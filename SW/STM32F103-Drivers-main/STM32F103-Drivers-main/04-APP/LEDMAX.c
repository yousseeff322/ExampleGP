/*
 * main.c
 *
 *  Created on: Mar 11, 2024
 *      Author: YOUSSEF
 */

#include "STD_type.h"
#include "BIT_math.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSTICK_interface.h"
#include "LEDMRX_interface.h"


u8 DataArr [8] = {0, 143, 136, 136, 136, 255, 0, 0} ;



void main(void)
{
	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock(RCC_APB2  , GPIOA_RCC);
	MRCC_VidEnablePeripheralClock(RCC_APB2  , GPIOB_RCC);

	MSTK_voidInit() ;
	HLEDMRX_voidInit();

	/* SEND DATA  */
	HLEDMRX_voidDisplay(DataArr) ;
	while(1){




	}

}



