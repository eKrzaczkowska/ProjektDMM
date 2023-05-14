#include <stdlib.h>
#include <stdio.h>
#include "displayDriver.h"

void Display_Update_SetOverload(int is_true)
{
    const char *trueMessage = "TRUE";
        
    const char *falseMessage = "FALSE";
	
	const char *is_overload = ((is_true == 0) ? trueMessage : falseMessage);

    printf("OVERLOAD: %s  \n", is_overload);
}

void Display_Update_SetVoltage(const char *sign,  int integer,  float  fraction)
{
    printf("DMM DISPLAY: %s %d.%.0f\n", sign, integer, fraction);
}