#include "stm32f103c8.h"
#include "rcc_ds3231.h"
#include "adc.h"
#define MAX_LED 32*8 // So luong LED
#define delay 50
uint16_t pwmData[(24 * MAX_LED) + delay];
volatile uint8_t datasentflag = 0;
volatile int k = 0;
uint32_t blue=5;
uint32_t green=5;
uint32_t red=5;
Time_t time;
Time_t time_update;
uint8_t regAddr = 0x0; // Starting register for date
uint8_t data[10];
void TIM1_Config(void);
void DMA_Config(void);
void WS2812_Config(int G, int R, int B);
void timer1_enable(void);
void dma1_channe15_enable(void);
void Update_Led(int led_idx, int G, int R, int B);
void Update_Multiple_Leds(uint8_t leds[], int led_count, int G, int R, int B);
void Update_Time_Hour(uint8_t hour);
void Update_Time_Min(uint8_t min);
void Update_Data(uint8_t hour, uint8_t min);
void Start_Transmit(void);
void delay_ms1(uint32_t ms) {
    for (uint32_t i = 0; i < ms; i++) {
        for (volatile uint32_t j = 0; j < 8000; j++) {
            // Vòng lặp trống để tạo độ trễ
        }
    }
}

int x = 1;
typedef struct{
	uint8_t so0[50];
	uint8_t so1[50];
	uint8_t so2[50];
	uint8_t so3[50];
	uint8_t so4[50];
	uint8_t so5[50];
	uint8_t so6[50];
	uint8_t so7[50];
	uint8_t so8[50];
	uint8_t so9[50];
}dongho_index;

dongho_index dongho_index_1;
dongho_index dongho_index_2;
dongho_index dongho_index_3;
dongho_index dongho_index_4;


uint8_t so1_0[32] = {9,10,11,12,13,14,17,18,19,20,21,22,24,25,30,31,32,33,38,39,41,42,43,44,45,46,49,50,51,52,53,54};
uint8_t so1_1[19] = {29,33,34,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55};
uint8_t so1_2[28] = {24,25,26,27,28,30,31,32,33,35,36,37,38,39,40,41,43,44,45,46,47,48,49,50,51,52,54,55};	
uint8_t so1_3[28] = {24,25,27,28,30,31,32,33,35,36,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55};	
uint8_t so1_4[28] = {16,17,18,19,20,27,28,29,30,31,35,36,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55};	
uint8_t so1_5[28] = {24,25,27,28,29,30,31,32,33,34,35,36,38,39,40,41,42,43,44,46,47,48,49,51,52,53,54,55};	
uint8_t so1_6[36] = {16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,35,36,38,39,40,41,42,43,44,46,47,48,49,51
	                   ,52,53,54,55};	
uint8_t so1_7[20] = {30,31,32,33,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55};	
uint8_t so1_8[44] = {8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,27,28,30,31,32,33,35,36,38,39,40,41,42,
                     43,44,45,46,47,48,49,50,51,52,53,54,55};	
uint8_t so1_9[42] = {8,9,11,12,13,14,15,16,17,18,19,20,22,23,24,25,27,28,30,31,32,33,35,36,38,39,40,41,42,43,44,
                     45,46,47,48,49,50,51,52,53,54,55};		

										 
uint8_t so2_0[32] = {65,66,67,68,69,70,73,74,75,76,77,78,80,81,86,87,88,89,94,95,97,98,99,100,101,102,105,106,107,108,109,110};
uint8_t so2_1[19] = {82,93,94,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111};
uint8_t so2_2[28] = {80,81,83,84,85,86,87,88,89,90,91,92,94,95,96,97,98,99,100,102,103,104,105,107,108,109,110,111};
uint8_t so2_3[28] = {80,81,83,84,86,87,88,89,91,92,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111};
uint8_t so2_4[28] = {75,76,77,78,79,80,81,82,83,84,91,92,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111};
uint8_t so2_5[28] = {80,81,82,83,84,86,87,88,89,91,92,93,94,95,96,97,99,100,101,102,103,104,105,106,107,108,110,111};
uint8_t so2_6[36] = {72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,91,92,94,95,96,97,99,100,101,102,103,104,
										105,106,107,108,110,111};
