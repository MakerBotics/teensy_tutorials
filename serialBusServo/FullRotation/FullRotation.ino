/*
  * MakerBotics Tutorial by VBG created on the 05/07/2024
  
  * Module for fully rotating a STS3020 servo using a teensy 4.0

  * Please note that the RX pin is connected to pin 7 & TX Pin is
  * connected to pin 8 to use Serial2.
*/
#include <SCServo.h>

/* Servo id */
#define STS3020 1

// The STS3020 servo
SMS_STS sms_sts;

void setup() {
  Serial.begin(9600);
  // STS servo's require a baud rate of 1000000
  Serial2.begin(1000000);
  sms_sts.pSerial = &Serial2;
  delay(1000);
}

// Continuous servo rotation
void loop() {
  /* The servo runs to the position P1 = 4095 at  maximum speed V=2400 
     steps/second, acceleration A=50 (50*100 steps/second^2) */
  sms_sts.WritePosEx(STS3020, 4095, 2400, 50);
  Serial.println("Rotating forwards to position 4095");
  // delaying for [(P1-P0)/V]*1000+[V/(A*100)]*1000
  delay(2240); 

  /* The servo returns to the position P0=0 at maximum speed V=2400 
     steps/second, acceleration A=50 (50*100 steps/second^2) */
  sms_sts.WritePosEx(STS3020, 0, 2400, 50);
  Serial.println("Rotating backwards to position 0");
  delay(2240);
}
