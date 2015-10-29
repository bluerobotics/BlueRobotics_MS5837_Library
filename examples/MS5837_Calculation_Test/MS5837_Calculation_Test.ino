

/* Blue Robotics MS5837 Library Calculation Test Code
-----------------------------------------------------
 
Title: Blue Robotics MS5837 Library Calculation Test Code

Description: This example is only used to test the conversion calculations
from the part datasheet. It does not actually communicate with the sensor.

The code is designed for the Arduino Uno board and can be compiled and 
uploaded via the Arduino 1.0+ software.

-------------------------------
The MIT License (MIT)

Copyright (c) 2015 Blue Robotics Inc.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-------------------------------*/

#include <Wire.h>
#include "MS5837.h"

MS5837 sensor;

void setup() {
  Serial.begin(57600);
  
  Wire.begin();
}

void loop() {
  sensor.readTestCase();

  Serial.print("Pressure: "); Serial.print(sensor.pressure()); Serial.print(" mbar");
  Serial.print("(Should be 3999.8 mbar before 2nd order corrections)"); Serial.println();
  Serial.print("Temperature: "); Serial.print(sensor.temperature()); Serial.print(" deg C");
  Serial.print("(Should be 19.81 deg C before 2nd order corrections)"); Serial.println();

  delay(10000);
}
