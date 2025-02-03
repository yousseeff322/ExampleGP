#include "STD_type.h"
#include "BIT_math.h"

#include "TIMER3_interface.h"
#include "DIO_interface.h"

#include "MOTOR_interface.h"
#include "MOTOR_config.h"

// 🔹 Initialize motor driver
void MotorDriver_voidInit(void) {
    // Set pins as output
    MGPIO_VidSetPinDirection(MOTOR1_PIN, OUT_SPEED_2MHZ_PP);
    MGPIO_VidSetPinDirection(MOTOR2_PIN, OUT_SPEED_2MHZ_PP);
    MGPIO_VidSetPinDirection(MOTOR3_PIN, OUT_SPEED_2MHZ_PP);
    MGPIO_VidSetPinDirection(MOTOR4_PIN, OUT_SPEED_2MHZ_PP);

    MTIMER3_init(PWM_channel_1_us);
}

// 🔹 Control motor speed
void MotorDriver_voidControlSpeed(u8 DutyCycle) {
    if (DutyCycle > 100) DutyCycle = 100; // Ensure values between 0 and 100
    u16 pwm_value = (DutyCycle * 99) / 100;

    // Assign PWM values to Timer3 channels corresponding to motor pins
    MTIMER3_PWM(MTIMER3_CH1_PORTA_6, 100, pwm_value); // Motor 1
    MTIMER3_PWM(MTIMER3_CH2_PORTA_7, 100, pwm_value); // Motor 2
    MTIMER3_PWM(MTIMER3_CH3_PORTB_0, 100, pwm_value); // Motor 3
    MTIMER3_PWM(MTIMER3_CH4_PORTB_1, 100, pwm_value); // Motor 4
}

// 🔹 Stop motors
void MotorDriver_voidStop(void) {
	MGPIO_VidSetPinValue(MOTOR1_PIN, GPIO_LOW);
   MGPIO_VidSetPinValue(MOTOR2_PIN, GPIO_LOW);
   MGPIO_VidSetPinValue(MOTOR3_PIN, GPIO_LOW);
   MGPIO_VidSetPinValue(MOTOR4_PIN, GPIO_LOW);
}

// 🔹 Move forward
void MotorDriver_voidMoveForward(void) {
	MotorDriver_voidControlSpeed(100);
	MGPIO_VidSetPinValue(MOTOR1_PIN, GPIO_HIGH);
	MGPIO_VidSetPinValue(MOTOR2_PIN, GPIO_LOW);
	MGPIO_VidSetPinValue(MOTOR3_PIN, GPIO_HIGH);
	MGPIO_VidSetPinValue(MOTOR4_PIN, GPIO_LOW);
}

// 🔹 Move backward
void MotorDriver_voidMoveBackward(void) {
	MotorDriver_voidControlSpeed(100);
	MGPIO_VidSetPinValue(MOTOR1_PIN, GPIO_LOW);
	MGPIO_VidSetPinValue(MOTOR2_PIN, GPIO_HIGH);
	MGPIO_VidSetPinValue(MOTOR3_PIN, GPIO_LOW);
	MGPIO_VidSetPinValue(MOTOR4_PIN, GPIO_HIGH);
}

// 🔹 Move right
void MotorDriver_voidMoveRight(void) {
    MotorDriver_voidControlSpeed(100);
	MGPIO_VidSetPinValue(MOTOR1_PIN, GPIO_LOW);
	MGPIO_VidSetPinValue(MOTOR2_PIN, GPIO_HIGH);
	MGPIO_VidSetPinValue(MOTOR3_PIN, GPIO_HIGH);
	MGPIO_VidSetPinValue(MOTOR4_PIN, GPIO_LOW);
}

// 🔹 Move left
void MotorDriver_voidMoveLeft(void) {
    MotorDriver_voidControlSpeed(100);
	MGPIO_VidSetPinValue(MOTOR1_PIN, GPIO_HIGH);
	MGPIO_VidSetPinValue(MOTOR2_PIN, GPIO_LOW);
	MGPIO_VidSetPinValue(MOTOR3_PIN, GPIO_LOW);
	MGPIO_VidSetPinValue(MOTOR4_PIN, GPIO_HIGH);
}

// 🔹 Move diagonally left
void MotorDriver_voidMoveDiagonalLeft(void) {
    MotorDriver_voidControlSpeed(100);
	MGPIO_VidSetPinValue(MOTOR1_PIN, GPIO_HIGH);
	MGPIO_VidSetPinValue(MOTOR2_PIN, GPIO_LOW);
	MGPIO_VidSetPinValue(MOTOR3_PIN, GPIO_LOW);
	MGPIO_VidSetPinValue(MOTOR4_PIN, GPIO_LOW);
}

// 🔹 Move diagonally right
void MotorDriver_voidMoveDiagonalRight(void) {
    MotorDriver_voidControlSpeed(100);
	MGPIO_VidSetPinValue(MOTOR1_PIN, GPIO_LOW);
	MGPIO_VidSetPinValue(MOTOR2_PIN, GPIO_LOW);
	MGPIO_VidSetPinValue(MOTOR3_PIN, GPIO_HIGH);
	MGPIO_VidSetPinValue(MOTOR4_PIN, GPIO_LOW);
}
