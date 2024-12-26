#ifndef WS2812_H
#define WS2812_H

#include "stm32f103c8.h"

#define MAX_LED (32 * 8) // Số lượng LED
#define DELAY 100

extern uint16_t pwmData[(24 * MAX_LED) + DELAY];
extern volatile uint8_t datasentflag;
extern volatile int k;

// Định nghĩa cấu trúc
typedef struct {
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
} dongho_index;

// Khai báo các hàm
void TIM1_Config(void);
void DMA_Config(void);
void WS2812_Config(int G, int R, int B);
void timer1_enable(void);
void dma1_channe12_enable(void);
void Update_Led(int led_idx, int G, int R, int B);
void Update_Multiple_Leds(uint8_t leds[], int led_count, int G, int R, int B);

#endif // WS2812_H
