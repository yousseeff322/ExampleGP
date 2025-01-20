/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 9 MAR 2024                 */
/* Version          : v01                        */ 
/*************************************************/


#include "STD_type.h"
#include "BIT_math.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#include "AFIO_interface.h"



static void (* EXTI0_CallBack) (void) = NULL ;

void MEXTI_voidInit()
{
	#if     EXTI_LINE == EXTI_LINE0
	        SET_BIT(EXTI -> IMR , 0);
	#elif   EXTI_LINE == EXTI_LINE1
	        SET_BIT(EXTI -> IMR , 1);
	#elif   EXTI_LINE == EXTI_LINE2
	        SET_BIT(EXTI -> IMR , 2);
	#elif   EXTI_LINE == EXTI_LINE3
	        SET_BIT(EXTI -> IMR , 3);
	#else
		#error("Wrong External Interrupt Line !")
	#endif

	#if   EXTI_MODE == RISING
	SET_BIT(EXTI -> RTSR , EXTI_LINE);
	#elif EXTI_MODE == FALLING
	SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#elif EXTI_MODE == ON_CHANGE
	SET_BIT(EXTI -> RTSR , EXTI_LINE);
	SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#else
		#error ("Wrong Externl Interrupt Sense Mode !")
	#endif

}
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case RISING    :    SET_BIT(EXTI -> RTSR , EXTI_LINE);  break;
		case FALLING   :    SET_BIT(EXTI -> FTSR , EXTI_LINE);  break;
		case ON_CHANGE :    SET_BIT(EXTI -> RTSR , EXTI_LINE);
	                        SET_BIT(EXTI -> FTSR , EXTI_LINE);  break;

	}
	SET_BIT(EXTI -> IMR , Copy_u8Line);
}
void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> IMR ,Copy_u8Line);

}
void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI -> IMR ,Copy_u8Line);
}
void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> SWIER ,Copy_u8Line);
}


void MEXTI_voidSetCallBack(void (*ptr) (void))
{
		EXTI0_CallBack = ptr ;
}

void	EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI -> PR , 0);
}
