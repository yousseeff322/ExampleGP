/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 25 APR 2024                 */
/* Version          : v01                        */ 
/*************************************************/


#include "STD_type.h"
#include "BIT_math.h"

#include "DIO_interface.h"
#include "SYSTICK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void HSTP_voidSendSynchronus(u8 Copy_u8DataToSend)
{
	s8 Local_s8Counter;
	u8 Local_u8Bit;
	for (Local_s8Counter = 7; Local_s8Counter >=0; Local_s8Counter--)
	{
		/* Send bit by bit strating from MSb */
		Local_u8Bit =  GET_BIT(Copy_u8DataToSend,Local_s8Counter);
		
		MGPIO_VidSetPinValue(HSTP_SERIAL_DATA,Local_u8Bit);
		

		/* Send Pulse to Shift Clock */
		MGPIO_VidSetPinValue(HSTP_SHIFT_CLOCK,HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_VidSetPinValue(HSTP_SHIFT_CLOCK,LOW);
		MSTK_voidSetBusyWait(1);
	}
	
			/* Send Pulse to Shift Clock */
	MGPIO_VidSetPinValue(HSTP_STORE_CLOCK,HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_VidSetPinValue(HSTP_STORE_CLOCK,LOW);
	MSTK_voidSetBusyWait(1);
	
}




