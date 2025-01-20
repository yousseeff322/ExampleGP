/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 2 sep 2024                 */
/* Version          : v01                        */
/*************************************************/


#ifndef HULTRA_INTERFACE_H_
#define HULTRA_INTERFACE_H_



/*Ultra-Sonic functions*/
void HULTRA_attachPin(u8 Copy_u8TrigPort,u8 Copy_u8TrigPIN,u8 Copy_u8Echo) ;
void HULTRA_Trig(u8 Copy_u8Port,u8 Copy_u8Pin) ;
u16 HULTRA_Distance(u8 Copy_u8Channel);








#endif
