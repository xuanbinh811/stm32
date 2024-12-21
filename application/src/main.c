#include <stdint.h>
#include "stm32f103c8.h"
#include "gpio.h"
#include "button.h"
#include "interrupt.h"
#include "RCC.h"
#include "i2c.h"
#include "systick.h"
#include "rcc_ds3231.h"
static volatile uint32_t a=0;
static volatile uint32_t b=0;
Time_t time;
Time_t time_update;
uint8_t regAddr = 0x0; // Starting register for date
uint8_t data[10];
void delay_ms(uint32_t ms) {
    volatile uint32_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 4000; j++) {
            __asm("NOP"); // Lệnh NOP để tránh tối ưu hóa
        }
    }
}
void INTERRUPT_B15(){
	delay(1000);
	b++;
}
void INTERRUPT_A11(){
	delay(1000);
	a++;
}
int main()
 {
		time_update.second=10;
	  time_update.minute=15;
	  time_update.hour=1;
		time.second = data[0];
		time.minute = data[1];
		time.hour = data[2];
		time.date = data[3];
	 //SysTick_Init();
	 DS3231_Init(I2C1);
	 //DS3231_SetTime(I2C1,&time_update);

	//(void)a;
	//INTERRUPT_Init(GPIO_B,Pin15,INTERRUPT_B15);
	//INTERRUPT_Init(GPIO_A,Pin7,INTERRUPT_A11);
	while (1)
	{
			DS3231_GetTime(I2C1, &time);
			delay_ms(100);
		
	}
}