uint8_t so2_7[20] = {80,81,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111};
uint8_t so2_8[44] = {64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,83,84,86,87,88,89,91,92,94,95,96,97,98,99,
										 100,101,102,103,104,105,106,107,108,109,110,111};
uint8_t so2_9[42] = {64,65,66,67,68,70,71,72,73,75,76,77,78,79,80,81,83,84,86,87,88,89,91,92,94,95,96,97,98,99,100,
                     101,102,103,104,105,106,107,108,109,110,111};

										 
uint8_t so3_0[32] = {145,146,147,148,149,150,153,154,155,156,157,158,160,161,166,167,168,169,174,175,	
										 177,178,179,180,181,182,185,186,187,188,189,190};
uint8_t so3_1[19] = {146,157,158,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175};
uint8_t so3_2[28] = {144,145,147,148,149,150,151,152,153,154,155,156,158,159,160,161,162,163,164,166,167,168,169,
										171,172,173,174,175};
uint8_t so3_3[28] = {144,145,147,148,150,151,152,153,155,156,158,159,160,161,162,163,164,165,166,167,168,169,170,
	                  171,172,173,174,175};
uint8_t so3_4[28] = {144,145,146,147,148,155,156,157,158,159,163,164,168,169,170,171,172,
                     173,174,175,176,177,178,179,180,181,182,183};
uint8_t so3_5[28] = {144,145,146,147,148,150,151,152,153,155,156,157,158,159,160,161,163,164,165,166,167,168,169,170,
                     171,172,174,175};
uint8_t so3_6[36] = {144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,163,164,166,167,168,169,
                     170,171,172,174,175,176,177,179,180,181,182,183};
uint8_t so3_7[20] = {144,145,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175};
uint8_t so3_8[44] = {144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,163,164,
										166,167,168,169,171,172,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191};
uint8_t so3_9[42] = {144,145,146,147,148,150,151,152,153,155,156,157,158,159,160,161,163,164,166,167,168,169,171,172,
                     174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191};

uint8_t so4_0[32] = {201,202,203,204,205,206,209,210,211,212,213,214,216,217,222,223,224,225,230,231,233,234,235,236,
											237,238,241,242,243,244,245,246};
uint8_t so4_1[19] = {205,209,210,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231};
uint8_t so4_2[28] = {200,201,202,203,204,206,207,208,209,211,212,213,214,215,216,217,219,220,221,222,223,224,225,226,227,
											228,230,231};
uint8_t so4_3[28] = {200,201,203,204,206,207,208,209,211,212,214,215,216,217,218,219,220,221,222,223,224,225,226,227,
											228,229,230,231};
uint8_t so4_4[28] = {203,204,205,206,207,208,209,210,211,212,219,220,224,225,226,227,228,229,230,231,232,233,234,235,236,
											237,238,239};
uint8_t so4_5[28] = {200,201,203,204,205,206,207,208,209,210,211,212,214,215,216,217,218,219,220,222,223,224,225,227,
											228,229,230,231};
uint8_t so4_6[36] = {200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,219,220,222,223,224,225,
											227,228,229,230,231,232,233,234,235,236,238,239};
uint8_t so4_7[20] = {206,207,208,209,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231};
uint8_t so4_8[44] = {200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,219,220,222,223,224,225,227,
										 228,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247};
uint8_t so4_9[42] = {200,201,203,204,205,206,207,208,209,210,211,212,214,215,216,217,219,220,222,223,224,225,227,228,
										 230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247};	
const uint8_t dau_hai_cham[8] = {121, 122, 125, 126, 129, 130, 133, 134};

uint32_t dd=1010;


