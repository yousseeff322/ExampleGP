/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 2 sep 2024                 */
/* Version          : v01                        */
/*************************************************/

#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

/*TIMER2 Functions*/
void MTIMER2_init(u8 Copy_u8Delay_type);
void MTIMER2_delay_ms(u16 Copy_u16Value);
void MTIMER2_delay_us(u16 Copy_u16Value);


/*TIMER2 delay types*/
#define delay_ms   1
#define delay_us   2











#endif
