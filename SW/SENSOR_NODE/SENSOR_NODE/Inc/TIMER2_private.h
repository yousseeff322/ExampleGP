/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 2 sep 2024                 */
/* Version          : v01                        */
/*************************************************/

#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_


#define CR1_CEN  0
#define SR_UIF   0
#define EGR_UG   0


#define MTIMER2  ((volatile TIMER2*)(0x40000000))
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
}TIMER2;














#endif
