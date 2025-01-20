#include "STD_type.h"
#include "BIT_math.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"

#include "STP_interface.h"


void main(void)
{
	/*Clock Initialization */
	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock(RCC_APB2,2);

	/* Pin Direction*/
	MGPIO_VidSetPinDirection(GPIOA,0,0b0010);
	MGPIO_VidSetPinDirection(GPIOA,1,0b0010);
	MGPIO_VidSetPinDirection(GPIOA,2,0b0010);

	/* Timer Init*/
	MSTK_voidInit();

	u8 i;
	while(1)
	{
        for(i=0;i<8;i++)
        {
        	HSTP_voidSendSynchronus(1<<i);
        	MSTK_voidSetBusyWait(300000);
        }
	}
}



