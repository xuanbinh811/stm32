#include "i2c.h"

// I2C Initialization
void I2C_Init(I2C_TypeDef *I2C, uint32_t clockSpeed, uint8_t ownAddress) {

    GPIO_Init(GPIO_B, Pin6, OUTPUT_50MHZ, OUTPUT_AFOpendrain);  // SCL
    GPIO_Init(GPIO_B, Pin7, OUTPUT_50MHZ, OUTPUT_AFOpendrain);  // SDA

    // 3. Reset and enable I2C peripheral
    I2C->I2C_CR1.bit.SWRST = 1;  // Software reset
    I2C->I2C_CR1.bit.SWRST = 0;  // Clear reset

    // 4. Configure frequency in I2C_CR2
    uint32_t pclk1 = Get_APB1_Clock();  // Get APB1 clock frequency
    I2C->I2C_CR2.bit.FREQ = pclk1 / 1000000;  // FREQ in MHz

    // 5. Configure CCR (Clock Control Register)
    uint32_t ccrValue = pclk1 / (2 * clockSpeed);
    I2C->CCR = ccrValue & 0xFFF;  // Standard mode (up to 100 kHz)

    // 6. Configure rise time (TRISE)
    I2C->TRISE = (pclk1 / 1000000) + 1;

    // 7. Set own address
    I2C->OAR1 = (ownAddress << 1);  // Left-align 7-bit address
    I2C->OAR1 |= (1 << 14);         // Enable addressing mode

    // 8. Enable the I2C peripheral
    I2C->I2C_CR1.bit.PE = 1;  // Peripheral Enable
}

// Function to send start condition
void I2C_Start(I2C_TypeDef *I2C) {
    I2C->I2C_CR1.bit.START = 1;  // Generate START condition
    while (!I2C->I2C_SR1.bit.SB);  // Wait for start bit (SB) to be set
}

// Function to send stop condition
void I2C_Stop(I2C_TypeDef *I2C) {
    I2C->I2C_CR1.bit.STOP = 1;  // Generate STOP condition
//    while (!I2C->I2C_SR1.bit.STOPF);  // Wait for stop condition to be set
//		I2C->I2C_SR1.bit.STOPF = 0;
}

// Function to send address (read/write)
void I2C_SendAddress(I2C_TypeDef *I2C, uint8_t address, uint8_t read) {
    I2C->DR = (address << 1) | read;  // Send address with read/write bit
    while (!I2C->I2C_SR1.bit.ADDR);  // Wait for address to be acknowledged
    (void)I2C->I2C_SR2.reg;          // Clear ADDR flag by reading SR2
}

// Function to send a byte of data
void I2C_SendData(I2C_TypeDef *I2C, uint8_t data) {
    I2C->DR = data;  // Load data into data register
    while (!I2C->I2C_SR1.bit.BTF);  // Wait for byte transfer finished
}

// Function to receive a byte of data
uint8_t I2C_ReceiveData(I2C_TypeDef *I2C) {
    while (!I2C->I2C_SR1.bit.RXNE);  // Wait for data to be received
    return I2C->DR;                  // Read data from data register
}

// Function to write data to a slave device
void I2C_Write(I2C_TypeDef *I2C, uint8_t address, uint8_t *data, uint8_t length) {
    I2C_Start(I2C);
    I2C_SendAddress(I2C, address, 0);  // 0 for write operation
	//	I2C_SendData(I2C, 0x00);
    for (uint8_t i = 0; i < length; i++) {
        I2C_SendData(I2C, data[i]);
    }
    I2C_Stop(I2C);
}
void I2C_Write1(I2C_TypeDef *I2C, uint8_t address, uint8_t *data, uint8_t length) {
    I2C_Start(I2C);
    I2C_SendAddress(I2C, address, 0);  // 0 for write operation
		I2C_SendData(I2C, 0x00);
    for (uint8_t i = 0; i < length; i++) {
        I2C_SendData(I2C, data[i]);
    }
    I2C_Stop(I2C);
}

// Function to read data from a slave device
void I2C_Read(I2C_TypeDef *I2C, uint8_t address, uint8_t *buffer, uint8_t length) {
    //I2C_Start(I2C);
    //I2C_SendAddress(I2C, address, 1);  // 1 for read operation
    for (uint8_t i = 0; i < length ; i++) {
				I2C_Start(I2C);
				I2C_SendAddress(I2C, address, 1);
        buffer[i] = I2C_ReceiveData(I2C);
        I2C->I2C_CR1.bit.ACK = 0;  // Acknowledge received data
				I2C_Stop(I2C);
    }
    //I2C->I2C_CR1.bit.ACK = 0;  // NACK for last byte
   // buffer[length - 1] = I2C_ReceiveData(I2C);
   // I2C_Stop(I2C);
}
