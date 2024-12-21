#ifndef __STM32F103C8_H__
#define __STM32F103C8_H__
#include <stdint.h>

#ifndef __IO
#define __IO volatile   
#endif

#ifndef __I
#define __I volatile const 
#endif

#ifndef __O
#define __O volatile  
#endif
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
    __IO union {
				uint32_t reg; // To�n b? 32 bit c?a thanh ghi
				struct {
						uint32_t TIM2EN:1;       // Bit 0: Enable clock for TIM2
						uint32_t TIM3EN:1;       // Bit 1: Enable clock for TIM3
						uint32_t TIM4EN:1;       // Bit 2: Enable clock for TIM4
						uint32_t TIM5EN:1;       // Bit 3: Enable clock for TIM5
						uint32_t TIM6EN:1;       // Bit 4: Enable clock for TIM6
						uint32_t TIM7EN:1;       // Bit 5: Enable clock for TIM7
						uint32_t reserved1:5;    // Bit [10:6]: Reserved
						uint32_t WWDGEN:1;       // Bit 11: Enable clock for Window Watchdog
						uint32_t reserved2:2;    // Bit [13:12]: Reserved
						uint32_t SPI2EN:1;       // Bit 14: Enable clock for SPI2
						uint32_t SPI3EN:1;       // Bit 15: Enable clock for SPI3
						uint32_t reserved3:1;    // Bit 16: Reserved
						uint32_t USART2EN:1;     // Bit 17: Enable clock for USART2
						uint32_t USART3EN:1;     // Bit 18: Enable clock for USART3
						uint32_t UART4EN:1;      // Bit 19: Enable clock for UART4
						uint32_t UART5EN:1;      // Bit 20: Enable clock for UART5
						uint32_t I2C1EN:1;       // Bit 21: Enable clock for I2C1
						uint32_t I2C2EN:1;       // Bit 22: Enable clock for I2C2
						uint32_t USBEN:1;        // Bit 23: Enable clock for USB
						uint32_t reserved4:1;    // Bit 24: Reserved
						uint32_t CAN1EN:1;       // Bit 25: Enable clock for CAN1
						uint32_t CAN2EN:1;       // Bit 26: Enable clock for CAN2
						uint32_t BKPEN:1;        // Bit 27: Enable clock for Backup interface
						uint32_t PWREN:1;        // Bit 28: Enable clock for Power interface
						uint32_t DACEN:1;        // Bit 29: Enable clock for DAC
						uint32_t reserved5:2;    // Bit [31:30]: Reserved
				} bit; // Truy c?p theo bit
		}RCC_APB1ENR;

    

    uint32_t RCC_BDCR;     // Backup Domain Control Register (Offset: 0x20)
    uint32_t RCC_CSR;      // Control/Status Register (Offset: 0x24)

} RCC_Typedef;
#define  RCC_AHBENR_DMA1EN                   ((uint16_t)0x0001)    

// RCC base
#define RCC ((volatile RCC_Typedef *) 0x40021000)

