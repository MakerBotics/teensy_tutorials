/**
  * Created by Maker Store 28/11/2023

  * Module for reading the RGB values from a TCS34725 colour sensor and 
  * indicating the colour using a Teensy 4.1

**/

#include "Adafruit_TCS34725.h"
#include <Wire.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);

  // Initiating the sensor
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
}

// Continuously measuring the RGB values every 2 seconds
void loop() {
  float red, green, blue;
  
  // Reading RGB sensor values, takes 50ms to read
  tcs.setInterrupt(false);  
  delay(60);  
  tcs.getRGB(&red, &green, &blue);
  tcs.setInterrupt(true); 
 
  // Printing RGB values
  Serial.print("R: "); Serial.print(int(red)); 
  Serial.print("\tG: "); Serial.print(int(green)); 
  Serial.print("\tB: "); Serial.print(int(blue));
  Serial.print(" ==> ");

  // Determining the predominant colour
  if ( red > blue && red > green) {
    Serial.print("Red!");
  } else if ( blue > red && blue > green) {
    Serial.print("Blue!");
  } else if ( green > red && green > blue) {
    Serial.print("Green!");
  }
  Serial.print("\n");

  delay(2000);
}
