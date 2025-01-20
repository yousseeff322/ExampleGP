#include "STD_type.h"
#include "BIT_math.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"

#include "file.h"

#include "DIO_private.h"

void voidSetDAC(void);
volatile  u16 i = 0 ;

int main (void)
{
		MRCC_VidInit();
		MRCC_VidDisablePeripheralClock(RCC_APB2 , GPIOA_RCC) ;


		/* GPIO direction */
		MGPIO_voidSetPinDirection(GPIOA , PIN0 , OUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN1 , OUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN2 , OUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN3 , OUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN4 , OUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN5 , OUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN6 , OUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN7 , OUT_SPEED_2MHZ_PP);

			MSTK_voidInit();
			MSTK_voidSetIntervalPeriodic(125, voidSetDAC) ;

	while (1) {

	}
		return 0 ;
}


void voidSetDAC(void)
{
		GPIOA_ODR = one_raw[i] ;
		i++ ;
		if (i == 39098 )
		{
			i = 0 ;
		}
}