// GPIO_Typedef
typedef struct
{
    // [0x0] GPIO Port Configuration Low Register
    volatile union {
      uint32_t reg; 
      struct {
          uint32_t MODE0 : 2;  // MODE for pin 0
          uint32_t CNF0 : 2;   // CNF for pin 0
          uint32_t MODE1 : 2;  // MODE for pin 1
          uint32_t CNF1 : 2;   // CNF for pin 1
          uint32_t MODE2 : 2;  // MODE for pin 2
          uint32_t CNF2 : 2;   // CNF for pin 2
          uint32_t MODE3 : 2;  // MODE for pin 3
          uint32_t CNF3 : 2;   // CNF for pin 3
          uint32_t MODE4 : 2;  // MODE for pin 4
          uint32_t CNF4 : 2;   // CNF for pin 4
          uint32_t MODE5 : 2;  // MODE for pin 5
          uint32_t CNF5 : 2;   // CNF for pin 5
          uint32_t MODE6 : 2;  // MODE for pin 6
          uint32_t CNF6 : 2;   // CNF for pin 6
          uint32_t MODE7 : 2;  // MODE for pin 7
          uint32_t CNF7 : 2;   // CNF for pin 7
      } bit;
    } GPIO_CRL;
    
    // [0x04] GPIO Port Configuration High Register
    volatile union {
      uint32_t reg; 
      struct {
          uint32_t MODE8 : 2;  // MODE for pin 8
          uint32_t CNF8 : 2;   // CNF for pin 8
          uint32_t MODE9 : 2;  // MODE for pin 9
          uint32_t CNF9 : 2;   // CNF for pin 9
          uint32_t MODE10 : 2; // MODE for pin 10
          uint32_t CNF10 : 2;  // CNF for pin 10
          uint32_t MODE11 : 2; // MODE for pin 11
          uint32_t CNF11 : 2;  // CNF for pin 11
          uint32_t MODE12 : 2; // MODE for pin 12
          uint32_t CNF12 : 2;  // CNF for pin 12
          uint32_t MODE13 : 2; // MODE for pin 13
          uint32_t CNF13 : 2;  // CNF for pin 13
          uint32_t MODE14 : 2; // MODE for pin 14
          uint32_t CNF14 : 2;  // CNF for pin 14
          uint32_t MODE15 : 2; // MODE for pin 15
          uint32_t CNF15 : 2;  // CNF for pin 15
      } bit;
    } GPIO_CRH;
    
    // [0x08] GPIO Port Input Data Register
    volatile union {
      uint32_t reg;  // Thanh ghi 32 bit

      struct {
          uint32_t Pin0  : 1;  // 1 bit for Pin 0
          uint32_t Pin1  : 1;  // 1 bit for Pin 1
          uint32_t Pin2  : 1;  // 1 bit for Pin 2
          uint32_t Pin3  : 1;  // 1 bit for Pin 3
          uint32_t Pin4  : 1;  // 1 bit for Pin 4
          uint32_t Pin5  : 1;  // 1 bit for Pin 5
          uint32_t Pin6  : 1;  // 1 bit for Pin 6
          uint32_t Pin7  : 1;  // 1 bit for Pin 7
          uint32_t Pin8  : 1;  // 1 bit for Pin 8
          uint32_t Pin9  : 1;  // 1 bit for Pin 9
          uint32_t Pin10 : 1;  // 1 bit for Pin 10
          uint32_t Pin11 : 1;  // 1 bit for Pin 11
          uint32_t Pin12 : 1;  // 1 bit for Pin 12
          uint32_t Pin13 : 1;  // 1 bit for Pin 13
          uint32_t Pin14 : 1;  // 1 bit for Pin 14
          uint32_t Pin15 : 1;  // 1 bit for Pin 15
          uint32_t reserved: 16; 
      }bit;
    } GPIO_IDR;
    
    // [0x0C] GPIO Port Output Data Register
    volatile union {
      uint32_t reg;
      struct {
          uint32_t ODR0 : 1;  // Bit 0 - Output Data Register for pin 0
          uint32_t ODR1 : 1;  // Bit 1 - Output Data Register for pin 1
          uint32_t ODR2 : 1;  // Bit 2 - Output Data Register for pin 2
          uint32_t ODR3 : 1;  // Bit 3 - Output Data Register for pin 3
          uint32_t ODR4 : 1;  // Bit 4 - Output Data Register for pin 4
          uint32_t ODR5 : 1;  // Bit 5 - Output Data Register for pin 5
          uint32_t ODR6 : 1;  // Bit 6 - Output Data Register for pin 6
          uint32_t ODR7 : 1;  // Bit 7 - Output Data Register for pin 7
          uint32_t ODR8 : 1;  // Bit 8 - Output Data Register for pin 8
          uint32_t ODR9 : 1;  // Bit 9 - Output Data Register for pin 9
          uint32_t ODR10 : 1; // Bit 10 - Output Data Register for pin 10
          uint32_t ODR11 : 1; // Bit 11 - Output Data Register for pin 11
          uint32_t ODR12 : 1; // Bit 12 - Output Data Register for pin 12
          uint32_t ODR13 : 1; // Bit 13 - Output Data Register for pin 13
          uint32_t ODR14 : 1; // Bit 14 - Output Data Register for pin 14
          uint32_t ODR15 : 1; // Bit 15 - Output Data Register for pin 15
          uint32_t Reserved : 16; 
      } bit;
    } GPIO_ODR;
    volatile uint32_t BSRR;  // [0x10] GPIO Port Bit Set/Reset Register
    volatile uint32_t BRR;   // [0x14] GPIO Port Bit Reset Register
    volatile uint32_t LCKR;  // [0x18] GPIO Port Configuration Lock Register
} GPIO_Typedef;

