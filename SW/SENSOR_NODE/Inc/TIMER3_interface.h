/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 2 sep 2024                 */
/* Version          : v01                        */
/*************************************************/


#ifndef TIMER3_INTERFACE_H_
#define TIMER3_INTERFACE_H_


/*TIMER3 delay types*/
#define delay_ms     		      1
#define delay_us     		      2

/*PWM Mode*/
#define PWM_channel_1_us          3

/*PWM Period & Duty Cycle Measurement on channel 1 by two registers CCR1 & CCR2*/
#define PWM_channel_1_IN          4



/*TIMER3 I/O capture/compare channels*/
#define MTIMER3_CH1_PORTA_6  0
#define MTIMER3_CH2_PORTA_7  1
#define MTIMER3_CH3_PORTB_0  2
#define MTIMER3_CH4_PORTB_1  3



/*TIMER3 Functions*/
void MTIMER3_init(u8 mode);
void MTIMER3_delay_ms(u16 value);
void MTIMER3_delay_us(u16 value);
void MTIMER3_PWM(u8 channel,u16 CNT_value,u16 PWM_value);
u16 MTIMER3_PWM_PulseIn(u8 channel,u16 CNT_value);




#endif
