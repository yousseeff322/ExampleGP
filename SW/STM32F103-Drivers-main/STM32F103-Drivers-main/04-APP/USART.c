/*
  * main.c
 *
 *  Created on: APR 29, 2024
 *      Author: YOUSSEF
 */
#include "STD_type.h"
#include "BIT_math.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "USART_interface.h"



void main(void)
{

	u8 Data ;

	MRCC_VidInit() ;
	/*Enable clock on GPIOA Peripheral*/
	MRCC_VidEnablePeripheralClock(RCC_APB2 , USART1_RCC);
	MRCC_VidEnablePeripheralClock(RCC_APB2 , GPIOA_RCC);

		/* PINA9 -->Rx    PINA10 --> TX */
	MGPIO_VidSetPinDirection(GPIOA , PIN10 , OUT_SPEED_50MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA , PIN9  , INPUT_FLOATING);
	MGPIO_VidSetPinDirection(GPIOA , PIN0 , OUT_SPEED_2MHZ_PP);

	MUSART1_voidInit() ;



	while(1)
	{

		MUSART1_voidTransmit("97") ;

		Data = MUSART1_voidReceive () ;
		if (Data == '5' )
		{
			MGPIO_VidSetPinValue(GPIOA , PIN0  , HIGH);

		}
		if (Data== 'r' )
		{
			MGPIO_VidSetPinValue(GPIOA , PIN0  , LOW);

		}
	}
}