//GPIO STM32F103C8T6
#define GPIOA ((GPIO_Typedef *)0x40010800)
#define GPIOB ((GPIO_Typedef *)0x40010C00)
#define GPIOC ((GPIO_Typedef *)0x40011000)
#define GPIOD ((GPIO_Typedef *)0x40011400)
#define GPIOE ((GPIO_Typedef *)0x40011800)
#define GPIOF ((GPIO_Typedef *)0x40011C00)
#define GPIOG ((GPIO_Typedef *)0x40012000)


typedef struct {
    // Interrupt Mask Register
    __IO union {
      struct {
          uint32_t MR0  : 1;  // Mask for line 0
          uint32_t MR1  : 1;  // Mask for line 1
          uint32_t MR2  : 1;  // Mask for line 2
          uint32_t MR3  : 1;  // Mask for line 3
          uint32_t MR4  : 1;  // Mask for line 4
          uint32_t MR5  : 1;  // Mask for line 5
          uint32_t MR6  : 1;  // Mask for line 6
          uint32_t MR7  : 1;  // Mask for line 7
          uint32_t MR8  : 1;  // Mask for line 8
          uint32_t MR9  : 1;  // Mask for line 9
          uint32_t MR10 : 1;  // Mask for line 10
          uint32_t MR11 : 1;  // Mask for line 11
          uint32_t MR12 : 1;  // Mask for line 12
          uint32_t MR13 : 1;  // Mask for line 13
          uint32_t MR14 : 1;  // Mask for line 14
          uint32_t MR15 : 1;  // Mask for line 15
          uint32_t MR16 : 1;  // Mask for line 16
          uint32_t MR17 : 1;  // Mask for line 17
          uint32_t MR18 : 1;  // Mask for line 18
          uint32_t MR19 : 1;  // Mask for line 19
          uint32_t Reserved : 12; // Reserved bits
      } bit;
      uint32_t reg; 
    } EXTI_IMR;
    __IO uint32_t EMR;   // Event Mask Register
    // Rising Trigger Selection Register
    __IO union {
        struct {
            uint32_t TR0  : 1;  // Trigger Rising edge configuration for line 0
            uint32_t TR1  : 1;  // Trigger Rising edge configuration for line 1
            uint32_t TR2  : 1;  // Trigger Rising edge configuration for line 2
            uint32_t TR3  : 1;  // Trigger Rising edge configuration for line 3
            uint32_t TR4  : 1;  // Trigger Rising edge configuration for line 4
            uint32_t TR5  : 1;  // Trigger Rising edge configuration for line 5
            uint32_t TR6  : 1;  // Trigger Rising edge configuration for line 6
            uint32_t TR7  : 1;  // Trigger Rising edge configuration for line 7
            uint32_t TR8  : 1;  // Trigger Rising edge configuration for line 8
            uint32_t TR9  : 1;  // Trigger Rising edge configuration for line 9
            uint32_t TR10 : 1;  // Trigger Rising edge configuration for line 10
            uint32_t TR11 : 1;  // Trigger Rising edge configuration for line 11
            uint32_t TR12 : 1;  // Trigger Rising edge configuration for line 12
            uint32_t TR13 : 1;  // Trigger Rising edge configuration for line 13
            uint32_t TR14 : 1;  // Trigger Rising edge configuration for line 14
            uint32_t TR15 : 1;  // Trigger Rising edge configuration for line 15
            uint32_t TR16 : 1;  // Trigger Rising edge configuration for line 16
            uint32_t TR17 : 1;  // Trigger Rising edge configuration for line 17
            uint32_t TR18 : 1;  // Trigger Rising edge configuration for line 18
            uint32_t TR19 : 1;  // Trigger Rising edge configuration for line 19
            uint32_t TR20 : 1;  // Trigger Rising edge configuration for line 20
            uint32_t TR21 : 1;  // Trigger Rising edge configuration for line 21
            uint32_t TR22 : 1;  // Trigger Rising edge configuration for line 22
            uint32_t Reserved : 9; // Reserved bits
        } bit;
        uint32_t reg; 
    } EXTI_RTSR;
    __IO uint32_t FTSR; // Falling Trigger Selection Register
    __IO uint32_t SWIER; // Software Interrupt Event Register
    // Pending Register
    __IO union {
        struct {
            uint32_t PR0  : 1;  //EXTI line 0
            uint32_t PR1  : 1;  //EXTI line 1
            uint32_t PR2  : 1;  //EXTI line 2
            uint32_t PR3  : 1;  //EXTI line 3
            uint32_t PR4  : 1;  //EXTI line 4
            uint32_t PR5  : 1;  //EXTI line 5
            uint32_t PR6  : 1;  //EXTI line 6
            uint32_t PR7  : 1;  //EXTI line 7
            uint32_t PR8  : 1;  //EXTI line 8
            uint32_t PR9  : 1;  //EXTI line 9
            uint32_t PR10 : 1;  //EXTI line 10
            uint32_t PR11 : 1;  //EXTI line 11
            uint32_t PR12 : 1;  //EXTI line 12
            uint32_t PR13 : 1;  //EXTI line 13
            uint32_t PR14 : 1;  //EXTI line 14
            uint32_t PR15 : 1;  //EXTI line 15
            uint32_t Reserved : 16; // reserved
        } bit;
        uint32_t reg;  
    } EXTI_PR;
} EXTI_TypeDef;
#define EXTI ((EXTI_TypeDef *)0x40010400)
typedef union {
		struct {
				uint32_t EXT0  : 4;  //EXTI0 (GPIOA - GPIOG)
				uint32_t EXT1  : 4;  //EXTI1 (GPIOA - GPIOG)
				uint32_t EXT2  : 4;  //EXTI2 (GPIOA - GPIOG)
				uint32_t EXT3  : 4;  //EXTI3 (GPIOA - GPIOG)
				uint32_t Reserved : 16; // 16 Reserved bits
		} bit;
		uint32_t reg;
} AFIO_EXTICR_t;
typedef struct {
    __IO uint32_t EVCR;     /*!< Event Control Register,              Address offset: 0x00 */
    __IO uint32_t MAPR;     /*!< AF Remap and Debug I/O Configuration, Address offset: 0x04 */
    /*!< External Interrupt Configuration Registers, Address offset: 0x08-0x14 */
    __IO AFIO_EXTICR_t AFIO_EXTICR[4];
    __IO uint32_t MAPR2;    /*!< AF Remap and Debug I/O Configuration 2, Address offset: 0x1C */
} AFIO_TypeDef;

