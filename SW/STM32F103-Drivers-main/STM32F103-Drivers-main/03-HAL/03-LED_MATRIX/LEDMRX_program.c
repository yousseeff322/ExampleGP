/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 15 APR 2024                 */
/* Version          : v01                        */ 
/*************************************************/

#include "STD_type.h"
#include "BIT_math.h"

#include "DIO_interface.h" 
#include "SYSTICK_interface.h" 


#include "LEDMRX_private.h"
#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"





void HLEDMRX_voidInit (void ) 
{
	
	MGPIO_VidSetPinDirection(LEDMRX_ROW0_PIN  , OUT_SPEED_2MHZ_PP) ;
	MGPIO_VidSetPinDirection(LEDMRX_ROW1_PIN  , OUT_SPEED_2MHZ_PP) ;
	MGPIO_VidSetPinDirection(LEDMRX_ROW2_PIN  , OUT_SPEED_2MHZ_PP) ;
	MGPIO_VidSetPinDirection(LEDMRX_ROW3_PIN  , OUT_SPEED_2MHZ_PP) ;
	MGPIO_VidSetPinDirection(LEDMRX_ROW4_PIN  , OUT_SPEED_2MHZ_PP) ;
	MGPIO_VidSetPinDirection(LEDMRX_ROW5_PIN  , OUT_SPEED_2MHZ_PP) ;
	MGPIO_VidSetPinDirection(LEDMRX_ROW6_PIN  , OUT_SPEED_2MHZ_PP) ;
	MGPIO_VidSetPinDirection(LEDMRX_ROW7_PIN  , OUT_SPEED_2MHZ_PP) ;

	MGPIO_VidSetPinDirection(LEDMRX_COL0_PIN  , OUT_SPEED_2MHZ_PP) ;
	MGPIO_VidSetPinDirection(LEDMRX_COL1_PIN  , OUT_SPEED_2MHZ_PP) ;
	MGPIO_VidSetPinDirection(LEDMRX_COL2_PIN  , OUT_SPEED_2MHZ_PP) ;
	MGPIO_VidSetPinDirection(LEDMRX_COL3_PIN  , OUT_SPEED_2MHZ_PP) ;
	MGPIO_VidSetPinDirection(LEDMRX_COL4_PIN  , OUT_SPEED_2MHZ_PP) ;
	MGPIO_VidSetPinDirection(LEDMRX_COL5_PIN  , OUT_SPEED_2MHZ_PP) ;
	MGPIO_VidSetPinDirection(LEDMRX_COL6_PIN  , OUT_SPEED_2MHZ_PP) ;
	MGPIO_VidSetPinDirection(LEDMRX_COL7_PIN  , OUT_SPEED_2MHZ_PP) ;

	
	
	
} 


void HLEDMRX_voidDisplay (u8 *Copy_u8Data) 
{
	
	while (1)
	{	
	/* Disable  all columes */ 
	HLEDMRX_voidDisableAllCols() ; 
	/* Enable col 0 */ 
	HLEDMRX_voidSetRowValues(Copy_u8Data[0]);
	ActivateColumn(0) ;
	MSTK_voidSetBusyWait(2500) ;   //2.5 msec
		
	/* Disable  all columes */ 
	HLEDMRX_voidDisableAllCols() ; 
	/* Enable col 1 */ 
	HLEDMRX_voidSetRowValues(Copy_u8Data[1]);
	ActivateColumn(1) ;
	MSTK_voidSetBusyWait(2500) ;   //2.5 msec
		
	/* Disable  all columes */ 
	HLEDMRX_voidDisableAllCols() ; 
	/* Enable col 2 */ 
	HLEDMRX_voidSetRowValues(Copy_u8Data[2]);
	ActivateColumn(2) ;
	MSTK_voidSetBusyWait(2500) ;   //2.5 msec
		
	/* Disable  all columes */ 
	HLEDMRX_voidDisableAllCols() ; 
	/* Enable col 3 */ 
	HLEDMRX_voidSetRowValues(Copy_u8Data[3]);
	ActivateColumn(3) ;
	MSTK_voidSetBusyWait(2500) ;   //2.5 msec
		
	/* Disable  all columes */ 
	HLEDMRX_voidDisableAllCols() ; 
	/* Enable col 4 */ 
	HLEDMRX_voidSetRowValues(Copy_u8Data[4]);
	ActivateColumn(4) ;
	MSTK_voidSetBusyWait(2500) ;   //2.5 msec
		
	/* Disable  all columes */ 
	HLEDMRX_voidDisableAllCols() ; 
	/* Enable col 5 */ 
	HLEDMRX_voidSetRowValues(Copy_u8Data[5]);
	ActivateColumn(5) ;
	MSTK_voidSetBusyWait(2500) ;   //2.5 msec
		
	/* Disable  all columes */ 
	HLEDMRX_voidDisableAllCols() ; 
	/* Enable col 6*/ 
	HLEDMRX_voidSetRowValues(Copy_u8Data[6]);
	ActivateColumn(6) ;
	MSTK_voidSetBusyWait(2500) ;   //2.5 msec
		
	/* Disable  all columes */ 
	HLEDMRX_voidDisableAllCols() ; 
	/* Enable col 7 */ 
	HLEDMRX_voidSetRowValues(Copy_u8Data[7]);
	ActivateColumn(7) ;
	MSTK_voidSetBusyWait(2500) ;   //2.5 msec
	}
}


