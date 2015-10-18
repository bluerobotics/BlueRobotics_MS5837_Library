/* Blue Robotics Arduino I2C ESC Control Library
------------------------------------------------
 
Title: Arduino I2C ESC Library

Description: This library provide methods to control I2C capable ESCs
using the Blue Robotics fork of the tgy firmware. It's designed for the
"BlueESC" but will work with an tgy compatible ESC.

The code is designed for the Arduino boards and can be compiled and 
uploaded via the Arduino 1.0+ software.

Inspired by: https://github.com/balrog-kun/autopilot/blob/lpc1343/actuators-i2c.h

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

#ifndef MS5837_H_BLUEROBOTICS
#define MS5837_H_BLUEROBOTICS

#include "Arduino.h"

class MS5837 {
public:
	MS5837();

	void init();

private:

};

#endif
