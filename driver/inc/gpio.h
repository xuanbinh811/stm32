#ifndef __GPIO_H__
#define __GPIO_H__
#include <stdint.h>
typedef enum {
  LOW=0,
  HIGH=1
}Logic_level;
typedef enum {
  OK,
  ERROR_GPIO
}GPIO_Status;
typedef enum {
  INPUT =0,
  OUTPUT_10MHZ=1,
  OUTPUT_2MHZ=2,
  OUTPUT_50MHZ=3
}GPIO_Mode;
typedef enum {
  GPIO_A =0,
  GPIO_B =1,
  GPIO_C =2,
  GPIO_D =3,
  GPIO_E =4,
  GPIO_G =5

}GPIO_Type;

typedef enum {
  Pin0=0,
  Pin1=1,
  Pin2=2,
  Pin3=3,
  Pin4=4,
  Pin5=5,
  Pin6=6,
  Pin7=7,
  Pin8=8,
  Pin9=9,
  Pin10=10,
  Pin11=11,
  Pin12=12,
  Pin13=13,
  Pin14=14,
  Pin15=15
}GPIO_Pin;
typedef enum {
  INPUT_Analog,
  INPUT_Float,
  INPUT_Pullup,
  INPUT_Pulldown,
  OUTPUT_GPPushpull,
  OUTPUT_GPOpendrain,
  OUTPUT_AFPushpull,
  OUTPUT_AFOpendrain  
}GPIO_Option;

GPIO_Status GPIO_Init(GPIO_Type GPIOx,GPIO_Pin pin,GPIO_Mode mode,GPIO_Option option);
uint8_t GPIOA_Read(GPIO_Pin pin);
uint8_t GPIOB_Read(GPIO_Pin pin);
uint8_t GPIOC_Read(GPIO_Pin pin);
void GPIOA_Write(GPIO_Pin pin,Logic_level t);
void GPIOB_Write(GPIO_Pin pin,Logic_level t);
void GPIOC_Write(GPIO_Pin pin,Logic_level t);

#endif