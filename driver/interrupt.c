#include "interrupt.h"

#define EXTI_PIN_COUNT 16
static volatile ISR_Handler EXTI_Callback[EXTI_PIN_COUNT];
void INTERRUPT_Init(GPIO_Type GPIOx, GPIO_Pin pin,ISR_Handler ISR_Callback) {
		if (pin < EXTI_PIN_COUNT) {
			EXTI_Callback[pin]=ISR_Callback;
		}
    // Configure the GPIO pin as input with pull-down resistor
    GPIO_Init(GPIOx, pin, INPUT, INPUT_Pulldown);

    // Enable the clock for the AFIO (Alternate Function I/O) module
    RCC->RCC_APB2ENR.bit.AFIOEN |= 1;

    // Select GPIOA for EXTI11 in the EXTICR3 register of AFIO
		if (pin%4==0) AFIO->AFIO_EXTICR[pin/4].bit.EXT0 = GPIOx;
		if (pin%4==1) AFIO->AFIO_EXTICR[pin/4].bit.EXT1 = GPIOx;
		if (pin%4==2) AFIO->AFIO_EXTICR[pin/4].bit.EXT2 = GPIOx;
		if (pin%4==3) AFIO->AFIO_EXTICR[pin/4].bit.EXT3 = GPIOx;

    // Enable the interrupt request for EXTI11 in the Interrupt Mask Register (IMR)
    EXTI->EXTI_IMR.reg |= (1<<pin);

    // Configure the interrupt to be triggered on the rising edge for EXTI11
    EXTI->EXTI_RTSR.reg |= (1<<pin);

    // Enable the NVIC interrupt for EXTI
		if (pin==0) NVIC->NVIC_ISER[0].bit.SETENA6 = 1;
		if (pin==1) NVIC->NVIC_ISER[0].bit.SETENA7 = 1;
		if (pin==2) NVIC->NVIC_ISER[0].bit.SETENA8 = 1;
		if (pin==3) NVIC->NVIC_ISER[0].bit.SETENA9 = 1;
		if (pin==4) NVIC->NVIC_ISER[0].bit.SETENA10 = 1;
		if (pin>=5 && pin<=9) NVIC->NVIC_ISER[0].bit.SETENA23 = 1;
		if (pin>=10 && pin<=15) NVIC->NVIC_ISER[1].bit.SETENA8 = 1;
		
  
}
void EXTI15_10_IRQHandler(void) {

    for (int pin = 10; pin <= 15; pin++) {
        if (EXTI->EXTI_PR.reg & (1 << pin)) {  // Ki?m tra c? ng?t c?a chân pin
            EXTI_Callback[pin]();
            EXTI->EXTI_PR.reg |= (1 << pin);  // Xóa c? ng?t
        }
    }   
}
void EXTI9_5_IRQHandler(void) {
    for (int pin = 5; pin <= 9; pin++) {
        if (EXTI->EXTI_PR.reg & (1 << pin)) {  // Ki?m tra c? ng?t c?a chân pin
            EXTI_Callback[pin]();
            EXTI->EXTI_PR.reg |= (1 << pin);  // Xóa c? ng?t
        }
    }   
}
void EXTI4_IRQHandler(void) {
		EXTI_Callback[4]();
		EXTI->EXTI_PR.reg |= (1 << 4);    
}
void EXTI3_IRQHandler(void) {
		EXTI_Callback[3]();
		EXTI->EXTI_PR.reg |= (1 << 3);    
}
void EXTI2_IRQHandler(void) {
		EXTI_Callback[2]();
		EXTI->EXTI_PR.reg |= (1 << 2);    
}
void EXTI1_IRQHandler(void) {
		EXTI_Callback[1]();
		EXTI->EXTI_PR.reg |= (1 << 1);    
}
void EXTI0_IRQHandler(void) {
		EXTI_Callback[0]();
		EXTI->EXTI_PR.reg |= (1 << 0);    
}

