# BlueRobotics MS5837 Library [![Build Status](https://travis-ci.org/bluerobotics/BlueRobotics_MS5837_Library.svg?branch=master)](https://travis-ci.org/bluerobotics/BlueRobotics_MS5837_Library)

Arduino library for the MS5837 pressure sensor. The MS5837 is a tiny SMT pressures sensor from Measurement Specialties that can measure pressure of up to 30 Bar (300m depth) with resolution of 0.2 mbar.

# Documentation

Please see the examples for normal operation. Below are the available functions used in the library.

``` cpp
MS5837();

void init();

/** Provide the density of the working fluid in kg/m^3. Default is for 
 * seawater. Should be 997 for freshwater.
 */
void setFluidDensity(float density);

/** The read from I2C takes up for 40 ms, so use sparingly is possible.
 */
void read();

/** This function loads the datasheet test case values to verify that
 *  calculations are working correctly. No example checksum is provided
 *  so the checksum test may fail.
 */
void readTestCase();

/** Pressure returned in mbar or mbar*conversion rate.
 */
float pressure(float conversion = 1.0f);

/** Temperature returned in deg C.
 */
float temperature();

/** Depth returned in meters (valid for operation in incompressible
 *  liquids only. Uses density that is set for fresh or seawater.
 */
float depth();

/** Altitude returned in meters (valid for operation in air only).
 */
float altitude();

```

# Versions

1.0.0 - First release, included in Arduino Library Manager

# Reference

You can find the [MS5837-30BA datasheet here](http://www.mouser.com/ds/2/418/MS5837-30BA-736494.pdf).
