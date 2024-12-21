#ifndef __RCC_DS3231_H__
#define __RCC_DS3231_H__

#include "stm32f103c8.h"
#include "i2c.h"
typedef struct {
	uint8_t second;
	uint8_t minute;
	uint8_t hour;
	uint8_t day;
	uint8_t date;
	uint8_t month;
	uint8_t year;
} Time_t;
// RCC Configuration APIs
void RCC_EnableHSE(void);
void RCC_EnableI2CClock(void);

// DS3231 APIs
void DS3231_Init(I2C_TypeDef *I2C);
void DS3231_SetTime(I2C_TypeDef *I2C, Time_t *time);
void DS3231_SetDate(I2C_TypeDef *I2C, uint8_t day, uint8_t date, uint8_t month, uint8_t year);
void DS3231_GetTime(I2C_TypeDef *I2C, Time_t *time);
void DS3231_GetDate(I2C_TypeDef *I2C, uint8_t *day, uint8_t *date, uint8_t *month, uint8_t *year);

#endif // __RCC_DS3231_H__
