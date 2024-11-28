#ifndef __STM32F103C8_H__
#define __STM32F103C8_H__
#include <stdint.h>
// RCC_Typedef
typedef struct
{
    // RCC_CR: Clock Control Register (Offset: 0x00)
    union
    {
        uint32_t reg;
        struct
        {
            uint32_t HSION      : 1; // [0] Internal High-Speed clock enable
            uint32_t HSIRDY     : 1; // [1] Internal High-Speed clock ready flag
            uint32_t Reserved1  : 1; // [2] Reserved
            uint32_t HSITRIM    : 5; // [3:7] Internal High-Speed clock trimming 
            uint32_t HSICAL     : 8; // [8:15] Internal High-Speed clock calibration
            uint32_t HSEON      : 1; // [16] External High-Speed clock enable 
            uint32_t HSERDY     : 1; // [17] External High-Speed clock ready flag
            uint32_t HSEBYP     : 1; // [18] External High-Speed clock bypass 
            uint32_t CSSON      : 1; // [19] Clock Security System enable
            uint32_t Reserved2  : 4; // [20:23] Reserved 
            uint32_t PLLON      : 1; // [24] PLL enable
            uint32_t PLLRDY     : 1; // [25] PLL ready flag 
            uint32_t Reserved3  : 6; // [26:31] Reserved 
        } bit;
    } RCC_CR;

    // RCC_CFGR: Clock Configuration Register (Offset: 0x04)
    union
    {
        uint32_t reg;
        struct
        {
            uint32_t SW         : 2; // System clock switch
            uint32_t SWS        : 2; // System clock switch status
            uint32_t HPRE       : 4; // AHB prescaler
            uint32_t PPRE1      : 3; // APB1 low-speed prescaler
            uint32_t PPRE2      : 3; // APB2 high-speed prescaler
            uint32_t ADCPRE     : 2; // ADC prescaler
            uint32_t PLLSRC     : 1; // PLL entry clock source
            uint32_t PLLXTPRE   : 1; // HSE divider for PLL entry
            uint32_t PLLMUL     : 4; // PLL multiplication factor
            uint32_t USBPRE     : 1; // USB prescaler
            uint32_t Reserved1  : 1; // Reserved
            uint32_t MCO        : 3; // Microcontroller clock output
            uint32_t Reserved2  : 5;
        } bit;
    } RCC_CFGR;

    // RCC_CIR: Clock Interrupt Register (Offset: 0x08)
    union
    {
        uint32_t reg;
        struct
        {
            uint32_t LSIRDYF    : 1; // LSI ready interrupt flag
            uint32_t LSERDYF    : 1; // LSE ready interrupt flag
            uint32_t HSIRDYF    : 1; // HSI ready interrupt flag
            uint32_t HSERDYF    : 1; // HSE ready interrupt flag
            uint32_t PLLRDYF    : 1; // PLL ready interrupt flag
            uint32_t CSSF       : 1; // Clock security system interrupt flag
            uint32_t Reserved1  : 2;
            uint32_t LSIRDYIE   : 1; // LSI ready interrupt enable
            uint32_t LSERDYIE   : 1; // LSE ready interrupt enable
            uint32_t HSIRDYIE   : 1; // HSI ready interrupt enable
            uint32_t HSERDYIE   : 1; // HSE ready interrupt enable
            uint32_t PLLRDYIE   : 1; // PLL ready interrupt enable
            uint32_t Reserved2  : 3;
            uint32_t LSIRDYC    : 1; // LSI ready clear
            uint32_t LSERDYC    : 1; // LSE ready clear
            uint32_t HSIRDYC    : 1; // HSI ready clear
            uint32_t HSERDYC    : 1; // HSE ready clear
            uint32_t PLLRDYC    : 1; // PLL ready clear
            uint32_t CSSC       : 1; // Clock security system clear
            uint32_t Reserved3  : 10;
        } bit;
    } RCC_CIR;

    // Các thanh ghi khác
    uint32_t RCC_APB2RSTR; // APB2 Peripheral Reset Register (Offset: 0x0C)
    uint32_t RCC_APB1RSTR; // APB1 Peripheral Reset Register (Offset: 0x10)
    uint32_t RCC_AHBENR;   // AHB Peripheral Clock Enable Register (Offset: 0x14)
    
    // // RCC_APB2ENR: APB2 Peripheral Clock Enable Register (Offset: 0x18)
    union
    {
      uint32_t reg;
      struct
      {
          uint32_t AFIOEN    : 1; // [0] Alternate Function I/O clock enable
          uint32_t Reserved1 : 1; // [1] Reserved
          uint32_t IOPAEN    : 1; // [2] GPIOA clock enable
          uint32_t IOPBEN    : 1; // [3] GPIOB clock enable
          uint32_t IOPCEN    : 1; // [4] GPIOC clock enable
          uint32_t IOPDEN    : 1; // [5] GPIOD clock enable
          uint32_t IOPEEN    : 1; // [6] GPIOE clock enable
          uint32_t IOPFEN    : 1; // [7] GPIOF clock enable
          uint32_t IOPGEN    : 1; // [8] GPIOG clock enable
          uint32_t ADC1EN    : 1; // [9] ADC1 clock enable
          uint32_t ADC2EN    : 1; // [10] ADC2 clock enable
          uint32_t TIM1EN    : 1; // [11] TIM1 clock enable
          uint32_t SPI1EN    : 1; // [12] SPI1 clock enable
          uint32_t TIM8EN    : 1; // [13] TIM8 clock enable
          uint32_t USART1EN  : 1; // [14] USART1 clock enable
          uint32_t ADC3EN    : 1; // [15] ADC3 clock enable
          uint32_t Reserved2 : 16; // [16:31] Reserved
      }bit;
    }RCC_APB2ENR;
    
    // RCC_APB1ENR: APB1 Peripheral Clock Enable Register (Offset: 0x1C)
    union
    {
      uint32_t reg;
      struct
      {
          uint32_t AFIOEN    : 1; // [0] Alternate Function I/O clock enable
          uint32_t Reserved1 : 1; // [1] Reserved
          uint32_t IOPAEN    : 1; // [2] GPIOA clock enable
          uint32_t IOPBEN    : 1; // [3] GPIOB clock enable
          uint32_t IOPCEN    : 1; // [4] GPIOC clock enable
          uint32_t IOPDEN    : 1; // [5] GPIOD clock enable
          uint32_t IOPEEN    : 1; // [6] GPIOE clock enable
          uint32_t IOPFEN    : 1; // [7] GPIOF clock enable
          uint32_t IOPGEN    : 1; // [8] GPIOG clock enable
          uint32_t ADC1EN    : 1; // [9] ADC1 clock enable
          uint32_t ADC2EN    : 1; // [10] ADC2 clock enable
          uint32_t TIM1EN    : 1; // [11] TIM1 clock enable
          uint32_t SPI1EN    : 1; // [12] SPI1 clock enable
          uint32_t TIM8EN    : 1; // [13] TIM8 clock enable
          uint32_t USART1EN  : 1; // [14] USART1 clock enable
          uint32_t ADC3EN    : 1; // [15] ADC3 clock enable
          uint32_t Reserved2 : 16; // [16:31] Reserved
      }bit;
    }RCC_APB1ENR;
    

    uint32_t RCC_BDCR;     // Backup Domain Control Register (Offset: 0x20)
    uint32_t RCC_CSR;      // Control/Status Register (Offset: 0x24)

} RCC_Typedef;

