/**
  * MakerBotics Tutorial by VBG created on the 28/11/23
  * Module for reading & displaying the INA226 sensor output using a teensy 4.1
**/

#include <Wire.h>
#include "INA226.h"

INA226 INA(0x40);

// Initialising the INA226 sensor
void setup() {
  Serial.begin(9600);

  Wire.begin();
  if (!INA.begin()) { Serial.println("could not connect. Fix and Reboot"); }
  INA.setMaxCurrentShunt(1, 0.002);
}

// Polling & displaying the sensor readings every 2 seconds
void loop() {
  Serial.print("\nBus Voltage:");
  Serial.print(INA.getBusVoltage(), 3);

  Serial.print("\tShunt Voltage(mV): ");
  Serial.print(INA.getShuntVoltage_mV(), 3);

  Serial.print("\tCurrent(mA): ");
  Serial.print(INA.getCurrent_mA(), 3);

  Serial.print("\tPower(mW): ");
  Serial.print(INA.getPower_mW(), 3);
  delay(2000);
}
