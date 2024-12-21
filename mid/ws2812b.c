#include "stm32f103c8.h"
#include "gpio.h"
#define MAX_LED 32*8 // So luong LED
#define delay 250
uint16_t pwmData[(24 * MAX_LED) + delay];
volatile uint8_t datasentflag = 0;
volatile int k = 0;

void TIM1_Config(void);
void DMA_Config(void);
void WS2812_Config(int G, int R, int B);//update all leds
void timer1_enable(void);
void dma1_channe12_enable(void);
void Update_Led(int led_idx, int G, int R, int B);//update 1 led

int x = 1000;

void WS2812_Config(int G, int R, int B) {
    uint32_t indx = 0;
    uint32_t color;

    for (int i = 0; i < MAX_LED; i++) {
        color = ((G << 16) | (R << 8) | (B));
        for (int i = 23; i >= 0; i--) {
            if (color & (1 << i)) {
                pwmData[indx] = 18; // 2/3 cua 90
            } else {
                pwmData[indx] = 8; // 1/3 cua 90
            }
            indx++;
        }
    }

    for (int i = 0; i <	 delay; i++) {
        pwmData[indx] = 0;
        indx++;
    }
}

void Update_Led(int led_idx, int G, int R, int B) {
    uint32_t color;
    uint32_t start_index = led_idx * 24; // M?i LED s? d?ng 24 bit trong pwmData
    
    color = ((G << 16) | (R << 8) | (B)); // Ghép màu thành 24 bit

    for (int i = 23; i >= 0; i--) {
        if (color & (1 << i)) {
            pwmData[start_index] = 18; // Logic '1' - 2/3 c?a chu k?
        } else {
            pwmData[start_index] = 8; // Logic '0' - 1/3 c?a chu k?
        }
        start_index++; // Chuy?n sang bit ti?p theo
    }
}
void TIM1_Config(void) {
	
	// Enable clock for GPIOA
	//RCC->RCC_APB2ENR.bit.IOPAEN = 1;
	
	// test ngat
	//GPIOA->CRH |= 0x03<<8;
	//GPIOA->CRH &= ~(0x03<<10);

	
	// PA8: alternate output push/pull
	//GPIOA->CRH |= 0x03;
	//GPIOA->CRH |= 0x01<<3;
	//GPIOA->CRH &= ~(0x01<<2);
	GPIO_Init(GPIO_A,Pin1,OUTPUT_50MHZ,OUTPUT_AFPushpull);
	//AFIO->MAPR &= ~AFIO_MAPR_TIM1_REMAP; // not remap the pin
	// Enable clock for TIM1
	RCC->RCC_APB2ENR.reg |= 0x01<<11;
	
	//Config Output compare 1 mode
	TIM1->CCMR1 |= 0x03<<5;            // OC1M = 110
	TIM1->CCMR1 &= ~(0x01<<4);				 // OC1M = 110
	TIM1->CCMR1 &= ~(0x03);						// CC1A = 00
	TIM1->BDTR |= 0x01<<10;						// OSSI: Off-state selection for Idle mode
	TIM1->BDTR |= 0x01<<11;           // OSSR: Off-state selection for Run mode
TIM1->CCER |= 0x01<<0;            // CC1E
	//TIM1->CCER |= 0x01<<2; 						// CC1NE

	// TIM1->CCR1 = 320; // duty cycle;
	TIM1->CR2 = 0;
	TIM1->SMCR = 0;
	TIM1->DIER = 0;
	
	//TIM1->CCR1 = 10; 
	// Cau hình prescaler và ARR de dat tan so ~800kHz
    //TIM1->PSC = 0;            // No prescaler
		TIM1->DIER |= 0x01; // update interrupt enable
		TIM1->DIER |= TIM_DIER_CC1DE;
		
    TIM1->ARR = 29;       // Tan s0 800kHz (1.25µs moi chu ky) 	
		
		
		TIM1->EGR |= 0x01;        // UG enable
	
		TIM1->BDTR |= 0x01<<15; 					// MOE: Main output enable

		TIM1->DIER |= 0x01<<14; // TDE: Trigger DMA request enable
		TIM1->DIER |= 0x01<<6; // 1: Trigger interrupt enabled
		TIM1->DIER |= 0x01<<8; // update dma request enable
		TIM1->DIER |= 0x01; // 1: Update interrupt enabled
		

// Bat auto reload
		//TIM1->CR1 |= 0x01<<7;
   
}
void timer1_enable(void){
	// Kích hoat bo dinh thoi
		TIM1->CR1 |= 0x01<<7;
		TIM1->CR1 |= 0x01<<2;
    TIM1->CR1 |= 0x01;
}
void DMA_Config(void) {
    // Bat xung cho DMA1
    RCC->RCC_AHBENR |= RCC_AHBENR_DMA1EN;
			
		//DMA1_Channel2->CCR |= 0x01<<9; //32 bits data
		//DMA1_Channel2->CCR |= 0x01<<11; // 32 bits data
	
		DMA1_Channel5->CPAR = (uint32_t)(&TIM1->CCR1);
		DMA1_Channel5->CMAR = (uint32_t)pwmData;
		DMA1_Channel5->CNDTR = 24*MAX_LED + delay;

	//cho phep ngat sau khi truyen xong
}    
void dma1_channe12_enable(void){
		DMA1_Channel5->CCR |= 0x03<<12;  // highest priority
		DMA1_Channel5->CCR |= 0x01<<4;   //Read from memory	
    //DMA1_Channel5->CCR |= 0x01<<5; // Circular Mode
		DMA1_Channel5->CCR |= 0x01<<7; //Memory increment mode enabled
	  DMA1_Channel5->CCR |= 0x01<<10;
	  DMA1_Channel5->CCR |= 0x01<<8;
	  DMA1_Channel5->CCR |= 0x01<<1; // B?t ng?t Transfer Complete
  //  NVIC_EnableIRQ(DMA1_Channel5_IRQn); // Kích ho?t ng?t DMA trong NVIC
		uint8_t irqNumber = 15; // IRQ số 15
    uint8_t registerIndex = irqNumber / 32; // Chỉ số thanh ghi (ở đây là 0 vì IRQ < 32)
    uint8_t bitPosition = irqNumber % 32;   // Vị trí bit trong thanh ghi

    NVIC->NVIC_ISER[registerIndex].reg = (1 << bitPosition); // Bật bit tương ứng
		DMA1_Channel5->CCR |= 0x01;
}

void DMA1_Channel5_IRQHandler(void) {
    if (DMA1->ISR & ((uint32_t)0x00020000)) {
			GPIOA->GPIO_ODR.reg |= (0x01 << 10);
        DMA1->IFCR |= 0x01<<17; // Xóa co ngat hoàn thành truyen
        datasentflag = 1;
    }
}