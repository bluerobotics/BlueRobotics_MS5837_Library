# BlueRobotics MS5837 Library [![Build Status](https://travis-ci.org/bluerobotics/BlueRobotics_MS5837_Library.svg?branch=master)](https://travis-ci.org/bluerobotics/BlueRobotics_MS5837_Library)

Arduino library for the MS5837 pressure sensor. The MS5837 is a tiny SMT pressures sensor from Measurement Specialties that can measure pressure of up to 30 Bar (300m depth) with resolution of 0.2 mbar.

This library also supports the MS5837-02BA which has a much smaller measurement range and is better suited for altitude measurement in air.

# Documentation

Please see the examples for normal operation. Below are the available functions used in the library.

``` cpp
MS5837();

/** Must be called before attempting to operate the sensor.
 * Returns true if the sensor was initialized successfully.
 */
bool init();

/** Set model of MS5837 sensor. Valid options are MS5837::MS5837_30BA (default)
 * and MS5837::MS5837_02BA.
 */
void setModel(uint8_t model);

/** Provide the density of the working fluid in kg/m^3. Default is for 
 * seawater. Should be 997 for freshwater.
 */
void setFluidDensity(float density);

/** The read from I2C takes up for 40 ms, so use sparingly is possible.
 */
void read();

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
