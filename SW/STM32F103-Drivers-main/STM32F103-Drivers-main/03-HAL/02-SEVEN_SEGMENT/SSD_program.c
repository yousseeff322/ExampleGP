/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 6 MAR 2024                 */
/* Version          : v01                        */ 
/*************************************************/

#include "STD_type.h"
#include "BIT_math.h"

#include "DIO_interface.h" 
#include "SSD_private.h"
#include "SSD_interface.h"
#include "SSD_config.h"


u8 SSDARR1 [10] = {
    0b11000000,  // Digit 0
    0b11111001,  // Digit 1
    0b10100100,  // Digit 2
    0b10110000,  // Digit 3
    0b10011001,  // Digit 4
    0b10010010,  // Digit 5
    0b10000010,  // Digit 6
    0b11111000,  // Digit 7
    0b10000000,  // Digit 8
    0b10010000   // Digit 9
};



u8 SSD_u8Display(SSD_t *Copy_SSD, u8 Copy_u8Value)
{
    u8 Local_u8StateError = OK;

    /* Set SSD port direction */
    MGPIO_VidSetPortDirection(Copy_SSD->SSD_u8Port, LOW, OUT_SPEED_2MHZ_PP);
    MGPIO_VidSetPortDirection(Copy_SSD->SSD_u8Port, HIGH, OUT_SPEED_2MHZ_PP);

    /* Set port value in binary to display */
    switch (Copy_SSD->SSD_u8CommonType)
    {
    case SSD_COM_ANODE:
    	MGPIO_VidSetPinValue(Copy_SSD->SSD_u8Port, LOW, SSDARR1[Copy_u8Value]);
    	MGPIO_VidSetPinValue(Copy_SSD->SSD_u8Port, LOW, (SSDARR1[Copy_u8Value]) << 8);
        break;
    case SSD_COM_CATHODE:
    	MGPIO_VidSetPinValue(Copy_SSD->SSD_u8Port, LOW, ~SSDARR1[Copy_u8Value]);
    	MGPIO_VidSetPinValue(Copy_SSD->SSD_u8Port, LOW, ~(SSDARR1[Copy_u8Value]) << 8);
        break;
    default:
        Local_u8StateError = NOK;
        break;
    }

    return Local_u8StateError;
}




u8 SSD_u8Enable(SSD_t *Copy_SSD)
{
    u8 Local_u8StateError = OK;
    /* Set SSD enable pin direction */
    MGPIO_VidSetPortDirection(Copy_SSD->SSD_u8Port, LOW, OUT_SPEED_2MHZ_PP);
    MGPIO_VidSetPortDirection(Copy_SSD->SSD_u8Port, HIGH, OUT_SPEED_2MHZ_PP);

    /* Check common connection type */
    switch (Copy_SSD->SSD_u8CommonType)
    {
    case SSD_COM_CATHODE:
        /* Set common pin value */
    	MGPIO_VidSetPinValue(Copy_SSD->SSD_u8EnablePort, Copy_SSD->SSD_u8EnablePin, LOW);
        break;
    case SSD_COM_ANODE:
        /* Set common pin value */
    	MGPIO_VidSetPinValue(Copy_SSD->SSD_u8EnablePort, Copy_SSD->SSD_u8EnablePin, HIGH);
        break;
    default:
        Local_u8StateError = NOK;
        break;
    }
    return Local_u8StateError;
}




u8 SSD_u8Disable(SSD_t *Copy_SSD)
{
    u8 Local_u8StateError = OK;
    /* Check common connection type */
    switch (Copy_SSD->SSD_u8CommonType)
    {
    case SSD_COM_CATHODE:
        /* Set common pin value */
    	MGPIO_VidSetPinValue(Copy_SSD->SSD_u8EnablePort, Copy_SSD->SSD_u8EnablePin, HIGH);
        break;
    case SSD_COM_ANODE:
        /* Set common pin value */
    	MGPIO_VidSetPinValue(Copy_SSD->SSD_u8EnablePort, Copy_SSD->SSD_u8EnablePin, LOW);
        break;
    default:
        Local_u8StateError = NOK;
        break;
    }
    return Local_u8StateError;
}

