#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

#include "voltage.h"

unsigned int ADC_samples_sum = 0;

int numbersOfSamples = 0;

/* DMM_Update_Voltage
** Summing adc_samples and counting them*/ 
void DMM_Update_Voltage(signed int adc_sample)
{ 
    ADC_samples_sum+=adc_sample;

    numbersOfSamples++;
}

//calculate sample mean -> int because we don't need that precision, we only display  two decimal places.
unsigned int mean(unsigned int ADC_sum, int number_of_samples)
{
    if(number_of_samples == 0)
    {
        return 0;
    }
    else
    {
        ADC_samples_sum = 0;

        #ifdef DEBUG
                printf("number of samples: %i\n", number_of_samples);
        #endif

        numbersOfSamples = 0;

        #ifdef DEBUG
                printf("mean: %i\n", ADC_sum / number_of_samples);
        #endif

        return (ADC_sum / number_of_samples);
    }
}
