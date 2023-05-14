/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

#include "adc.h"
#include "main.h"
#include "displayDriver.h"
#include "voltage.h"


/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

//----------------------------FREE_RTOS------------------------------------
void vSampleADC(void *pvParameters);

void vRefreshDisplay(void *pvParameters);

int main(void)
{
    
    xTaskCreate(&vSampleADC, "Task 1", 1024, NULL, 1, NULL); 

    xTaskCreate(&vRefreshDisplay, "Task 2", 1024, NULL, 1, NULL);

    vTaskStartScheduler();

    return 0;
}

void vSampleADC(void *pvParameters)
{
    for (;;)
    {
        signed int ADC_sample = ADC_read();

        DMM_Update_Voltage(ADC_sample);

        vTaskDelay(pdMS_TO_TICKS(ADC_SAMPLE_ms));
    }
}

void vRefreshDisplay(void *pvParameters)
{
    for (;;)
    {
        //calculate mean
        unsigned int ADCmean = mean(ADC_samples_sum,numbersOfSamples);

        signed int mV = convertToVoltage(ADCmean);

        //checking if in range
        int is_overload = checkIfVoltageInRange(mV); 

        Display_Update_SetOverload(is_overload);
        
        //checking if negative or positive number?
        const char *trueMessage = "-";
        
        const char *falseMessage = " ";
	
	    const char *sign = ((mV < 0) ? trueMessage : falseMessage);

        #ifdef DEBUG
            printf("sign: %s\n", sign);
        #endif
        
        //finding Integer and decimal part of number
        float VOLTS = (float)mV/1000;

        #ifdef DEBUG
            printf("voltage: %f\n", VOLTS);
        #endif       

        int integer = (int)VOLTS;
   
        float fraction = (VOLTS - (float)integer) * 100;

        if(integer < 0)
        {
            integer=integer*(-1);
        }

        if(fraction < 0)
        {
            fraction=fraction*(-1);
        }

        #ifdef DEBUG
            printf("Integer part: %d, Decimal part: %.0f\n", integer, fraction);
        #endif      

        Display_Update_SetVoltage(sign, integer, fraction);

        vTaskDelay(pdMS_TO_TICKS(DISPLAY_UPDATE_ms));
    }
}
