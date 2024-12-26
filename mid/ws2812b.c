#include "ws2812b.h"

// Định nghĩa biến toàn cục
uint16_t pwmData[(24 * MAX_LED) + DELAY];
volatile uint8_t datasentflag = 0;
volatile int k = 0;
dongho_index dongho_index_1;
dongho_index dongho_index_2;
dongho_index dongho_index_3;
dongho_index dongho_index_4;

uint8_t so1_0[32] = {9,10,11,12,13,14,17,18,19,20,21,22,24,25,30,31,32,33,38,39,41,42,43,44,45,46,49,50,51,52,53,54};
uint8_t so1_1[19] = {29,33,34,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55};
uint8_t so1_2[28] = {24,25,26,27,28,30,31,32,33,35,36,37,38,39,40,41,43,44,45,46,47,48,49,50,51,52,54,55};	
uint8_t so1_3[28] = {24,25,27,28,30,31,32,33,35,36,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55};	
uint8_t so1_4[28] = {16,17,18,19,20,27,28,29,30,31,35,36,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55};	
uint8_t so1_5[32] = {24,25,27,28,29,30,31,32,33,34,35,36,38,39,40,41,42,43,44,46,47,48,49,51,52,53,54,55};	
uint8_t so1_6[36] = {16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,35,36,38,39,40,41,42,43,44,46,47,48,49,51
	                   ,52,53,54,55};	
uint8_t so1_7[32] = {30,31,32,33,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55};	
	
uint8_t so1_9[42] = {8,9,11,12,13,14,15,16,17,18,19,20,22,23,24,25,27,28,30,31,32,33,35,36,38,39,40,41,42,43,44,
                     45,46,47,48,49,50,51,52,53,54,55};	
// Hàm WS2812_Config
void WS2812_Config(int G, int R, int B) {
    uint32_t indx = 0;
    uint32_t color;

    for (int i = 0; i < MAX_LED; i++) {
        color = ((G << 16) | (R << 8) | (B));
        for (int i = 23; i >= 0; i--) {
            if (color & (1 << i)) {
                pwmData[indx] = 60; // 2/3 cua 90
            } else {
                pwmData[indx] = 30; // 1/3 cua 90
            }
            indx++;
        }
    }
	for (int i = 0; i <	 DELAY; i++) {
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
            pwmData[start_index] = 60; // Logic '1' - 2/3 c?a chu k?
        } else {
            pwmData[start_index] = 30; // Logic '0' - 1/3 c?a chu k?
        }
        start_index++; // Chuy?n sang bit ti?p theo
    }
}
void TIM1_Config(void) {
	
	// Enable clock for GPIOA
	RCC->RCC_APB2ENR.reg |= 0x01<<2;
	
	// test ngat
	GPIOA->GPIO_CRH.reg |= 0x03<<8;
	GPIOA->GPIO_CRH.reg &= ~(0x03<<10);

	
	// PB8: alternate output push/pull
	GPIOA->GPIO_CRH.reg |= 0x03;
	GPIOA->GPIO_CRH.reg |= 0x01<<3;
	GPIOA->GPIO_CRH.reg &= ~(0x01<<2);
	
	AFIO->MAPR &= ~((uint32_t)0x000000C0) ; // not remap the pin
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
		
    TIM1->ARR = 90;       // Tan s0 800kHz (1.25µs moi chu ky) 	
		
		
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
		RCC->RCC_APB2ENR.reg |= RCC_AHBENR_DMA1EN;
			
		//DMA1_Channel2->CCR |= 0x01<<9; //32 bits data
		//DMA1_Channel2->CCR |= 0x01<<11; // 32 bits data
	
		DMA1_Channel5->CPAR = (uint32_t)(&TIM1->CCR1);
		DMA1_Channel5->CMAR = (uint32_t)pwmData;
		DMA1_Channel5->CNDTR = 24*MAX_LED + DELAY;

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
    uint32_t irq_num = 17; // DMA1_Channel5_IRQn có giá trị là 17
    uint32_t reg_index = irq_num / 32; // Chọn ISER tương ứng
    uint32_t bit_pos = irq_num % 32; // Vị trí bit trong thanh ghi ISER

    // Kích hoạt ngắt bằng cách ghi vào ISER
    NVIC->NVIC_ISER[reg_index].reg = (1U << bit_pos); // Kích ho?t ng?t DMA trong NVIC
		DMA1_Channel5->CCR |= 0x01;
}

void DMA1_Channel5_IRQHandler(void) {
    if (DMA1->ISR & ((uint32_t)0x00020000)) {
			GPIOA->GPIO_ODR.reg |= (0x01 << 10);
        DMA1->IFCR |= 0x01<<17; // Xóa co ngat hoàn thành truyen
        datasentflag = 1;
    }
}
void Update_Multiple_Leds(uint8_t	leds[], int led_count, int G, int R, int B) {
    for (int i = 0; i < led_count; i++) {
        Update_Led(leds[i], G, R, B);
    }
}