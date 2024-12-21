#include "rcc_ds3231.h"

// DS3231 APIs
uint8_t toBCD(uint8_t value) {
    return ((value / 10) << 4) | (value % 10);
}

uint8_t fromBCD(uint8_t value) {
    return ((value >> 4) * 10) + (value & 0x0F);
}

void DS3231_Init(I2C_TypeDef *I2C) {
    RCC->RCC_APB1ENR.bit.I2C1EN = 1; // Enable I2C1 clock
    I2C_Init(I2C, 100000, 0x00); // Initialize I2C with 100kHz and no specific address
}

void DS3231_SetTime(I2C_TypeDef *I2C, Time_t *time) {
    uint8_t data[3];

    // Chuyển đổi giây, phút, giờ từ thập phân sang BCD
    data[0] = ((time->second / 10) << 4) | (time->second % 10); // Giây
    data[1] = ((time->minute / 10) << 4) | (time->minute % 10); // Phút
    data[2] = ((time->hour / 10) << 4) | (time->hour % 10); // Giờ
		

    // Ghi dữ liệu vào các thanh ghi bắt đầu từ 0x00 (Giây, Phút, Giờ)
    I2C_Write1(I2C, 0x68, data, 3); // Địa chỉ của DS3231 là 0x68
}

void DS3231_SetDate(I2C_TypeDef *I2C, uint8_t day, uint8_t date, uint8_t month, uint8_t year) {
    uint8_t data[4] = { day, date, month, year };
    I2C_Write(I2C, 0x68, data, 4); // Write date starting from register 0x03
}

void DS3231_GetTime(I2C_TypeDef *I2C, Time_t *time) {
    uint8_t regAddr = 0x00; // Starting register for time
    uint8_t data[7];
    I2C_Write(I2C, 0x68, &regAddr, 1); // Send register address 0x00
		//I2C_SendAddress(I2C, 0, 0);
    I2C_Read(I2C, 0x68, data, 3); // Read 3 bytes (time)
    time->second = ((data[0] >> 4) * 10) + (data[0] & 0x0F);
    time->minute = ((data[1] >> 4) * 10) + (data[1] & 0x0F);
    time->hour = ((data[2] >> 4) & 0x03) * 10 + (data[2] & 0x0F);
}

void DS3231_GetDate(I2C_TypeDef *I2C, uint8_t *day, uint8_t *date, uint8_t *month, uint8_t *year) {
    uint8_t regAddr = 0x03; // Starting register for date
    uint8_t data[4];
    I2C_Write(I2C, 0x68, &regAddr, 1); // Send register address 0x03
    I2C_Read(I2C, 0x68, data, 4); // Read 4 bytes (date)
    *day = ((data[0] >> 4) * 10) + (data[0] & 0x0F);
    *date = ((data[1] >> 4) * 10) + (data[1] & 0x0F);
    *month = data[2];
    *year = data[3];
}
