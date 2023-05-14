#ifndef __VOLTAGE
#define __VOLTAGE

//global variables
extern unsigned int ADC_samples_sum;

extern int numbersOfSamples;

void DMM_Update_Voltage(signed int adc_sample);

unsigned int mean(unsigned int ADC_sum, int number_of_samples);

#endif