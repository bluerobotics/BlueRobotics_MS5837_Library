#include "MS5837.h"
#include <Wire.h>

#define MS5837_ADDR               0x76

#define MS5837_RESET              0x1E
#define MS5837_ADC_READ           0x00
#define MS5837_PROM_READ          0xA0
#define MS5837_CONVERT_D1_8192    0x4A
#define MS5837_CONVERT_D2_8192    0x5A

MS5837::MS5837() {

}

void MS5837::init() {
	// Reset the MS5837, per datasheet
	Wire.beginTransmission(MS5837_ADDR);
	Wire.write(MS5837_RESET);
	Wire.endTransmission();

	// Wait for reset to complete
	delay(10);

	// Read calibration values and CRC
	for ( uint8_t i = 0 ; i < 8 ; i++ ) {
		Wire.beginTransmission(MS5837_ADDR);
		Wire.write(MS5837_PROM_READ+i*2);
		Wire.endTransmission();

		Wire.requestFrom(MS5837_ADDR,2);
		C[i] = (Wire.read() << 8) | Wire.read();
	}

	// Verify that data is correct with CRC
	uint8_t crcRead = C[0] >> 12;
	uint8_t crcCalculated = crc4(C);

	if ( crcCalculated == crcRead ) {
		// Success
	} else {
		// Failure - try again?
	}
}

void MS5837::read() {
	// Request D1 conversion
	Wire.beginTransmission(MS5837_ADDR);
	Wire.write(MS5837_CONVERT_D1_8192);
	Wire.endTransmission();

	delay(20); // Max conversion time per datasheet

	Wire.requestFrom(MS5837_ADDR,3);
	D1 = 0;
	D1 = (Wire.read() << 24) | (Wire.read() << 16) | Wire.read();

	// Request D2 conversion
	Wire.beginTransmission(MS5837_ADDR);
	Wire.write(MS5837_CONVERT_D2_8192);
	Wire.endTransmission();

	delay(20); // Max conversion time per datasheet

	Wire.requestFrom(MS5837_ADDR,2);
	D2 = 0;
	D2 = (Wire.read() << 24) | (Wire.read() << 16) | Wire.read();

	calculate();
}

void MS5837::readTestCase() {
	C[0] = 0;
	C[1] = 34982;
	C[2] = 36352;
	C[3] = 20328;
	C[4] = 22354;
	C[5] = 26646;
	C[6] = 26146;
	C[7] = 0;

	D1 = 4958179;
	D2 = 6815414;

	calculate();
}

void MS5837::calculate() {
	// Given C1-C6 and D1, D2, calculated TEMP and P
	// Do conversion first and then second order temp compensation

	
}

float MS5837::pressure(float conversion) {
	return P/100.0f*conversion;
}

float MS5837::temperature() {
	return TEMP/
}

uint8_t MS5837::crc4(uint16_t n_prom[]) {
	uint16_t n_rem = 0;

	n_prom[0] = ((n_prom[0]) & 0x0FFF);
	n_prom[7] = 0;

	for ( uint8_t i = 0 ; i < 16; i++ ) {
		if ( i%2 == 1 ) {
			n_rem ^= (uint16_t)((n_prom[i>>1]) & 0x00FF0);
		} else {
			n_rem ^= (uint16_t)(n_prom[i>>1] >> 8);
		}
		for ( uint8_t n_bit = 8 ; n_bit > 0 ; n_bit-- ) {
			if ( n_rem & 0x8000 ) {
				n_rem = (n_rem << 1) ^ 0x3000;
			} else {
				n_rem = (n_rem << 1);
			}
		}
	}
	
	n_rem = ((n_rem >> 12) & 0x000F);

	return n_rem ^ 0x00;
}