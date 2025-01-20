/*********************************************************/
/* Author      : GP Team                                 */
/* Date        :                                         */
/* Version     : V01                                     */
/*********************************************************/
#include "STD_type.h"
#include "BIT_math.h"

#include "TIM_interface.h"
#include "DIO_interface.h"

#include "MOTOR_interface.h"
#include "MOTOR_config.h"


void MotorDriver_voidInit(void)
{
    sPWM_Confg_t PWM_Config;

    // Configure for TIM1 and start PWM on Channel 1 and Channel 2
    PWM_Config.TimerSelect = PWM_TIMER1;
    PWM_Config.Prescaler = 0;             // Set as needed for PWM frequency
    PWM_Config.AutoReloadReg = 99;        // Set ARR to maximum (e.g., 99 for 100 levels of PWM resolution)
    PWM_Config.CCR1_Status = CCR_ENABLE;  // Enable Channel 1 for Motor1 and Motor2
    PWM_Config.CCR2_Status = CCR_ENABLE;  // Enable Channel 2 for Motor3 and Motor4

    PWM_voidInit(&PWM_Config);
}

void MotorDriver_voidControlSpeed(u8 DutyCycle)
{
    // Update duty cycle for Motor1 + Motor2 (Channel 1) and Motor3 + Motor4 (Channel 2)
    PWM_voidUpdate(PWM_TIMER1, Channel_1, 99 - DutyCycle);
    PWM_voidUpdate(PWM_TIMER1, Channel_2, 99 - DutyCycle);
}


// Initialize Timer3 for PWM mode on channels 1 and 2
void MotorDriver_voidInit(void) {
    // Initialize Timer 3 in PWM mode for both channels, assuming up-counting mode and CCR registers for duty control
    MTIMER3_init(PWM_channel_1_us);

    // Set PWM on both channels 1 and 2, with CNT_value set to define PWM period
    MTIMER3_PWM(MTIMER3_CH1_PORTA_6, 100, 0);  // Initialize Motor1 + Motor2
    MTIMER3_PWM(MTIMER3_CH2_PORTA_7, 100, 0);  // Initialize Motor3 + Motor4
}

// Control speed by adjusting PWM duty cycle on channels 1 and 2
void MotorDriver_voidControlSpeed(u8 DutyCycle) {
    u16 pwm_value = 99 - DutyCycle;  // Adjust to fit the required range

    // Adjust duty cycle for channels 1 and 2
    MTIMER3_PWM(MTIMER3_CH1_PORTA_6, 100, pwm_value);  // Set duty for Motor1 + Motor2
    MTIMER3_PWM(MTIMER3_CH2_PORTA_7, 100, pwm_value);  // Set duty for Motor3 + Motor4
}


void MotorDriver_voidStop(void)
{
	MGPIO_VidSetPinValue(GPIOB, GPIO_PIN_12, GPIO_LOW); // Motor 1
	MGPIO_VidSetPinValue(GPIOB, GPIO_PIN_13, GPIO_LOW); // Motor 2
	MGPIO_VidSetPinValue(GPIOB, GPIO_PIN_14, GPIO_LOW); // Motor 3
	MGPIO_VidSetPinValue(GPIOB, GPIO_PIN_15, GPIO_LOW); // Motor 4
}

void MotorDriver_voidMoveForward(void)
{
	MGPIO_VidSetPinValue(MOTOR1_PIN, GPIO_HIGH);    // Motor 1
	MGPIO_VidSetPinValue(MOTOR2_PIN, GPIO_LOW);  	// Motor 2
	MGPIO_VidSetPinValue(MOTOR3_PIN, GPIO_HIGH);    // Motor 3
	MGPIO_VidSetPinValue(MOTOR4_PIN, GPIO_LOW);  	// Motor 4
}

void MotorDriver_voidMoveBackward(void)
{
	MGPIO_VidSetPinValue(MOTOR1_PIN, GPIO_LOW);   	// Motor 1
	MGPIO_VidSetPinValue(MOTOR2_PIN, GPIO_HIGH);     // Motor 2
	MGPIO_VidSetPinValue(MOTOR3_PIN, GPIO_LOW);   	// Motor 3
	MGPIO_VidSetPinValue(MOTOR4_PIN, GPIO_HIGH);     // Motor 4
}

void MotorDriver_voidMoveRight(void)
{
	MGPIO_VidSetPinValue(MOTOR1_PIN, GPIO_LOW);   // Motor 1
	MGPIO_VidSetPinValue(MOTOR2_PIN, GPIO_HIGH);   // Motor 2
	MGPIO_VidSetPinValue(MOTOR3_PIN, GPIO_HIGH);     // Motor 3
	MGPIO_VidSetPinValue(MOTOR4_PIN, GPIO_LOW);   // Motor 4
}

void MotorDriver_voidMoveLeft(void)
{
	MGPIO_VidSetPinValue(MOTOR1_PIN, GPIO_HIGH);      // Motor 1
	MGPIO_VidSetPinValue(MOTOR2_PIN, GPIO_LOW);  	 // Motor 2
	MGPIO_VidSetPinValue(MOTOR3_PIN, GPIO_LOW);   	// Motor 3
	MGPIO_VidSetPinValue(MOTOR4_PIN, GPIO_HIGH);   // Motor 4
}

