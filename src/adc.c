#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "adc.h"


/* Simulation of ADC read
** 12 bit ADC resolve 4096 levels 
** Codes below 2048 represent a negative input voltage 
** Digital values above 2048 correspond to a positive input. */
unsigned int ADC_read()
{
	unsigned int ADC;

	if(ADC_BIT == 12)
	{
		ADC = (rand() % 4095);
	}

	if(ADC_BIT == 16)
	{
		ADC = (rand() % 65536);
	}

	return (ADC);
}

/* Convert ADC to volts
** Ideally 0 volts would be in middle of the range <0, 4095>
** For calibration purposes ->  offset error, gain error. 
** First, the gain error is corrected.
** And then We can compensate for offset by subtracting it from every ADC reading*/
signed int convertToVoltage(unsigned int adc_sample)
{
	if((adc_sample >= 0) && (adc_sample <= 4095))
	{
		return (adc_sample * ADC_GAIN_ERROR) * RESOLUTION_mV - ADC_OFFSET_ERROR_mV - ADC_OFFSET_BIPOLAR_ZERO_mV; // in mV   
	}
	else
	{
		return (NULL);
	}
}


/* User Requirements:
** Displayed range of -10v to +10v -> Checking if in range
** But with 12 bit ADC and 4mV resolution it is imposible to be out of range
** That's why we have in ADC_read example for 12 bit ADC but also for 16 bit*/
int checkIfVoltageInRange(signed int mV)	//return 1 if voltage is in range <-10, 10> else return 0
{
	if ((mV <= 10000) && (mV >= -10000))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}