kkkkint main(void) {
		ADC_Init();
		time.second = data[0];
		time.minute = data[1];
		time.hour = data[2];
		time.date = data[3];
		time_update.second=10;
	  time_update.minute=04;
	  time_update.hour=16;
		DS3231_Init(I2C1);
		//DS3231_SetTime(I2C1,&time_update);
    // Cau hình TIM1 và DMA
	  WS2812_Config(0,0,0);
    TIM1_Config();
	  timer1_enable();
    DMA_Config();
		dma1_channe15_enable();
		
		
		//Update_Data(22,22);
		//Start_Transmit();
		//TIM1->CCR1 = 0;  
		
    while (1) {
			blue=0;
			green=0;
			red=0;
			for (int i=1; i<=100;i++){
				blue+=read_ADC(0);
			}
			for (int i=1; i<=100;i++){
				green+=read_ADC(1);
			}
			for (int i=1; i<=100;i++){
				red+=read_ADC(2);
			}
			blue=blue/10000;
			red=red/10000;
			green=green/10000;
			//ADC_ReadMulti(datargb);
			DS3231_GetTime(I2C1, &time);
			WS2812_Config(0,0,0);
			Update_Data(time.hour,time.minute);
			Start_Transmit();
			dd++;
			delay_ms1(100);
			
		}
}
void WS2812_Config(int G, int R, int B) {
    uint32_t indx = 0;
    uint32_t color;

    for (int i = 0; i < MAX_LED; i++) {
        color = ((G << 16) | (R << 8) | (B));
        for (int i = 23; i >= 0; i--) {
            if (color & (1 << i)) {
                pwmData[indx] = 62; // 2/3 cua 90
            } else {
                pwmData[indx] = 28; // 1/3 cua 90
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
            pwmData[start_index] = 62; // Logic '1' - 2/3 c?a chu k?
        } else {
            pwmData[start_index] = 28; // Logic '0' - 1/3 c?a chu k?
        }
        start_index++; // Chuy?n sang bit ti?p theo
    }
}
void TIM1_Config(void) {
	
	// Enable clock for GPIOA
	RCC->RCC_APB2ENR.reg |= 0x01<<2;
	
	// co ngat
	GPIOA->GPIO_CRH.reg |= 0x03<<8;
	GPIOA->GPIO_CRH.reg &= ~(0x03<<10);
	GPIOA->GPIO_ODR.reg &= ~(0x01<<10);

	
	// PA8: alternate output push/pull
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
    RCC->RCC_AHBENR |= RCC_AHBENR_DMA1EN;
			
		//DMA1_Channel2->CCR |= 0x01<<9; //32 bits data
		//DMA1_Channel2->CCR |= 0x01<<11; // 32 bits data
	
		DMA1_Channel5->CPAR = (uint32_t)(&TIM1->CCR1);
		DMA1_Channel5->CMAR = (uint32_t)pwmData;
		DMA1_Channel5->CNDTR = 24*MAX_LED + delay;

	//cho phep ngat sau khi truyen xong
}    
void dma1_channe15_enable(void){
		DMA1_Channel5->CCR |= 0x03<<12;  // highest priority
		DMA1_Channel5->CCR |= 0x01<<4;   //Read from memory	
    //DMA1_Channel5->CCR |= 0x01<<5; // Circular Mode
		DMA1_Channel5->CCR |= 0x01<<7; //Memory increment mode enabled
	  DMA1_Channel5->CCR |= 0x01<<10;
	  DMA1_Channel5->CCR |= 0x01<<8;
	  DMA1_Channel5->CCR |= 0x01<<1; // B?t ng?t Transfer Complete
    uint32_t irq_num = 15; // DMA1_Channel5_IRQn có giá trị là 17
    uint32_t reg_index = irq_num / 32; // Chọn ISER tương ứng
    uint32_t bit_pos = irq_num % 32; // Vị trí bit trong thanh ghi ISER

    // Kích hoạt ngắt bằng cách ghi vào ISER
    NVIC->NVIC_ISER[reg_index].reg = (1U << bit_pos); // Kích ho?t ng?t DMA trong NVIC

}

void DMA1_Channel5_IRQHandler(void) {
    if (DMA1->ISR &  ((uint32_t)0x00020000) ) {
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
void Update_Time_Hour(uint8_t hour){
	switch(hour/10){        // tách chu so hang chuc          
		case 0:
			Update_Multiple_Leds(so1_0,32,red,green,blue);
			break;
		case 1:
			Update_Multiple_Leds(so1_1,19,red,green,blue);
			break;
		case 2:
			Update_Multiple_Leds(so1_2,28,red,green,blue);
			break;
		case 3:
			Update_Multiple_Leds(so1_3,28,red,green,blue);
			break;
		case 4:
			Update_Multiple_Leds(so1_4,28,red,green,blue);
			break;
		case 5:
			Update_Multiple_Leds(so1_5,28,red,green,blue);
			break;
		case 6:
			Update_Multiple_Leds(so1_6,36,red,green,blue);
			break;
		case 7:
			Update_Multiple_Leds(so1_7,20,red,green,blue);
			break;
		case 8:
			Update_Multiple_Leds(so1_8,44,red,green,blue);
			break;
		case 9:
			Update_Multiple_Leds(so1_9,42,red,green,blue);
			break;
	}
	switch(hour%10){        // tách chu so hang don vi          
		case 0:
			Update_Multiple_Leds(so2_0,32,red,green,blue);
			break;
		case 1:
			Update_Multiple_Leds(so2_1,19,red,green,blue);
			break;
		case 2:
			Update_Multiple_Leds(so2_2,28,red,green,blue);
			break;
		case 3:
			Update_Multiple_Leds(so2_3,28,red,green,blue);
			break;
		case 4:
			Update_Multiple_Leds(so2_4,28,red,green,blue);
			break;
		case 5:
			Update_Multiple_Leds(so2_5,28,red,green,blue);
			break;
		case 6:
			Update_Multiple_Leds(so2_6,36,red,green,blue);
			break;
		case 7:
			Update_Multiple_Leds(so2_7,20,red,green,blue);
			break;
		case 8:
			Update_Multiple_Leds(so2_8,44,red,green,blue);
			break;
		case 9:
Update_Multiple_Leds(so2_9,42,red,green,blue);
			break;
	}
}
void Update_Time_Min(uint8_t min){
	switch(min/10){        // tách chu so hang chuc          
		case 0:
			Update_Multiple_Leds(so3_0,32,red,green,blue);
			break;
		case 1:
			Update_Multiple_Leds(so3_1,19,red,green,blue);
			break;
		case 2:
			Update_Multiple_Leds(so3_2,28,red,green,blue);
			break;
		case 3:
			Update_Multiple_Leds(so3_3,28,red,green,blue);
			break;
		case 4:
			Update_Multiple_Leds(so3_4,28,red,green,blue);
			break;
		case 5:
			Update_Multiple_Leds(so3_5,28,red,green,blue);
			break;
		case 6:
			Update_Multiple_Leds(so3_6,36,red,green,blue);
			break;
		case 7:
			Update_Multiple_Leds(so3_7,20,red,green,blue);
			break;
		case 8:
			Update_Multiple_Leds(so3_8,44,red,green,blue);
			break;
		case 9:
			Update_Multiple_Leds(so3_9,42,red,green,blue);
			break;
	}
	switch(min%10){        // tách chu so hang don vi          
		case 0:
			Update_Multiple_Leds(so4_0,32,red,green,blue);
			break;
		case 1:
			Update_Multiple_Leds(so4_1,19,red,green,blue);
			break;
		case 2:
			Update_Multiple_Leds(so4_2,28,red,green,blue);
			break;
		case 3:
			Update_Multiple_Leds(so4_3,28,red,green,blue);
			break;
		case 4:
			Update_Multiple_Leds(so4_4,28,red,green,blue);
			break;
		case 5:
			Update_Multiple_Leds(so4_5,28,red,green,blue);
			break;
		case 6:
			Update_Multiple_Leds(so4_6,36,red,green,blue);
			break;
		case 7:
			Update_Multiple_Leds(so4_7,20,red,green,blue);
			break;
		case 8:
			Update_Multiple_Leds(so4_8,44,red,green,blue);
			break;
		case 9:
			Update_Multiple_Leds(so4_9,42,red,green,blue);
			break;
	}
}
void Update_Data(uint8_t hour, uint8_t min){
	/* 
	Update multiple leds here
	*/
		Update_Multiple_Leds(dau_hai_cham,8,10,0,10);
		Update_Time_Min(min);
		Update_Time_Hour(hour);
		DMA1_Channel5->CPAR = (uint32_t)(&TIM1->CCR1);
		DMA1_Channel5->CMAR = (uint32_t)pwmData;
		DMA1_Channel5->CNDTR = 24*MAX_LED + delay;
}

void Start_Transmit(void){
		DMA1_Channel5->CCR |= 0x01;
	while(!(GPIOA->GPIO_ODR.reg & (0x01 << 10)));
	if((GPIOA->GPIO_ODR.reg & (0x01 << 10))){
			GPIOA->GPIO_ODR.reg &= ~(0x01<<10);
		  DMA1_Channel5->CCR &= ~0x01;
	}
}