#define AFIO ((AFIO_TypeDef *) 0x40010000)

typedef union {
    struct {
        uint32_t SETENA0  : 1;  /*!< Enable interrupt for IRQ 0 */
        uint32_t SETENA1  : 1;  /*!< Enable interrupt for IRQ 1 */
        uint32_t SETENA2  : 1;  /*!< Enable interrupt for IRQ 2 */
        uint32_t SETENA3  : 1;  /*!< Enable interrupt for IRQ 3 */
        uint32_t SETENA4  : 1;  /*!< Enable interrupt for IRQ 4 */
        uint32_t SETENA5  : 1;  /*!< Enable interrupt for IRQ 5 */
        uint32_t SETENA6  : 1;  /*!< Enable interrupt for IRQ 6 */
        uint32_t SETENA7  : 1;  /*!< Enable interrupt for IRQ 7 */
        uint32_t SETENA8  : 1;  /*!< Enable interrupt for IRQ 8 */
        uint32_t SETENA9  : 1;  /*!< Enable interrupt for IRQ 9 */
        uint32_t SETENA10 : 1;  /*!< Enable interrupt for IRQ 10 */
        uint32_t SETENA11 : 1;  /*!< Enable interrupt for IRQ 11 */
        uint32_t SETENA12 : 1;  /*!< Enable interrupt for IRQ 12 */
        uint32_t SETENA13 : 1;  /*!< Enable interrupt for IRQ 13 */
        uint32_t SETENA14 : 1;  /*!< Enable interrupt for IRQ 14 */
        uint32_t SETENA15 : 1;  /*!< Enable interrupt for IRQ 15 */
        uint32_t SETENA16 : 1;  /*!< Enable interrupt for IRQ 16 */
        uint32_t SETENA17 : 1;  /*!< Enable interrupt for IRQ 17 */
        uint32_t SETENA18 : 1;  /*!< Enable interrupt for IRQ 18 */
        uint32_t SETENA19 : 1;  /*!< Enable interrupt for IRQ 19 */
        uint32_t SETENA20 : 1;  /*!< Enable interrupt for IRQ 20 */
        uint32_t SETENA21 : 1;  /*!< Enable interrupt for IRQ 21 */
        uint32_t SETENA22 : 1;  /*!< Enable interrupt for IRQ 22 */
        uint32_t SETENA23 : 1;  /*!< Enable interrupt for IRQ 23 */
        uint32_t SETENA24 : 1;  /*!< Enable interrupt for IRQ 24 */
        uint32_t SETENA25 : 1;  /*!< Enable interrupt for IRQ 25 */
        uint32_t SETENA26 : 1;  /*!< Enable interrupt for IRQ 26 */
        uint32_t SETENA27 : 1;  /*!< Enable interrupt for IRQ 27 */
        uint32_t SETENA28 : 1;  /*!< Enable interrupt for IRQ 28 */
        uint32_t SETENA29 : 1;  /*!< Enable interrupt for IRQ 29 */
        uint32_t SETENA30 : 1;  /*!< Enable interrupt for IRQ 30 */
        uint32_t SETENA31 : 1;  /*!< Enable interrupt for IRQ 31 */
    } bit;                      /*!< Bit access to enable individual IRQs */
    uint32_t reg;               /*!< Access the whole register as a 32-bit value */
} NVIC_ISER_t;
typedef struct {
    __IO NVIC_ISER_t NVIC_ISER[8];     /*!< Interrupt Set-Enable Registers,       Address offset: 0x000 - 0x01C */
    uint32_t RESERVED0[24];    /*!< Reserved space */
    __IO uint32_t ICER[8];     /*!< Interrupt Clear-Enable Registers,     Address offset: 0x080 - 0x09C */
    uint32_t RESERVED1[24];    /*!< Reserved space */
    __IO uint32_t ISPR[8];     /*!< Interrupt Set-Pending Registers,      Address offset: 0x100 - 0x11C */
    uint32_t RESERVED2[24];    /*!< Reserved space */
    __IO uint32_t ICPR[8];     /*!< Interrupt Clear-Pending Registers,    Address offset: 0x180 - 0x19C */
    uint32_t RESERVED3[24];    /*!< Reserved space */
    __IO uint32_t IABR[8];     /*!< Interrupt Active Bit Registers,       Address offset: 0x200 - 0x21C */
    uint32_t RESERVED4[56];    /*!< Reserved space */
    __IO uint8_t  IP[240];     /*!< Interrupt Priority Registers,         Address offset: 0x300 - 0x3EF */
    uint32_t RESERVED5[644];   /*!< Reserved space */
    __O  uint32_t STIR;        /*!< Software Trigger Interrupt Register,  Address offset: 0xE00 */
} NVIC_TypeDef;

