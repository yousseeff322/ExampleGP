#include "STD_type.h"
#include "BIT_math.h"

#include"DIO_interface.h"

#include"IR_Interface.h"
#include"IR_Config.h"

void IR_Init(u8 IR_Dir)
{

	switch (IR_Dir)
	{
	case Left_IR:MGPIO_VidSetPinDirection(Left_IR_Connection,INPUT_PULL_UP_DOWN); break;
	case Right_IR:MGPIO_VidSetPinDirection(Right_IR_Connection,INPUT_PULL_UP_DOWN); break;

	}


}
u8 Left_IR_Measurement()
{

	return MGPIO_u8GetPinValue(Left_IR_Connection);
}

u8 Right_IR_Measurment()
{
	return MGPIO_u8GetPinValue(Right_IR_Connection) ;
}
