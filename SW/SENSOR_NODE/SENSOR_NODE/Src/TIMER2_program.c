
#include "STD_type.h"
#include "BIT_math.h"
#include "FunHelp.h"


#include "TIMER2_interface.h"
#include "TIMER2_private.h"
#include "TIMER2_config.h"






void MTIMER2_init(u8 Copy_u8Delay_type)
{
	switch(Copy_u8Delay_type)
	{
		case delay_ms:
			MTIMER2 -> PSC  = (u16)7999;
			MTIMER2 -> CR1  = (u16)0x0088;
			break;

		case delay_us:
			MTIMER2 -> PSC  = (u16)7;
			MTIMER2 -> CR1  = (u16)0x0088;
			break;
	}
	return;
}

void MTIMER2_delay_ms(u16 Copy_u16Value)
{
	MTIMER2 -> ARR = Copy_u16Value;
	SET_BIT((MTIMER2 -> CR1),CR1_CEN);
	while(GET_BIT((MTIMER2 -> SR),SR_UIF) == 0);
	CLR_BIT((MTIMER2 -> SR),SR_UIF);
	return;
}

void MTIMER2_delay_us(u16 Copy_u16Value)
{
	MTIMER2 -> ARR = Copy_u16Value;
	SET_BIT((MTIMER2 -> CR1),CR1_CEN);
	while(GET_BIT((MTIMER2 -> SR),SR_UIF) == 0);
	CLR_BIT((MTIMER2 -> SR),SR_UIF);
	return;
}

