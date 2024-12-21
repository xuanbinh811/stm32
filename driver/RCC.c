#include "RCC.h" // Include the header file for RCC register definitions

// Function to get the current system clock frequency (SYSCLK)
uint32_t Get_SystemClock(void) {
    uint32_t sysclk, pllmul, pllsrc, prediv;

    // Read the SYSCLK source from RCC_CFGR register (SWS bits)
    switch (RCC->RCC_CFGR.bit.SWS ) { // Extract SWS[1:0] bits
        case 0x00: // HSI oscillator
            sysclk = 8000000; // Default HSI frequency is 8 MHz
            break;
        case 0x01: // HSE oscillator
            sysclk = 8000000; // Blue Pill HSE frequency is 8 MHz
            break;
        case 0x02: // PLL
            pllsrc = RCC->RCC_CFGR.bit.PLLSRC ; // PLLSRC bit (bit 16)
            pllmul = RCC->RCC_CFGR.bit.PLLMUL + 2; // PLLMUL bits (bits 18-21) + 2
            
            if (pllsrc == 0) { // HSI/2 is the PLL source
                sysclk = (8000000 / 2) * pllmul; // Calculate SYSCLK
            } else { // HSE is the PLL source
                prediv = RCC->RCC_CFGR.bit.PLLXTPRE; // PLLXTPRE bit (bit 17)
                sysclk = (8000000 / (prediv+1)) * pllmul; // Calculate SYSCLK based on HSE
            }
            break;
        default:
            sysclk = 8000000; // Default to HSI if no valid source
            break;
    }

    return sysclk; // Return the calculated SYSCLK frequency
}

// Function to get the HCLK (AHB clock)
uint32_t Get_HCLK(void) {
    uint32_t hpre = RCC->RCC_CFGR.bit.HPRE; // Get AHB prescaler
    uint32_t hclk = Get_SystemClock(); // Get system clock frequency
    if (hpre >= 8) { // If prescaler is active
        hclk >>= (hpre - 7); // Divide according to prescaler value
    }
    return hclk; // Return HCLK frequency
}

// Function to get the PCLK1 (APB1 clock)
uint32_t Get_PCLK1(void) {
    uint32_t ppre1 = RCC->RCC_CFGR.bit.PPRE1; // Get APB1 prescaler
    uint32_t pclk1 = Get_HCLK(); // Get HCLK frequency
    if (ppre1 >= 4) { // If prescaler is active
        pclk1 >>= (ppre1 - 3); // Divide according to prescaler value
    }
    return pclk1; // Return PCLK1 frequency
}

// Function to get the PCLK2 (APB2 clock)
uint32_t Get_PCLK2(void) {
    uint32_t ppre2 = RCC->RCC_CFGR.bit.PPRE2; // Get APB2 prescaler
    uint32_t pclk2 = Get_HCLK(); // Get HCLK frequency
    if (ppre2 >= 4) { // If prescaler is active
        pclk2 >>= (ppre2 - 3); // Divide according to prescaler value
    }
    return pclk2; // Return PCLK2 frequency
}
uint32_t Get_APB1_Clock(void) {
    uint32_t hclk = Get_HCLK(); // L?y t?n s? HCLK (High-Speed Clock)
    
    // L?y giá tr? prescaler APB1 t? thanh ghi RCC_CFGR
    uint32_t apb1_prescaler = RCC->RCC_CFGR.bit.PPRE1; // Bits [10:8] là PPRE1 (APB1 prescaler)

    // Xác d?nh h? s? chia tuong ?ng
    if (apb1_prescaler == 0) {
        // Không chia (division factor = 1)
        return hclk;
    } else {
        // H? s? chia t? 2 tr? lên (b?t d?u t? giá tr? 4 trong b?ng tra c?u)
        uint32_t division_factor = 1 << (apb1_prescaler - 3); // 4 -> 2^1, 5 -> 2^2, ...
        return hclk / division_factor;
    }
}
