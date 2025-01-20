/*
 * main.c
 *
 *  Created on: Sep 21, 2020
 *      Author: Ahmed
 */
#include "STD_type.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "SPI_interface.h"
#include "RCC_interface.h"

#include "TFT_interface.h"
#include "image.h"

void main(void)
{
	/* RCC Initialization */
	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock(RCC_APB2,GPIOA_RCC);   /* GPIOA */
	MRCC_VidEnablePeripheralClock(RCC_APB2,SPI1_RCC);  /* SPI1  */

	/* Pin Initializations */

	MGPIO_VidSetPinDirection(GPIOA,5,0b1001);  /* CLK  */
	MGPIO_VidSetPinDirection(GPIOA,7,0b1001);  /* MOSI */

	/* Init STK */
	MSTK_voidInit();

	/* SPI Init */
	MSPI1_voidInit();

	/* TFT Init */
	HTFT_voidInit();

	/* Display Image */
	//HTFT_voidDisplayImage(image);
	 //HTFT_voidFullColor ( 0xF800) ; // white color
	 // HTFT_voidDrawRect ( 0 ,  30 , 0  ,  30 ,  0xffff) ;
	HTFT_voidPrintText((s8*)"Youssef Hamed " , 0 , 0 , 2 , TFT_BLUE , TFT_YELLOW );

	while(1);

}

