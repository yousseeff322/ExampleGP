/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 2 sep 2024                 */
/* Version          : v01                        */
/*************************************************/


#ifndef TIMER3_PRIVATE_H_
#define TIMER3_PRIVATE_H_




#define CR1_CEN  0
#define SR_UIF   0
#define EGR_UG   0


#define MTIMER3  ((volatile TIMER3*)(0x40000400))
typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SMCR;
	u32 DIER;
	u32 SR;
	u32 EGR;
	u32 CCMR1;
	u32 CCMR2;
	u32 CCER;
	u32 CNT;
	u32 PSC;
	u32 ARR;
	u32 RES1;
	u32 CCR1;
	u32 CCR2;
	u32 CCR3;
	u32 CCR4;
	u32 RES2;
	u32 DCR;
	u32 DMAR;
}TIMER3;












#endif