#define NVIC ((NVIC_TypeDef *) 0xE000E100) /*!< NVIC base address */


typedef struct {
    __IO uint32_t CTRL;    // SysTick Control and Status Register
    __IO uint32_t LOAD;    // SysTick Reload Value Register
    __IO uint32_t VAL;     // SysTick Current Value Register
    __I  uint32_t CALIB;   // SysTick Calibration Value Register
} SysTick_Type;

#define SYSTICK_BASE        (0xE000E010)  
#define SysTick             ((SysTick_Type*) SYSTICK_BASE)  // Tr? t?i c�c thanh ghi c?a SysTick
#define SysTick_CTRL_ENABLE    (1 << 0)  // Bit 0: SysTick Enable
#define SysTick_CTRL_TICKINT   (1 << 1)  // Bit 1: SysTick Interrupt Enable
#define SysTick_CTRL_CLKSOURCE (1 << 2)  // Bit 2: SysTick Clock Source (1: HCLK, 0: HCLK/8)
#define SysTick_CTRL_COUNTFLAG (1 << 16) // Bit 16: SysTick Count Flag (1: Counter reached 0)

// I2C register bit-field structure for STM32F103C8T6
typedef struct {
    // Control register 1
	 __IO union {
			uint32_t reg;  // Toàn bộ thanh ghi I2C_CR1 (32 bit)
			struct {
					uint32_t PE         : 1;  // Peripheral enable (Bit 0)
					uint32_t SMBUS      : 1;  // SMBus mode (Bit 1)
					uint32_t RESERVED   : 1;  // Reserved (Bit 2) - phải giữ giá trị mặc định
					uint32_t SMBTYPE    : 1;  // SMBus type (Bit 3)
					uint32_t ENARP      : 1;  // ARP enable (Bit 4)
					uint32_t ENPEC      : 1;  // PEC enable (Bit 5)
					uint32_t ENGC       : 1;  // General call enable (Bit 6)
					uint32_t NOSTRETCH  : 1;  // Clock stretching disable (Bit 7)
					uint32_t START      : 1;  // Start generation (Bit 8)
					uint32_t STOP       : 1;  // Stop generation (Bit 9)
					uint32_t ACK        : 1;  // Acknowledge enable (Bit 10)
					uint32_t POS        : 1;  // Acknowledge/PEC position (Bit 11)
					uint32_t PEC        : 1;  // Packet error checking (Bit 12)
					uint32_t ALERT      : 1;  // SMBus alert (Bit 13)
					uint32_t RESERVED2  : 1;  // Reserved (Bit 14-15)
					uint32_t SWRST      : 1;  // Software reset (Bit 16)
					uint32_t RESERVED3  : 16; // Reserved (Bit 17-31)
			} bit;
	} I2C_CR1;

    // Control register 2
		union {
				__IO uint32_t reg;  // Toàn bộ thanh ghi I2C_CR2 (32 bit)
				struct {
						__IO uint32_t FREQ       : 6;  // Peripheral clock frequency (Bit 5-0)
						__IO uint32_t RESERVED2  : 2;  // Reserved (Bit 7-6)
						__IO uint32_t ITERREN    : 1;  // Error interrupt enable (Bit 8)
						__IO uint32_t ITEVTEN    : 1;  // Event interrupt enable (Bit 9)
						__IO uint32_t ITBUFEN    : 1;  // Buffer interrupt enable (Bit 10)
						__IO uint32_t DMAEN      : 1;  // DMA requests enable (Bit 11)
						__IO uint32_t LAST       : 1;  // DMA last transfer (Bit 12)
						__IO uint32_t RESERVED   : 19;  // Reserved (Bit 15-13)
				} bit;
		} I2C_CR2;
    __IO uint32_t OAR1;    // Own address register 1
    __IO uint32_t OAR2;    // Own address register 2
    __IO uint32_t DR;      // Data register
    // Status register 1
		__IO union {
				__IO uint32_t reg;  // To�n b? 32 bit c?a thanh ghi
				struct {
						uint32_t SB:1;        // Bit 0: Start bit (sent/received)
						uint32_t ADDR:1;      // Bit 1: Address sent/received
						uint32_t BTF:1;       // Bit 2: Byte transfer finished
						uint32_t ADD10:1;     // Bit 3: 10-bit header sent
						uint32_t STOPF:1;     // Bit 4: Stop condition detected
						uint32_t reserved1:1; 
						uint32_t RXNE:1;      // Bit 5: Data register not empty (received)
						uint32_t TXE:1;       // Bit 6: Data register empty (transmit)
						uint32_t BERR:1;      // Bit 8: Bus error
						uint32_t ARLO:1;      // Bit 9: Arbitration lost
						uint32_t AF:1;        // Bit 10: Acknowledge failure
						uint32_t OVR:1;       // Bit 11: Overrun/underrun
						uint32_t PECERR:1;    // Bit 12: PEC error in reception
						uint32_t reserved2:1; 
						uint32_t TIMEOUT:1;   // Bit 14: Timeout or Tlow error
						uint32_t SMBALERT:1;  // Bit 15: SMBus alert
						uint32_t reserved:16; // Bit [31:16]: Reserved
				} bit;  // Truy c?p theo bit
		} I2C_SR1;
    // Status register 2
		union {
				__IO uint32_t reg;  // Toàn bộ thanh ghi I2C_SR2 (32 bit)
				struct {
						__IO uint32_t MSL        : 1;  // Master/slave (Bit 0)
						__IO uint32_t BUSY       : 1;  // Bus busy (Bit 1)
						__IO uint32_t TRA        : 1;  // Transmitter/receiver (Bit 2)
						__IO uint32_t RESERVED   : 1;  // Reserved (Bit 3)
						__IO uint32_t GENCALL    : 1;  // General call address (Bit 4)
						__IO uint32_t SMBDEFAULT : 1;  // SMBus device default address (Bit 5)
						__IO uint32_t SMBHOST    : 1;  // SMBus host header (Bit 6)
						__IO uint32_t DUALF      : 1;  // Dual flag (Bit 7)
						__IO uint32_t PEC        : 8;  // Packet error checking register (Bit 15-8)
						__IO uint32_t RESERVED2  : 16;  // Reserved (Bit 15-8)
				} bit;
		} I2C_SR2;

    __IO uint32_t CCR;     // Clock control register
    __IO uint32_t TRISE;   // TRISE register
    __IO uint32_t FLTR;    // Filtering register (I2C has this on some models)
} I2C_TypeDef;
typedef struct
{
  __IO uint32_t CCR;
  __IO uint32_t CNDTR;
  __IO uint32_t CPAR;
  __IO uint32_t CMAR;
} DMA_Channel_TypeDef;
typedef struct
{
  __IO uint32_t ISR;
  __IO uint32_t IFCR;
} DMA_TypeDef;
#define PERIPH_BASE           ((uint32_t)0x40000000) 
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)
#define DMA1_Channel5_BASE    (AHBPERIPH_BASE + 0x0058)
#define DMA1_Channel5       ((DMA_Channel_TypeDef *) DMA1_Channel5_BASE)
#define DMA1_BASE             (AHBPERIPH_BASE + 0x0000)
#define DMA1                ((DMA_TypeDef *) DMA1_BASE)

