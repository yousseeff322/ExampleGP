/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 8 MAR 2024                 */
/* Version          : v01                        */ 
/*************************************************/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_



#define NO_SUB_PRIORITY 0



#define MNVIC_GROUP_4_SUB_0      0x05FA0300
#define MNVIC_GROUP_3_SUB_1      0x05FA0400
#define MNVIC_GROUP_2_SUB_2      0x05FA0500
#define MNVIC_GROUP_1_SUB_3      0x05FA0600
#define MNVIC_GROUP_0_SUB_4      0x05FA0700



void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
u8	 MNVIC_u8GetActiveFlag        (u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority(u8 Copy_PeripheralIdx, u8 Copy_u8Priority);
void MNVIC_voidInit(void);







#endif