/* private functions */ 
static void HLEDMRX_voidDisableAllCols(void) 
{
		/* Disable  all columes */ 
	MGPIO_VidSetPinValue(LEDMRX_COL0_PIN  , HIGH) ;
	MGPIO_VidSetPinValue(LEDMRX_COL1_PIN  , HIGH) ;
	MGPIO_VidSetPinValue(LEDMRX_COL2_PIN  , HIGH) ;
	MGPIO_VidSetPinValue(LEDMRX_COL3_PIN  , HIGH) ;
	MGPIO_VidSetPinValue(LEDMRX_COL4_PIN  , HIGH) ;
	MGPIO_VidSetPinValue(LEDMRX_COL5_PIN  , HIGH) ;
	MGPIO_VidSetPinValue(LEDMRX_COL6_PIN  , HIGH) ;
} 

/* private functions */ 
static void HLEDMRX_voidSetRowValues(u8 Copy_u8Value) 
{
	u8 Local_u8Bit ;

		Local_u8Bit = GET_BIT(Copy_u8Value , 0 ) ; 
		MGPIO_VidSetPinValue(LEDMRX_ROW0_PIN  , Local_u8Bit) ;
	

	Local_u8Bit = GET_BIT(Copy_u8Value , 1 ) ; 
	MGPIO_VidSetPinValue(LEDMRX_ROW1_PIN  , Local_u8Bit) ;

	Local_u8Bit = GET_BIT(Copy_u8Value, 2 ) ; 
	MGPIO_VidSetPinValue(LEDMRX_ROW2_PIN  , Local_u8Bit) ;


	Local_u8Bit = GET_BIT(Copy_u8Value, 3 ) ; 
	MGPIO_VidSetPinValue(LEDMRX_ROW3_PIN  , Local_u8Bit) ;


	Local_u8Bit = GET_BIT(Copy_u8Value , 4 ) ; 
	MGPIO_VidSetPinValue(LEDMRX_ROW4_PIN  , Local_u8Bit) ;
 

	Local_u8Bit = GET_BIT(Copy_u8Value , 5) ; 
	MGPIO_VidSetPinValue(LEDMRX_ROW5_PIN  , Local_u8Bit) ;

	Local_u8Bit = GET_BIT(Copy_u8Value , 6 ) ; 
	MGPIO_VidSetPinValue(LEDMRX_ROW6_PIN  , Local_u8Bit) ;
	
	Local_u8Bit = GET_BIT(Copy_u8Value , 7 ) ; 
	MGPIO_VidSetPinValue(LEDMRX_ROW7_PIN  , Local_u8Bit) ;
	
	
}




