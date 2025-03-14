#include <SoftwareSerial.h>
#include "EBYTE.h"

#define PIN_RX 2
#define PIN_TX 3
#define PIN_M0 4
#define PIN_M1 5
#define PIN_AX 6

struct DATA {
  unsigned long Count;
  int Bits;
  float Volts;
  float Amps;
  
};

int Chan;
DATA MyData;
unsigned long Last;

const int MAX_SIGNAL_TIME = 1000;
const int MIN_SIGNAL_STRENGTH = 0;
const int MAX_SIGNAL_STRENGTH = 100;

const int BEEPER_PIN = 7;
const int MAX_BEEP_DURATION = 1000;
const int MIN_BEEP_DURATION = 100;

SoftwareSerial ESerial(PIN_RX, PIN_TX);
EBYTE Transceiver(&ESerial, PIN_M0, PIN_M1, PIN_AX);

void setup() {
  Serial.begin(9600);
  ESerial.begin(9600);
  Serial.println("Starting Reader");

Transceiver.Reset();
  Transceiver.init();

  Transceiver.SetUARTBaudRate(3);
  Transceiver.SetParityBit(0);
  Transceiver.SetAirDataRate(0);
  Transceiver.SetTransmitPower(0);
  Transceiver.SetFECMode(0);
  Transceiver.SetWORTIming(0);
  Transceiver.SetChannel(15);
  Transceiver.SetPullupMode(1);
   Transceiver.SetSpeed(0b00011010);  
  Transceiver.SetChannel(15);
  Transceiver.SetOptions(0b01000100);


  Transceiver.SaveParameters(PERMANENT);

  pinMode(BEEPER_PIN, OUTPUT);
}

void loop() {
  unsigned long startMillis = millis();

  if (ESerial.available()) {
    Transceiver.GetStruct(&MyData, sizeof(MyData));
    unsigned long captureTime = millis() - startMillis;
    int signalStrength = map(captureTime, 0, 5000, 0, 100);

    Serial.print("Capture Time: ");
    Serial.print(captureTime);
    Serial.print(" ms, Signal Strength: ");
    Serial.println(signalStrength);

    Last = millis();

    // Make the heartbeat-like beep based on signal strength
    int beepDuration = map(signalStrength, 0, 100, MAX_BEEP_DURATION, MIN_BEEP_DURATION);
    int pauseDuration = MAX_BEEP_DURATION - beepDuration;
    makeHeartbeat(beepDuration, pauseDuration);
  } else {
    if ((millis() - Last) > 1000) {
      Serial.println("Searching: ");
      Last = millis();

      // Turn off the beeper
      digitalWrite(BEEPER_PIN, LOW);
    }
  }
}

void makeHeartbeat(int beepDuration, int pauseDuration) {
  unsigned long startMillis = millis();
  while (millis() - startMillis < beepDuration) {
    digitalWrite(BEEPER_PIN, HIGH);
    delay(100);
    digitalWrite(BEEPER_PIN, LOW);
    delay(100);
  }
  delay(pauseDuration);
}


