#ifndef __ADC_H__
#define __ADC_H__
#include "stm32f103c8.h"
#include "gpio.h"
void ADC_Init();
uint32_t read_ADC(uint8_t channel);
void ADC_ReadMulti(uint16_t *data) ;

#endif //__ADC_H__