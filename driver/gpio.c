#include "gpio.h"
#include "stm32f103c8.h"

GPIO_Status GPIO_Init(GPIO_Type GPIOx,GPIO_Pin pin,GPIO_Mode mode,GPIO_Option option){
  GPIO_Typedef *baseaddress;
  
  switch (GPIOx){
    case GPIO_A:
      baseaddress=GPIOA;
      RCC->RCC_APB2ENR.bit.IOPAEN=1;
      break;
    case GPIO_B:
      baseaddress= GPIOB;
      RCC->RCC_APB2ENR.bit.IOPBEN=1;
      break;
    case GPIO_C:
      baseaddress= GPIOC;
      RCC->RCC_APB2ENR.bit.IOPCEN=1;
      break;
    case GPIO_D:
      baseaddress= GPIOD;
      RCC->RCC_APB2ENR.bit.IOPDEN=1;
      break;
    case GPIO_E:
      baseaddress= GPIOE;
      RCC->RCC_APB2ENR.bit.IOPEEN=1;
      break;
    case GPIO_G:
      baseaddress= GPIOG;
      RCC->RCC_APB2ENR.bit.IOPGEN=1;
      break; 
  }
  
  switch (pin){
    case Pin0:
    case Pin1:    
    case Pin2: 
    case Pin3: 
    case Pin4: 
    case Pin5: 
    case Pin6: 
    case Pin7:
      baseaddress->GPIO_CRL.reg &= ~(0xF << (pin * 4));
      baseaddress->GPIO_CRL.reg|=(uint32_t)(mode<<(pin*4));
      switch (option) {
        case INPUT_Analog:
            baseaddress->GPIO_CRL.reg|=(uint32_t)(0<<(pin*4+2));
            break;

        case INPUT_Float:
            baseaddress->GPIO_CRL.reg|=(uint32_t)(1<<(pin*4+2));
            break;

        case INPUT_Pullup:
            baseaddress->GPIO_CRL.reg|=(uint32_t)(2<<(pin*4+2));
            baseaddress->GPIO_ODR.reg|=(uint32_t)(1<<pin);
            break;

        case INPUT_Pulldown:
            baseaddress->GPIO_CRL.reg|=(uint32_t)(2<<(pin*4+2));
            baseaddress->GPIO_ODR.reg&=~(uint32_t)(1<<pin);
            break;

        case OUTPUT_GPPushpull:
            baseaddress->GPIO_CRL.reg|=(uint32_t)(0<<(pin*4+2));
            break;

        case OUTPUT_GPOpendrain:
            baseaddress->GPIO_CRL.reg|=(uint32_t)(1<<(pin*4+2));
            break;

        case OUTPUT_AFPushpull:
            baseaddress->GPIO_CRL.reg|=(uint32_t)(2<<(pin*4+2));
            break;

        case OUTPUT_AFOpendrain:
            baseaddress->GPIO_CRL.reg|=(uint32_t)(3<<(pin*4+2));
            break;

      }
      break;
    case Pin8: 
    case Pin9:
    case Pin10:    
    case Pin11: 
    case Pin12: 
    case Pin13: 
    case Pin14: 
    case Pin15: 
      baseaddress->GPIO_CRH.reg &= ~(0xF << ((uint32_t)(pin - 8) * 4));
      baseaddress->GPIO_CRH.reg|=(uint32_t)(mode<<((pin-8)*4));
      switch (option) {
        case INPUT_Analog:
            baseaddress->GPIO_CRH.reg|=(uint32_t)(0<<((pin-8)*4+2));
            break;

        case INPUT_Float:
            baseaddress->GPIO_CRH.reg|=(uint32_t)(1<<((pin-8)*4+2));
            break;

        case INPUT_Pullup:
            baseaddress->GPIO_CRH.reg|=(uint32_t)(2<<((pin-8)*4+2));
            baseaddress->GPIO_ODR.reg|=(uint32_t)(1<<(pin-8));
            break;

        case INPUT_Pulldown:
            baseaddress->GPIO_CRH.reg|=(uint32_t)(2<<((pin-8)*4+2));
            baseaddress->GPIO_ODR.reg&=~(uint32_t)(1<<(pin-8));
            break;

        case OUTPUT_GPPushpull:
            baseaddress->GPIO_CRH.reg|=(uint32_t)(0<<((pin-8)*4+2));
            break;

        case OUTPUT_GPOpendrain:
            baseaddress->GPIO_CRH.reg|=(uint32_t)(1<<((pin-8)*4+2));
            break;

        case OUTPUT_AFPushpull:
            baseaddress->GPIO_CRH.reg|=(uint32_t)(2<<((pin-8)*4+2));
            break;

        case OUTPUT_AFOpendrain:
            baseaddress->GPIO_CRH.reg|=(uint32_t)(3<<((pin-8)*4+2));
            break;

      }
      break;
 
  }
  return OK;
}

uint8_t GPIOA_Read(GPIO_Pin pin){
  return (GPIOA->GPIO_IDR.reg &(1<<pin))>>pin;
}
uint8_t GPIOB_Read(GPIO_Pin pin){
  return (GPIOB->GPIO_IDR.reg &(1<<pin))>>pin;
}
uint8_t GPIOC_Read(GPIO_Pin pin){
  return (GPIOC->GPIO_IDR.reg &(1<<pin))>>pin;
}
void GPIOA_Write(GPIO_Pin pin, Logic_level t) {
    if (t == HIGH) {
        GPIOA->GPIO_ODR.reg |= (1 << pin);  // Set the pin to high
    } 
    if (t==LOW) {
        GPIOA->GPIO_ODR.reg &= ~(1 << pin);  // Set the pin to low
    }
}
void GPIOB_Write(GPIO_Pin pin, Logic_level t) {
    if (t == HIGH) {
        GPIOB->GPIO_ODR.reg |= (1 << pin);  // Set the pin to high
    } 
    if (t==LOW) {
        GPIOB->GPIO_ODR.reg &= ~(1 << pin);  // Set the pin to low
    }
}
void GPIOC_Write(GPIO_Pin pin, Logic_level t) {
    if (t == HIGH) {
        GPIOC->GPIO_ODR.reg |= (1 << pin);  // Set the pin to high
    } 
    if (t==LOW) {
        GPIOC->GPIO_ODR.reg &= ~(1 << pin);  // Set the pin to low
    }
}