// RCC base
#define RCC ((volatile RCC_Typedef *) 0x40021000)

// GPIO_Typedef
typedef struct
{
    // [0x0] GPIO Port Configuration Low Register
    volatile union {
      uint32_t reg; // Truy c?p toàn b? thanh ghi d?ng 32-bit
      struct {
          uint32_t MODE0 : 2;  // MODE cho chân 0
          uint32_t CNF0 : 2;   // CNF cho chân 0
          uint32_t MODE1 : 2;  // MODE cho chân 1
          uint32_t CNF1 : 2;   // CNF cho chân 1
          uint32_t MODE2 : 2;  // MODE cho chân 2
          uint32_t CNF2 : 2;   // CNF cho chân 2
          uint32_t MODE3 : 2;  // MODE cho chân 3
          uint32_t CNF3 : 2;   // CNF cho chân 3
          uint32_t MODE4 : 2;  // MODE cho chân 4
          uint32_t CNF4 : 2;   // CNF cho chân 4
          uint32_t MODE5 : 2;  // MODE cho chân 5
          uint32_t CNF5 : 2;   // CNF cho chân 5
          uint32_t MODE6 : 2;  // MODE cho chân 6
          uint32_t CNF6 : 2;   // CNF cho chân 6
          uint32_t MODE7 : 2;  // MODE cho chân 7
          uint32_t CNF7 : 2;   // CNF cho chân 7
      } bit;
    } GPIO_CRL;
    
    // [0x04] GPIO Port Configuration High Register
    volatile union {
      uint32_t reg; // Truy c?p toàn b? thanh ghi d?ng 32-bit
      struct {
          uint32_t MODE8 : 2;  // MODE cho chân 8
          uint32_t CNF8 : 2;   // CNF cho chân 8
          uint32_t MODE9 : 2;  // MODE cho chân 9
          uint32_t CNF9 : 2;   // CNF cho chân 9
          uint32_t MODE10 : 2; // MODE cho chân 10
          uint32_t CNF10 : 2;  // CNF cho chân 10
          uint32_t MODE11 : 2; // MODE cho chân 11
          uint32_t CNF11 : 2;  // CNF cho chân 11
          uint32_t MODE12 : 2; // MODE cho chân 12
          uint32_t CNF12 : 2;  // CNF cho chân 12
          uint32_t MODE13 : 2; // MODE cho chân 13
          uint32_t CNF13 : 2;  // CNF cho chân 13
          uint32_t MODE14 : 2; // MODE cho chân 14
          uint32_t CNF14 : 2;  // CNF cho chân 14
          uint32_t MODE15 : 2; // MODE cho chân 15
          uint32_t CNF15 : 2;  // CNF cho chân 15
      } bit;
    } GPIO_CRH;
    
    // [0x08] GPIO Port Input Data Register
    volatile union {
      uint32_t reg;  // Thanh ghi 32 bit

      struct {
          uint32_t Pin0  : 1;  // 1 bit cho Pin 0
          uint32_t Pin1  : 1;  // 1 bit cho Pin 1
          uint32_t Pin2  : 1;  // 1 bit cho Pin 2
          uint32_t Pin3  : 1;  // 1 bit cho Pin 3
          uint32_t Pin4  : 1;  // 1 bit cho Pin 4
          uint32_t Pin5  : 1;  // 1 bit cho Pin 5
          uint32_t Pin6  : 1;  // 1 bit cho Pin 6
          uint32_t Pin7  : 1;  // 1 bit cho Pin 7
          uint32_t Pin8  : 1;  // 1 bit cho Pin 8
          uint32_t Pin9  : 1;  // 1 bit cho Pin 9
          uint32_t Pin10 : 1;  // 1 bit cho Pin 10
          uint32_t Pin11 : 1;  // 1 bit cho Pin 11
          uint32_t Pin12 : 1;  // 1 bit cho Pin 12
          uint32_t Pin13 : 1;  // 1 bit cho Pin 13
          uint32_t Pin14 : 1;  // 1 bit cho Pin 14
          uint32_t Pin15 : 1;  // 1 bit cho Pin 15
          uint32_t reserved: 16;  // Các bit d? tr? n?u c?n thi?t
      }bit;
    } GPIO_IDR;
    
    // [0x0C] GPIO Port Output Data Register
    volatile union {
      uint32_t reg; // Truy c?p toàn b? thanh ghi du?i d?ng 32-bit
      struct {
          uint32_t ODR0 : 1;  // Bit 0 - Output Data Register cho chân 0
          uint32_t ODR1 : 1;  // Bit 1 - Output Data Register cho chân 1
          uint32_t ODR2 : 1;  // Bit 2 - Output Data Register cho chân 2
          uint32_t ODR3 : 1;  // Bit 3 - Output Data Register cho chân 3
          uint32_t ODR4 : 1;  // Bit 4 - Output Data Register cho chân 4
          uint32_t ODR5 : 1;  // Bit 5 - Output Data Register cho chân 5
          uint32_t ODR6 : 1;  // Bit 6 - Output Data Register cho chân 6
          uint32_t ODR7 : 1;  // Bit 7 - Output Data Register cho chân 7
          uint32_t ODR8 : 1;  // Bit 8 - Output Data Register cho chân 8
          uint32_t ODR9 : 1;  // Bit 9 - Output Data Register cho chân 9
          uint32_t ODR10 : 1; // Bit 10 - Output Data Register cho chân 10
          uint32_t ODR11 : 1; // Bit 11 - Output Data Register cho chân 11
          uint32_t ODR12 : 1; // Bit 12 - Output Data Register cho chân 12
          uint32_t ODR13 : 1; // Bit 13 - Output Data Register cho chân 13
          uint32_t ODR14 : 1; // Bit 14 - Output Data Register cho chân 14
          uint32_t ODR15 : 1; // Bit 15 - Output Data Register cho chân 15
          uint32_t Reserved : 16; 
      } bit;
    } GPIO_ODR;
    volatile uint32_t BSRR;  // [0x10] GPIO Port Bit Set/Reset Register
    volatile uint32_t BRR;   // [0x14] GPIO Port Bit Reset Register
    volatile uint32_t LCKR;  // [0x18] GPIO Port Configuration Lock Register
} GPIO_Typedef;

// Ð?nh nghia d?a ch? các GPIO trên STM32F103C8T6
#define GPIOA ((GPIO_Typedef *)0x40010800)
#define GPIOB ((GPIO_Typedef *)0x40010C00)
#define GPIOC ((GPIO_Typedef *)0x40011000)
#define GPIOD ((GPIO_Typedef *)0x40011400)
#define GPIOE ((GPIO_Typedef *)0x40011800)
#define GPIOG ((GPIO_Typedef *)0x40012000)

#endif