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
#include "DMA_interface.h"

#include "DMA_private.h"

u16 Local_u16Index;
void main(void)
{
	u32 Arr1[1000]={0};
	u32 Arr2[1000];

	u32 Arr3[1000]={0};
	u32 Arr4[1000];



	/*Enable clock on DMA Peripheral*/
	MRCC_VidEnablePeripheralClock(RCC_AHB , 0);

	MDMA_voidChannel1Init();

	MNVIC_voidEnableInterrupt(11);
	MDMA_voidChannel1Start(Arr1,Arr2,1000);

	for(Local_u16Index=0;Local_u16Index<1000;Local_u16Index++)
	{
		Arr4[Local_u16Index]=Arr3[Local_u16Index];
	}


	while(1)
	{

	}
}
void DMA1_Channel1_IRQHandler(void)
{
	/*Clear Interrupt flag*/
	DMA->IFCR =1<<0;		/*Clear Global Interrupt flag of channel1*/
	DMA->IFCR =1<<1;		/*Clear transfer complete Interrupt flag of channel1*/
}
