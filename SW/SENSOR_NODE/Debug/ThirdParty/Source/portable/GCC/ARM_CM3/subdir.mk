################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/Source/portable/GCC/ARM_CM3/port.c 

OBJS += \
./ThirdParty/Source/portable/GCC/ARM_CM3/port.o 

C_DEPS += \
./ThirdParty/Source/portable/GCC/ARM_CM3/port.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/Source/portable/GCC/ARM_CM3/%.o ThirdParty/Source/portable/GCC/ARM_CM3/%.su ThirdParty/Source/portable/GCC/ARM_CM3/%.cyclo: ../ThirdParty/Source/portable/GCC/ARM_CM3/%.c ThirdParty/Source/portable/GCC/ARM_CM3/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/Embedded System/STM_proj/MASTER_NODE/ThirdParty/Source/include" -I"D:/Embedded System/STM_proj/MASTER_NODE/ThirdParty/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ThirdParty-2f-Source-2f-portable-2f-GCC-2f-ARM_CM3

clean-ThirdParty-2f-Source-2f-portable-2f-GCC-2f-ARM_CM3:
	-$(RM) ./ThirdParty/Source/portable/GCC/ARM_CM3/port.cyclo ./ThirdParty/Source/portable/GCC/ARM_CM3/port.d ./ThirdParty/Source/portable/GCC/ARM_CM3/port.o ./ThirdParty/Source/portable/GCC/ARM_CM3/port.su

.PHONY: clean-ThirdParty-2f-Source-2f-portable-2f-GCC-2f-ARM_CM3

