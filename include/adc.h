#ifndef __ADC
#define __ADC

#define 	ADC_OFFSET_ERROR_mV		        120

#define 	ADC_GAIN_ERROR		            1.02

#define 	ADC_OFFSET_BIPOLAR_ZERO_mV	    8192

#define 	RESOLUTION_mV	                4

#define 	ADC_BIT	                        12

unsigned int ADC_read();

signed int convertToVoltage(unsigned int adc_sample);

int checkIfVoltageInRange(signed int mV);

#endif