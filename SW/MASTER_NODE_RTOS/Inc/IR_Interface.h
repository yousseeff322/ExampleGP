/*
 * IR_Interface.h
 *
 *  Created on: Jan 27, 2025
 *      Author: 20109
 */

#ifndef INC_HAL_IR_INTERFACE_H_
#define INC_HAL_IR_INTERFACE_H_


//Sender //Receiver
#define White 1
#define Black 0

#define Left_IR 0
#define Right_IR 1

//Connection of IR
void IR_Init(u8 IR_Dir);

u8 Left_IR_Measurement();

u8 Right_IR_Measurment();



#endif /* INC_HAL_IR_INTERFACE_H_ */