typedef struct
{
  __IO uint16_t CR1;
  uint16_t  RESERVED0;
  __IO uint16_t CR2;
  uint16_t  RESERVED1;
  __IO uint16_t SMCR;
  uint16_t  RESERVED2;
  __IO uint16_t DIER;
  uint16_t  RESERVED3;
  __IO uint16_t SR;
  uint16_t  RESERVED4;
  __IO uint16_t EGR;
  uint16_t  RESERVED5;
  __IO uint16_t CCMR1;
  uint16_t  RESERVED6;
  __IO uint16_t CCMR2;
  uint16_t  RESERVED7;
  __IO uint16_t CCER;
  uint16_t  RESERVED8;
  __IO uint16_t CNT;
  uint16_t  RESERVED9;
  __IO uint16_t PSC;
  uint16_t  RESERVED10;
  __IO uint16_t ARR;
  uint16_t  RESERVED11;
  __IO uint16_t RCR;
  uint16_t  RESERVED12;
  __IO uint16_t CCR1;
  uint16_t  RESERVED13;
  __IO uint16_t CCR2;
  uint16_t  RESERVED14;
  __IO uint16_t CCR3;
  uint16_t  RESERVED15;
  __IO uint16_t CCR4;
  uint16_t  RESERVED16;
  __IO uint16_t BDTR;
  uint16_t  RESERVED17;
  __IO uint16_t DCR;
  uint16_t  RESERVED18;
  __IO uint16_t DMAR;
  uint16_t  RESERVED19;
} TIM_TypeDef;
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x2C00)
#define TIM1                ((TIM_TypeDef *) TIM1_BASE)
#define  TIM_DIER_CC1DE                      ((uint16_t)0x0200)  
// Defining base address for I2C1
#define I2C1_BASE               (0x40005400U)     // Base address for I2C1
#define I2C1                    ((I2C_TypeDef *)I2C1_BASE)  // I2C1 register structure
#endif
