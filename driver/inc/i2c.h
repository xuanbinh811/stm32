#ifndef __I2C_H__
#define __I2C_H__

#include "stm32f103c8.h"
#include "gpio.h"
#include "RCC.h"


// Function prototypes
void I2C_Init(I2C_TypeDef *I2C, uint32_t clockSpeed, uint8_t ownAddress);
void I2C_Start(I2C_TypeDef *I2C);
void I2C_Stop(I2C_TypeDef *I2C);
void I2C_SendAddress(I2C_TypeDef *I2C, uint8_t address, uint8_t read);
void I2C_SendData(I2C_TypeDef *I2C, uint8_t data);
uint8_t I2C_ReceiveData(I2C_TypeDef *I2C);
void I2C_Write(I2C_TypeDef *I2C, uint8_t address, uint8_t *data, uint8_t length);
void I2C_Read(I2C_TypeDef *I2C, uint8_t address, uint8_t *buffer, uint8_t length);
void I2C_Write1(I2C_TypeDef *I2C, uint8_t address, uint8_t *data, uint8_t length);

// Helper macros
#define I2C_WRITE   0   // Write mode (bit 0 = 0)
#define I2C_READ    1   // Read mode (bit 0 = 1)

#endif // __I2C_H__
