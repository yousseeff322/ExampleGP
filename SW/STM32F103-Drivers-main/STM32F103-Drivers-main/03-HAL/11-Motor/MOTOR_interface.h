/*********************************************************/
/* Author      : GP Team                                 */
/* Date        :                                         */
/* Version     : V01                                     */
/*********************************************************/


#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_



void MotorDriver_voidInit(void);

void MotorDriver_voidControlSpeed(u8 DutyCycle);

void MotorDriver_voidMoveForward(void);

void MotorDriver_voidMoveBackward(void);

void MotorDriver_voidMoveRight(void);

void MotorDriver_voidMoveLeft(void);


void MotorDriver_voidStop(void);


#endif 
