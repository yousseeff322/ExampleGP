
#include "STD_type.h"
#include "BIT_math.h"

#include "RCC_interface.h"

#include "TIMER2_interface.h"
#include "TIMER2_private.h"
#include "TIMER2_config.h"






void MTIMER2_init(u8 Copy_u8Delay_type)
{
    // Enable TIM2 clock in RCC
    MRCC_VidEnablePeripheralClock(RCC_APB1, TIM2_RCC);

    switch(Copy_u8Delay_type)
    {
        case delay_ms:
            MTIMER2->PSC = (u16)71999; // Correct Prescaler for 1ms
            break;

        case delay_us:
            MTIMER2->PSC = (u16)71; // Correct Prescaler for 1µs
            break;
    }

    MTIMER2->EGR = (1 << EGR_UG); // Force update event to load prescaler
    MTIMER2->CR1 = (u16)0x0080; // Enable timer but don't start yet
}



void MTIMER2_delay_ms(u16 Copy_u16Value)
{
    MTIMER2->CNT = 0; // Reset the counter
    MTIMER2->ARR = Copy_u16Value; // Set Auto-Reload Register
    SET_BIT(MTIMER2->CR1, CR1_CEN); // Start the timer
    while (GET_BIT(MTIMER2->SR, SR_UIF) == 0); // Wait until update event
    CLR_BIT(MTIMER2->SR, SR_UIF); // Clear the flag
}

void MTIMER2_delay_us(u16 Copy_u16Value)
{
    MTIMER2->CNT = 0; // Reset the counter
    MTIMER2->ARR = Copy_u16Value; // Set Auto-Reload Register
    SET_BIT(MTIMER2->CR1, CR1_CEN); // Start the timer
    while (GET_BIT(MTIMER2->SR, SR_UIF) == 0); // Wait until update event
    CLR_BIT(MTIMER2->SR, SR_UIF); // Clear the flag
}

