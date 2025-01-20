/*
 * main.c
 *
 * Created on: Mar 11, 2024
 * Author: Youssef Hamed
 */

#include "STD_type.h"
#include "BIT_math.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSTICK_interface.h"
#include "AFIO_interface.h"
#include "IR_interface.h"


void HandleRemoteKey(u8 Copy_u8Key) ;

void main(void)
{
    // Initialize system clock
    MRCC_VidInit();
    MRCC_VidEnablePeripheralClock(RCC_APB2, GPIOA_RCC);   // Enable clock for GPIOA
    MRCC_VidEnablePeripheralClock(RCC_APB2, AFIO_RCC);    // Enable clock for AFIO


    MSTK_voidInit();


    // Configure PA0 as input with pull-up

    MGPIO_VidSetPinDirection(GPIOA, PIN0, INPUT_FLOATING);

    MGPIO_VidSetPinDirection(GPIOA, PIN1, OUT_SPEED_2MHZ_PP);
    MGPIO_VidSetPinDirection(GPIOA, PIN2, OUT_SPEED_2MHZ_PP);
    MGPIO_VidSetPinDirection(GPIOA, PIN3, OUT_SPEED_2MHZ_PP);


    HIR_voidSetCallBack(HandleRemoteKey);

    MEXTI_voidSetCallBack(HIR_voidGetFrame);
    MEXTI_voidInit(); // Initialize EXTI for PA0

	/* Enable EXTI0 from NVIC */
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6); /* EXTI0 */


    while(1)
    {

    }
}


// Callback function to handle the received IR remote key
void HandleRemoteKey(u8 Copy_u8Key)
{
    switch (Copy_u8Key)
    {
        case STOP:
            MGPIO_VidSetPinValue(GPIOA, PIN2, GPIO_HIGH);  // Turn ON
            break;

        case MODE:
            MGPIO_VidSetPinValue(GPIOA, PIN2, GPIO_LOW);   // Turn OFF
            break;
        case MUTE:
            MGPIO_VidSetPinValue(GPIOA, PIN1, GPIO_HIGH);  // Volume Up (e.g., Increase brightness)
            break;
        case ON:
            MGPIO_VidSetPinValue(GPIOA, PIN1, GPIO_LOW);   // Volume Down (e.g., Decrease brightness)
            break;
        case NEXT:
            MGPIO_VidSetPinValue(GPIOA, PIN3, GPIO_HIGH);  // Next (e.g., Next track)
            break;
        case BACK:
            MGPIO_VidSetPinValue(GPIOA, PIN3, GPIO_LOW);   // Back (e.g., Previous track)
            break;
        // Add more cases for other buttons as needed
        default:
            // Handle undefined keys
            break;

    }
}
