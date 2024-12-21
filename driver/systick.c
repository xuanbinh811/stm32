#include "systick.h" // Include the header file for SysTick functions and configurations
// Function to initialize SysTick timer
void SysTick_Init(void) {
		uint32_t hclk = Get_HCLK();
    uint32_t ticks_per_ms = hclk / 1000; // S? chu k? trong 1ms
    
    SysTick->LOAD = ticks_per_ms - 1;      // Set the reload value (ticks - 1, since counting starts from 0)
    SysTick->VAL = 0;                  // Clear the current value register
    SysTick->CTRL = SysTick_CTRL_ENABLE |  // Enable SysTick
                    SysTick_CTRL_TICKINT | // Enable SysTick interrupt
                    SysTick_CTRL_CLKSOURCE; // Use processor clock as the source
}

// SysTick interrupt handler
void SysTick_Handler(void) {
    sysTickCounter2++;  // Increment the millisecond counter on every interrupt
}

// Function to return the number of milliseconds elapsed since the SysTick timer started
uint64_t millis(void) {
    return sysTickCounter2 ; // Return the millisecond counter value
}

// Function to implement a delay in milliseconds
void delay(uint64_t delay) {
    uint64_t start = millis(); // Record the start time
    while ((millis() - start) < delay); // Wait until the specified delay has passed
}
