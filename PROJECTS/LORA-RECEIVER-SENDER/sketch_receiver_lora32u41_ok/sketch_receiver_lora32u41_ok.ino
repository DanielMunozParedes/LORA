//#include <SPI.h>
#include <RH_RF95.h>

#define RFM95_CS 8
#define RFM95_RST 4
#define RFM95_INT 7

/*
we using pins 8,4,7 because are the correct for RFM module data trasmission for Lora
*/

RH_RF95 rf95(RFM95_CS, RFM95_INT);
/*
the RFM95_CS is used for enabling communication, RFM95_RST is used for resetting the module
 RFM95_INT allows the LoRa module to send notifications to the microcontroller, informing it of important events that require attention.
*/


const int ledPin = LED_BUILTIN;


void setup() {
  pinMode(ledPin, OUTPUT);

  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);
  /*
  we using RFM95_RST module here isntead on the contructor basiclly for practical reasons, is easier to manipulate this module
  isntead of sending to the constructor of rf95 because it might change
  */
  //Serial.begin(9600);
  //while (!Serial);

  /*
  serial is a ashyncronous comunnication, waiting to the other device "talks", to now "talk"
  we using 9600 because is a realtivity and msot used bits per second speed between devices, we can user a higher or lower
  */

  if (!rf95.init()) {
    Serial.println("LoRa module initialization failed. Check wiring and configuration.");
    while (1);
  }

  rf95.setFrequency(433.0); // Set the frequency (must match the sender's frequency)

  //Serial.println("LoRa receiver initialized.");
}

void loop() {
  if (rf95.available()) {
    int number = 0;
    uint8_t len = sizeof(number);

    if (rf95.recv((uint8_t*)&number, &len)) {
      if (number % 2 == 0){
        //Serial.print("Received number: ");
        //Serial.println(number);
        digitalWrite(ledPin, HIGH);
        //delay(2000); // Wait for 1 second
  
        // Turn off the LED
        //digitalWrite(ledPin, LOW);
        //delay(2000); // Wait for 1 second

      }else{
        digitalWrite(ledPin, LOW);
        //delay(2000); // Wait for 1 second

      }



    }
  }
}
