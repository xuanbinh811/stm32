#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__
#include "stm32f103c8.h"
#include "gpio.h"
typedef void (*ISR_Handler)(void);
void INTERRUPT_Init(GPIO_Type GPIOx, GPIO_Pin pin,ISR_Handler ISR_Callback);



#endif 
