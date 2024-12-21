#ifndef __RCC_H__
#define __RCC_H__
#include "stm32f103c8.h"
// Function to get the current system clock frequency (SYSCLK)
uint32_t Get_SystemClock(void);
// Function to get the HCLK (AHB clock)
uint32_t Get_HCLK(void);
// Function to get the PCLK1 (APB1 clock)
uint32_t Get_PCLK1(void);
// Function to get the PCLK2 (APB2 clock)
uint32_t Get_PCLK2(void);
uint32_t Get_APB1_Clock(void);
#endif
