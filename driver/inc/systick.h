#ifndef __SYSTICK_H__  
#define __SYSTICK_H__  

#include "stm32f103c8.h"  // Include the STM32F103C8-specific header for register definitions
#include "RCC.h"           // Include the RCC (Reset and Clock Control) header for clock settings

// Volatile variable to hold the system tick count (in milliseconds)


// Function prototypes for SysTick initialization, millis, and delay
void SysTick_Init(void);          // Initialize SysTick timer
uint64_t millis(void);            // Get the current system tick count in milliseconds
void delay_ms(uint64_t delay);  // Delay for a specified number of milliseconds

#endif  // __SYSTICK_H__
