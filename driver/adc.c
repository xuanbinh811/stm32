#include "adc.h"

void ADC_Init(){
	/*Enable clock access to GPIOA*/
	//enable clock access to GPIOA
//	RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
	/*Set PA0 to analog Mode*/
//	GPIOA->CRL&=~GPIO_CRL_CNF0;
//	GPIOA->CRL&=~GPIO_CRL_MODE0;
	GPIO_Init(GPIO_A,Pin0,INPUT,INPUT_Analog);
	/*Enable clock accrss to ADC1*/
	RCC->RCC_APB2ENR.bit.ADC1EN=1;
	ADC1->SMPR2 |= (7 << (3 * 0)); // 239.5 cycles cho kênh PA0
	ADC1->SMPR2 |= (7 << (3 * 1)); // 239.5 cycles cho kênh PA1
	ADC1->SMPR2 |= (7 << (3 * 2)); // 239.5 cycles cho kênh PA2
	/*Set the trigger to be software mode*/
	ADC1->CR2 |= (7UL << 17);
	//  ADC1->SQR1 &= ~ADC_SQR1_L;   // Độ dài chuỗi: 3 chuyển đổi (L = 2)
  //  ADC1->SQR1 |= (2 << 20);     // L = 2 (tương ứng với 3 kênh)
   // ADC1->SQR3 = (0 << 0)        // Kênh 0 (PA0) là kênh đầu tiên
    //          | (1 << 5)         // Kênh 1 (PA1) là kênh thứ hai
    //          | (2 << 10);       // Kênh 2 (PA2) là kênh thứ ba
	/*Power up the adc*/
	ADC1->CR2|=ADC_CR2_ADON;
	ADC1->CR2 |= ADC_CR2_CAL;  // Hiệu chỉnh ADC
  while (ADC1->CR2 & ADC_CR2_CAL);


	/*Launch the ADC*/
	ADC1->CR2|=ADC_CR2_ADON;
}
uint32_t read_ADC(uint8_t channel){
		ADC1->SQR3 = channel;
	/*Relaunch the ADC*/
		ADC1->CR2|=ADC_CR2_ADON;
		/*Launch the ADC conversion*/
		ADC1->CR2|=ADC_CR2_SWSTART;

		/*wait for EOC*/

		while(!(ADC1->SR &ADC_SR_EOC));

		return ADC1->DR;
}

void ADC_ReadMulti(uint16_t *data) {
    ADC1->CR2 |= ADC_CR2_SWSTART; // Bắt đầu chuyển đổi
    for (int i = 0; i < 3; i++) {
        while (!(ADC1->SR & ADC_SR_EOC)); // Đợi cờ EOC được set
        data[i] = ADC1->DR;              // Đọc giá trị ADC
    }
}