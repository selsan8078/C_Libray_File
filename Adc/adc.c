#include "adc.h"
#include <xc.h>
#define _XTAL_FREQ  16000000

void adc_init()
{
    TRISA0 = 1;             //RA0=input       
//   
              //SELECT ADC
    
    ADCON1 = 0X8E;          //SELECT ADC
    ADCON0 = 0X81;          // 
    
    
}

int adc_read()
{
    int value = 0;
    ADCON0 |=(1<<2);
    while(ADCON0 &(1<<2));  // START checking 1st bit if high
    value =(ADRESH<<8)|(ADRESL);
   
    return value;
}