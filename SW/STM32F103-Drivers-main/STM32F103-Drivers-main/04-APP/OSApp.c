#include "STD_type.h"
#include "BIT_math.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"

#include "OS_interface.h"


void LED1 (void)    ;
void LED2 (void)    ;
void LED3 (void)    ;




int main (void)
{
		MRCC_VidInit();
		MRCC_VidDisablePeripheralClock(RCC_APB2 , GPIOA_RCC) ;


		/* GPIO direction */
		MGPIO_voidSetPinDirection(GPIOA , PIN0 , OUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN1 , OUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(GPIOA , PIN2 , OUT_SPEED_2MHZ_PP);

		SOS_voidCreatTask(0 , 1000 , LED1 ,0) ;

		SOS_voidCreatTask(1 , 2000 ,LED2 ,1) ;

		SOS_voidCreatTask(2 , 3000 , LED3 , 2) ;

		SOS_voidStart() ;


	while (1) {

	}
		return 0 ;
}


void LED1 (void)
{
	static u8 Local_u8Pin0 = 0 ;
	TOGGLE_BIT (Local_u8Pin0 , 0 ) ;
	MGPIO_voidSetPinValue(GPIOA , PIN0 ,Local_u8Pin0 ) ;

}

void LED2 (void)
{
	static u8 Local_u8Pin1 = 0 ;
	TOGGLE_BIT (Local_u8Pin1 , 0 ) ;
	MGPIO_voidSetPinValue(GPIOA , PIN1 ,Local_u8Pin1 ) ;

}


void LED3 (void)
{
	static u8 Local_u8Pin2 = 0 ;
	TOGGLE_BIT (Local_u8Pin2 , 0 ) ;
	MGPIO_voidSetPinValue(GPIOA , PIN2 ,Local_u8Pin2 ) ;

}
