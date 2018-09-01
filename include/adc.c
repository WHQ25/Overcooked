//
// Created by Hangqi Wu on 2018/8/30.
//

#include "adc.h"

void ADC_init()
{
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) | (1 << ADATE);
}

/**
 * Read ADC from chanel
 * @param ch: 0~7
 * @return ADC
 */
uint16_t ADC_read(uint8_t ch)
{
    ch = ch & 0b00000111;
    ADMUX = ( 1 << REFS0); // Enable AVCC
    ADMUX |= ch;
    ADCSRA |= (1 << ADSC); //Start Single conversion
    while(!(ADCSRA & (1<<ADIF))); //Wait for conversion to complete
    //Clear ADIF by writing one to it
    //Note you may be wondering why we have write one to clear it
    //This is standard way of clearing bits in io as said in datasheets.
    //The code writes '1' but it result in setting bit to '0' !!!
    ADCSRA |= (1 << ADIF);
    return ADC;
}

