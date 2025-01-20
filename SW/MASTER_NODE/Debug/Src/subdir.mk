################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC_program.c \
../Src/AFIO_program.c \
../Src/DIO_program.c \
../Src/EXTI_program.c \
../Src/FunHelp.c \
../Src/HULTRA_program.c \
../Src/LDR_program.c \
../Src/LM35_program.c \
../Src/MOTOR_program.c \
../Src/NVIC_program.c \
../Src/RCC_program.c \
../Src/TIMER2_program.c \
../Src/TIMER3_program.c \
../Src/TIM_program.c \
../Src/main.c \
../Src/syscalls.c 

OBJS += \
./Src/ADC_program.o \
./Src/AFIO_program.o \
./Src/DIO_program.o \
./Src/EXTI_program.o \
./Src/FunHelp.o \
./Src/HULTRA_program.o \
./Src/LDR_program.o \
./Src/LM35_program.o \
./Src/MOTOR_program.o \
./Src/NVIC_program.o \
./Src/RCC_program.o \
./Src/TIMER2_program.o \
./Src/TIMER3_program.o \
./Src/TIM_program.o \
./Src/main.o \
./Src/syscalls.o 

C_DEPS += \
./Src/ADC_program.d \
./Src/AFIO_program.d \
./Src/DIO_program.d \
./Src/EXTI_program.d \
./Src/FunHelp.d \
./Src/HULTRA_program.d \
./Src/LDR_program.d \
./Src/LM35_program.d \
./Src/MOTOR_program.d \
./Src/NVIC_program.d \
./Src/RCC_program.d \
./Src/TIMER2_program.d \
./Src/TIMER3_program.d \
./Src/TIM_program.d \
./Src/main.d \
./Src/syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/Embedded System/STM_proj/MASTER_NODE/ThirdParty/Source/include" -I"D:/Embedded System/STM_proj/MASTER_NODE/ThirdParty/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/ADC_program.cyclo ./Src/ADC_program.d ./Src/ADC_program.o ./Src/ADC_program.su ./Src/AFIO_program.cyclo ./Src/AFIO_program.d ./Src/AFIO_program.o ./Src/AFIO_program.su ./Src/DIO_program.cyclo ./Src/DIO_program.d ./Src/DIO_program.o ./Src/DIO_program.su ./Src/EXTI_program.cyclo ./Src/EXTI_program.d ./Src/EXTI_program.o ./Src/EXTI_program.su ./Src/FunHelp.cyclo ./Src/FunHelp.d ./Src/FunHelp.o ./Src/FunHelp.su ./Src/HULTRA_program.cyclo ./Src/HULTRA_program.d ./Src/HULTRA_program.o ./Src/HULTRA_program.su ./Src/LDR_program.cyclo ./Src/LDR_program.d ./Src/LDR_program.o ./Src/LDR_program.su ./Src/LM35_program.cyclo ./Src/LM35_program.d ./Src/LM35_program.o ./Src/LM35_program.su ./Src/MOTOR_program.cyclo ./Src/MOTOR_program.d ./Src/MOTOR_program.o ./Src/MOTOR_program.su ./Src/NVIC_program.cyclo ./Src/NVIC_program.d ./Src/NVIC_program.o ./Src/NVIC_program.su ./Src/RCC_program.cyclo ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/TIMER2_program.cyclo ./Src/TIMER2_program.d ./Src/TIMER2_program.o ./Src/TIMER2_program.su ./Src/TIMER3_program.cyclo ./Src/TIMER3_program.d ./Src/TIMER3_program.o ./Src/TIMER3_program.su ./Src/TIM_program.cyclo ./Src/TIM_program.d ./Src/TIM_program.o ./Src/TIM_program.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su

.PHONY: clean-Src

