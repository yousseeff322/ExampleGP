################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/Source/portable/MemMang/heap_4.c 

OBJS += \
./ThirdParty/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./ThirdParty/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/Source/portable/MemMang/%.o ThirdParty/Source/portable/MemMang/%.su ThirdParty/Source/portable/MemMang/%.cyclo: ../ThirdParty/Source/portable/MemMang/%.c ThirdParty/Source/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/Embedded System/STM_proj/MASTER_NODE/ThirdParty/Source/include" -I"D:/Embedded System/STM_proj/MASTER_NODE/ThirdParty/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ThirdParty-2f-Source-2f-portable-2f-MemMang

clean-ThirdParty-2f-Source-2f-portable-2f-MemMang:
	-$(RM) ./ThirdParty/Source/portable/MemMang/heap_4.cyclo ./ThirdParty/Source/portable/MemMang/heap_4.d ./ThirdParty/Source/portable/MemMang/heap_4.o ./ThirdParty/Source/portable/MemMang/heap_4.su

.PHONY: clean-ThirdParty-2f-Source-2f-portable-2f-MemMang

