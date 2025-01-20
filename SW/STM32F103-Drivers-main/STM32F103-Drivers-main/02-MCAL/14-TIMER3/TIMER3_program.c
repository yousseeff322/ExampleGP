
#include "STD_type.h"
#include "BIT_math.h"
#include "FunHelp.h"


#include "TIMER3_interface.h"
#include "TIMER3_private.h"
#include "TIMER3_config.h"


void MTIMER3_init(u8 mode) {
    switch(mode) {
        case delay_ms:
            MTIMER3 -> PSC  = (u16)7999;   // Prescaler set for milliseconds delay
            MTIMER3 -> CR1  = (u16)0x0088; // Configuring the timer
            break;

        case delay_us:
            MTIMER3 -> PSC  = (u16)7;      // Prescaler set for microseconds delay
            MTIMER3 -> CR1  = (u16)0x0088; // Configuring the timer
            break;

        case PWM_channel_1_us:
            MTIMER3 -> CR1   = (u16)0x0081; // Timer in upcounting mode, counter enabled
            MTIMER3 -> PSC   = (u16)7;      // Prescaler for PWM in microseconds
            MTIMER3 -> CCMR1 = (u16)0x0068; // PWM mode settings for channel 1
            MTIMER3 -> CCER  = (u16)0x0001; // Enable output on channel 1
            break;

        case PWM_channel_1_IN:
            MTIMER3 -> CR1   = (u16)0x0001; // Timer in upcounting mode, counter enabled
            MTIMER3 -> PSC   = (u16)7;      // Prescaler for input capture
            MTIMER3 -> CCMR1 = (u16)0x0201; // Input capture settings for channel 1
            MTIMER3 -> CCER  = (u16)0x0031; // Capture on both edges, enable channel 1
    }
    return;
}


void MTIMER3_delay_ms(u16 value)
{
	MTIMER3 -> ARR = value;
	SET_BIT((MTIMER3 -> CR1),CR1_CEN);
	while(GET_BIT((MTIMER3 -> SR),SR_UIF) == 0);
	CLR_BIT((MTIMER3 -> SR),SR_UIF);
	return;
}

void MTIMER3_delay_us(u16 value)
{
	MTIMER3 -> ARR = value;
	SET_BIT((MTIMER3 -> CR1),CR1_CEN);
	while(GET_BIT((MTIMER3 -> SR),SR_UIF) == 0);
	CLR_BIT((MTIMER3 -> SR),SR_UIF);
	return;
}


void MTIMER3_PWM(u8 channel,u16 CNT_value,u16 PWM_value)
{

	MTIMER3 -> ARR = CNT_value;
	switch(channel)
	{
		case MTIMER3_CH1_PORTA_6:
			MTIMER3 -> CCR1 = PWM_value;
			break;

		case MTIMER3_CH2_PORTA_7:
			MTIMER3 -> CCR2 = PWM_value;
			break;

		case MTIMER3_CH3_PORTB_0:
			MTIMER3 -> CCR3 = PWM_value;
			break;

		case MTIMER3_CH4_PORTB_1:
			MTIMER3 -> CCR4 = PWM_value;
			break;
	}

	while(GET_BIT((MTIMER3 -> SR),SR_UIF) == 0);
	CLR_BIT((MTIMER3 -> SR),SR_UIF);

	return;
}

u16 MTIMER3_PWM_PulseIn(u8 channel,u16 CNT_value)
{
	u16 value = 0;
	MTIMER3 -> ARR = CNT_value;
	switch(channel)
	{
		case MTIMER3_CH1_PORTA_6:
			while(!(GET_BIT((MTIMER3 -> SR),1) && GET_BIT((MTIMER3 -> SR),2)));
			CLR_BIT((MTIMER3 -> SR),1);
			CLR_BIT((MTIMER3 -> SR),2);
			value = ((MTIMER3 -> CCR2)-(MTIMER3 -> CCR1));
			return value;
			break;

		case MTIMER3_CH2_PORTA_7:
			while(GET_BIT((MTIMER3 -> SR),1) && GET_BIT((MTIMER3 -> SR),2));
			CLR_BIT((MTIMER3 -> SR),1);
			CLR_BIT((MTIMER3 -> SR),2);
			value = ((MTIMER3 -> CCR1)-(MTIMER3 -> CCR2));
			return value;
			break;

		case MTIMER3_CH3_PORTB_0:
			while(GET_BIT((MTIMER3 -> SR),3) && GET_BIT((MTIMER3 -> SR),4));
			CLR_BIT((MTIMER3 -> SR),3);
			CLR_BIT((MTIMER3 -> SR),4);
			value = ((MTIMER3 -> CCR3)-(MTIMER3 -> CCR4));
			return value;
			break;

		case MTIMER3_CH4_PORTB_1:
			while(GET_BIT((MTIMER3 -> SR),3) && GET_BIT((MTIMER3 -> SR),4));
			CLR_BIT((MTIMER3 -> SR),3);
			CLR_BIT((MTIMER3 -> SR),4);
			value = ((MTIMER3 -> CCR3)-(MTIMER3 -> CCR4));
			return value;
			break;

	}
	return value;
}
