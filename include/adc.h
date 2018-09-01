//
// Created by Hangqi Wu on 2018/8/30.
//

#ifndef TEST_ADC_H
#define TEST_ADC_H

#include <avr/io.h>
#include <stdint.h>

void ADC_init();

/**
 * Read ADC from chanel
 * @param ch: 0~7
 * @return ADC
 */
uint16_t ADC_read(uint8_t ch);


#endif //TEST_ADC_H
