################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC_program.c \
../Src/AFIO_program.c \
../Src/CAN_program.c \
../Src/DIO_program.c \
../Src/HULTRA_program.c \
../Src/IR_Program.c \
../Src/LDR_program.c \
../Src/NVIC_program.c \
../Src/RCC_program.c \
../Src/SYSTICK_program.c \
../Src/TIMER2_program.c \
../Src/TIMER3_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/ADC_program.o \
./Src/AFIO_program.o \
./Src/CAN_program.o \
./Src/DIO_program.o \
./Src/HULTRA_program.o \
./Src/IR_Program.o \
./Src/LDR_program.o \
./Src/NVIC_program.o \
./Src/RCC_program.o \
./Src/SYSTICK_program.o \
./Src/TIMER2_program.o \
./Src/TIMER3_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/ADC_program.d \
./Src/AFIO_program.d \
./Src/CAN_program.d \
./Src/DIO_program.d \
./Src/HULTRA_program.d \
./Src/IR_Program.d \
./Src/LDR_program.d \
./Src/NVIC_program.d \
./Src/RCC_program.d \
./Src/SYSTICK_program.d \
./Src/TIMER2_program.d \
./Src/TIMER3_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/Embedded System/STM_proj/MASTER_NODE/ThirdParty/Source/include" -I"D:/Embedded System/STM_proj/MASTER_NODE/ThirdParty/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/ADC_program.cyclo ./Src/ADC_program.d ./Src/ADC_program.o ./Src/ADC_program.su ./Src/AFIO_program.cyclo ./Src/AFIO_program.d ./Src/AFIO_program.o ./Src/AFIO_program.su ./Src/CAN_program.cyclo ./Src/CAN_program.d ./Src/CAN_program.o ./Src/CAN_program.su ./Src/DIO_program.cyclo ./Src/DIO_program.d ./Src/DIO_program.o ./Src/DIO_program.su ./Src/HULTRA_program.cyclo ./Src/HULTRA_program.d ./Src/HULTRA_program.o ./Src/HULTRA_program.su ./Src/IR_Program.cyclo ./Src/IR_Program.d ./Src/IR_Program.o ./Src/IR_Program.su ./Src/LDR_program.cyclo ./Src/LDR_program.d ./Src/LDR_program.o ./Src/LDR_program.su ./Src/NVIC_program.cyclo ./Src/NVIC_program.d ./Src/NVIC_program.o ./Src/NVIC_program.su ./Src/RCC_program.cyclo ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/SYSTICK_program.cyclo ./Src/SYSTICK_program.d ./Src/SYSTICK_program.o ./Src/SYSTICK_program.su ./Src/TIMER2_program.cyclo ./Src/TIMER2_program.d ./Src/TIMER2_program.o ./Src/TIMER2_program.su ./Src/TIMER3_program.cyclo ./Src/TIMER3_program.d ./Src/TIMER3_program.o ./Src/TIMER3_program.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

