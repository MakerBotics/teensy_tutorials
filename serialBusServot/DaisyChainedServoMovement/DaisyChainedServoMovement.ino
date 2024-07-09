/*
  * MakerBotics Tutorial by VBG created on the 05/07/2024

  * Module for fully rotating 3 daisy chained servos
  * (STS3020, SCS225, SCS0009) independently using a teensy 4.0

  * Please note that the RX pin is connected to pin 7 & TX Pin is
  * connected to pin 8 to use Serial2.
*/
#include <SCServo.h>

/* Servo ids */
#define STS3020 1
#define SCS225 2
#define SCS0009 3

// The STS/SCS servo
SMS_STS sms_sts;

void setup() {
  Serial.begin(9600);
  // STS servo's require a baud rate of 1000000
  Serial2.begin(1000000);
  sms_sts.pSerial = &Serial2;
  delay(1000);
}

// Full rotation of the servo backwards & forwards
void rotate(int servoID) {
  /* The servo runs to the position P1 = 4095 at  maximum speed V=2400 
     steps/second, acceleration A=50 (50*100 steps/second^2) */
  sms_sts.WritePosEx(servoID, 4095, 2400, 50);
  Serial.printf("Rotating servo %d to position 4095", servoID);
  Serial.println();
  // delaying for [(P1-P0)/V]*1000+[V/(A*100)]*1000
  delay(2240); 
  
  /* The servo returns to the position P0=0 at maximum speed V=2400 
     steps/second, acceleration A=50 (50*100 steps/second^2) */
  sms_sts.WritePosEx(servoID, 0, 2400, 50);
  Serial.printf("Rotating servo %d to position 0", servoID);
  Serial.println();
  delay(2240);
}

// Continuously rotating all the servos
void loop() {
  rotate(STS3020);
  rotate(SCS225);
  rotate(SCS0009);
  delay(3000);
}
