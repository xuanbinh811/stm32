#include <stdint.h>
#include "stm32f103c8.h"
#include "gpio.h"
#include "button.h"
uint32_t a=0;
int status=0;
uint32_t *valcrh;
int main()
{
     RCC->RCC_APB2ENR.bit.IOPCEN=1;
     
     
    uint32_t addgpioc =0x40010800; //base add 
    uint32_t addGPIOC_CRH =addgpioc+4;
    valcrh=(uint32_t*)addGPIOC_CRH;
    a=*valcrh;
    *valcrh |= (0b01) << 20;
    *valcrh &= ~(0b111 << 21);
    a=*valcrh;
    GPIOA->GPIO_ODR.reg |= (1 << 13);
    while (1)
    {

    }
    
   
}

void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms * 1500; i++);
}