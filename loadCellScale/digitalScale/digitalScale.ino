/*
  * MakerBotics Tutorial by VBG created on the 28/11/2023
  * Module for measuring weight & calculating the average weight using a 
  * HX711 load cell on a Teensy 4.1
*/

#include "HX711.h"

#define SCK 27
#define DT 26
#define CALIBRATION_FACTOR -228.4

HX711 scale;
// Scale weight reading counter
int count = 1;

/* Initialising the teensy & load cell */
void setup() {
  Serial.begin(9600);
  scale.begin(DT, SCK);
  // Calibration values
  scale.set_offset(4294799235);
  scale.set_scale(CALIBRATION_FACTOR);
  // Set the scale to 0
  scale.tare();
  Serial.println("Please place weight on scales");
}

/* Calculating & displaying the weight & average weight readings */
void loop() {
  // Reading scale input
  float weight = scale.get_units();

  // Checking for valid weight and updating the average
  if (weight > 1) {
    Serial.printf("reading %d: ", count++);
    Serial.println(scale.get_units(), 3);
    Serial.println("Please place another weight on scales");
  }
  delay(2000);
}
