#include "STD_type.h"
#include "BIT_math.h"
#include "FunHelp.h"

#include "DIO_interface.h"
#include "TIMER2_interface.h"
#include "TIMER3_interface.h"

#include "HULTRA_interface.h"
#include "HULTRA_private.h"
#include "HULTRA_config.h"


void HULTRA_attachPin(u8 Copy_u8TrigPort,u8 Copy_u8TrigPIN,u8 Copy_u8Echo)
{
	MGPIO_VidSetPinDirection(Copy_u8TrigPort, Copy_u8TrigPIN, OUT_SPEED_2MHZ_PP) ;

	switch(Copy_u8Echo)
	{
		case MTIMER3_CH1_PORTA_6:
			MGPIO_VidSetPinDirection(GPIOA,PIN6,INPUT_FLOATING);
			break;

		case MTIMER3_CH2_PORTA_7:
			MGPIO_VidSetPinDirection(GPIOA,PIN7,INPUT_FLOATING);
			break;

		case MTIMER3_CH3_PORTB_0:
			MGPIO_VidSetPinDirection(GPIOB,PIN0,INPUT_FLOATING);
			break;

		case MTIMER3_CH4_PORTB_1:
			MGPIO_VidSetPinDirection(GPIOB,PIN1,INPUT_FLOATING);
			break;
	}
	return;
}

void HULTRA_Trig(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	MGPIO_VidSetPinValue(Copy_u8Port, Copy_u8Pin, HIGH);
	MTIMER2_delay_us(10);
	MGPIO_VidSetPinValue(Copy_u8Port, Copy_u8Pin, LOW);
	return;
}


u16 HULTRA_Distance(u8 Copy_u8Channel)
{
	u16 time = 0;

	switch(Copy_u8Channel)
	{
		case MTIMER3_CH1_PORTA_6:
			time = MTIMER3_PWM_PulseIn(MTIMER3_CH1_PORTA_6,38000);
			MTIMER2_delay_us(60000);
			return (u16)(0.034*(time/2));
			break;

		case MTIMER3_CH2_PORTA_7:
			time = MTIMER3_PWM_PulseIn(MTIMER3_CH2_PORTA_7,38000);
			return (u16)(0.034*(time/2));
			break;

		case MTIMER3_CH3_PORTB_0:
			time = MTIMER3_PWM_PulseIn(MTIMER3_CH3_PORTB_0,38000);
			return (u16)(0.034*(time/2));
			break;

		case MTIMER3_CH4_PORTB_1:
			time = MTIMER3_PWM_PulseIn(MTIMER3_CH4_PORTB_1,38000);
			return (u16)(0.034*(time/2));
			break;
	}

	return 0;
}
