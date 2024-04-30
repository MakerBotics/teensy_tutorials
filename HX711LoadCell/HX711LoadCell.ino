/**
 
  * Created by Maker Store 28/11/2023
  
  * Module for measuring weight & calculating the average weight using a 
  * HX711 load cell on a Teensy 4.1

**/

#include "HX711.h"


#define SCK 27
#define DT 26


HX711 scale;
int count = 1;


void setup() {
  Serial.begin(9600);
  scale.begin(DT, SCK);
  // Calibration values
  scale.set_offset(4294799235);
  scale.set_scale(497.786407);
  scale.tare();
  Serial.println("Please place weight on scales");
}


void loop() {
  // Checking the scale's weight
  float weight = scale.get_units();


  // Checking for valid weight and updating the average
  if (weight > 1) {
    Serial.printf("reading %d: ", count++);
    Serial.print(scale.get_units(), 1);
    Serial.print("\t| average: ");
    Serial.println(scale.get_units(10), 5);
    Serial.println("Please place another weight on scales");
  }
  delay(2000);
}