void ActivateColumn(u8 Copy_u8Col)
{
	/* Disable All */
	MGPIO_VidSetPinValue(LEDMRX_COL0_PIN,HIGH);
	MGPIO_VidSetPinValue(LEDMRX_COL1_PIN,HIGH);
	MGPIO_VidSetPinValue(LEDMRX_COL2_PIN,HIGH);
	MGPIO_VidSetPinValue(LEDMRX_COL3_PIN,HIGH);
	MGPIO_VidSetPinValue(LEDMRX_COL4_PIN,HIGH);
	MGPIO_VidSetPinValue(LEDMRX_COL5_PIN,HIGH);
	MGPIO_VidSetPinValue(LEDMRX_COL6_PIN,HIGH);
	MGPIO_VidSetPinValue(LEDMRX_COL7_PIN,HIGH);

	/* Enable the desired pin only */
	switch (Copy_u8Col)
	{
		case 0: MGPIO_VidSetPinValue(LEDMRX_COL0_PIN,LOW); break;
		case 1: MGPIO_VidSetPinValue(LEDMRX_COL1_PIN,LOW); break;
		case 2: MGPIO_VidSetPinValue(LEDMRX_COL2_PIN,LOW); break;
		case 3: MGPIO_VidSetPinValue(LEDMRX_COL3_PIN,LOW); break;
		case 4: MGPIO_VidSetPinValue(LEDMRX_COL4_PIN,LOW); break;
		case 5: MGPIO_VidSetPinValue(LEDMRX_COL5_PIN,LOW); break;
		case 6: MGPIO_VidSetPinValue(LEDMRX_COL6_PIN,LOW); break;
		case 7: MGPIO_VidSetPinValue(LEDMRX_COL7_PIN,LOW); break;
	}
}

















static void	HLEDMRX_voidDisplayloop	(u8	* Copy_u8Data, u32 Copy_u32speed)
{
	for (u32 k = 0 ; k < Copy_u32speed ; k++)
	{

		/* Disable  all columes */
		HLEDMRX_voidDisableAllCols() ;
		/* Enable col 0 */
		HLEDMRX_voidSetRowValues(Copy_u8Data[0]);
		ActivateColumn(0) ;
		MSTK_voidSetBusyWait(2500) ;   //2.5 msec

		/* Disable  all columes */
		HLEDMRX_voidDisableAllCols() ;
		/* Enable col 1 */
		HLEDMRX_voidSetRowValues(Copy_u8Data[1]);
		ActivateColumn(1) ;
		MSTK_voidSetBusyWait(2500) ;   //2.5 msec

		/* Disable  all columes */
		HLEDMRX_voidDisableAllCols() ;
		/* Enable col 2 */
		HLEDMRX_voidSetRowValues(Copy_u8Data[2]);
		ActivateColumn(2) ;
		MSTK_voidSetBusyWait(2500) ;   //2.5 msec

		/* Disable  all columes */
		HLEDMRX_voidDisableAllCols() ;
		/* Enable col 3 */
		HLEDMRX_voidSetRowValues(Copy_u8Data[3]);
		ActivateColumn(3) ;
		MSTK_voidSetBusyWait(2500) ;   //2.5 msec

		/* Disable  all columes */
		HLEDMRX_voidDisableAllCols() ;
		/* Enable col 4 */
		HLEDMRX_voidSetRowValues(Copy_u8Data[4]);
		ActivateColumn(4) ;
		MSTK_voidSetBusyWait(2500) ;   //2.5 msec

		/* Disable  all columes */
		HLEDMRX_voidDisableAllCols() ;
		/* Enable col 5 */
		HLEDMRX_voidSetRowValues(Copy_u8Data[5]);
		ActivateColumn(5) ;
		MSTK_voidSetBusyWait(2500) ;   //2.5 msec

		/* Disable  all columes */
		HLEDMRX_voidDisableAllCols() ;
		/* Enable col 6*/
		HLEDMRX_voidSetRowValues(Copy_u8Data[6]);
		ActivateColumn(6) ;
		MSTK_voidSetBusyWait(2500) ;   //2.5 msec

		/* Disable  all columes */
		HLEDMRX_voidDisableAllCols() ;
		/* Enable col 7 */
		HLEDMRX_voidSetRowValues(Copy_u8Data[7]);
		ActivateColumn(7) ;
		MSTK_voidSetBusyWait(2500) ;   //2.5 msec
	}
}

void	HLEDMRX_voidDisplayMotion	(u8	* Copy_u8DataLarge ,u32 speed)
{
	u8 Copy_u8DataSmall[8];
	for(u8 i=0 ; i<25 ;i++)
	{
		for(u8 j=0 ; j<8 ;j++)
		{
			Copy_u8DataSmall[j]= Copy_u8DataLarge[i+j];
		}
		HLEDMRX_voidDisplayloop	(Copy_u8DataSmall,speed);
	}
}
