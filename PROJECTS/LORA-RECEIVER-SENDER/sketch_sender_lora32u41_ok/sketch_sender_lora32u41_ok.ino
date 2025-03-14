//#include <SPI.h>
#include <RH_RF95.h>

#define RFM95_CS 8
#define RFM95_RST 4
#define RFM95_INT 7

RH_RF95 rf95(RFM95_CS, RFM95_INT);
//RH_RF95 rf95;
int number = 42;

void setup() {
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);
  

  //Serial.begin(9600);
  //while (!Serial);

  if (!rf95.init()) {
    //Serial.println("LoRa module initialization failed. Check wiring and configuration.");
    while (1);
  }

  rf95.setFrequency(433.0); // Set the frequency (must match the receiver's frequency)

  //Serial.println("LoRa sender initialized.");
}

void loop() {
  //int number = 42; // Replace with your desired number
  
  //Serial.print("Sending number: ");
  //Serial.println(number);

  rf95.send((uint8_t*)&number, sizeof(number));
  rf95.waitPacketSent();
  
  delay(5000);
  if(number == 50){
    number = 42;
  }else{
    number = number + 1;
  }
  
}
