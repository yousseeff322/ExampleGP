################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/Source/croutine.c \
../ThirdParty/Source/event_groups.c \
../ThirdParty/Source/list.c \
../ThirdParty/Source/queue.c \
../ThirdParty/Source/stream_buffer.c \
../ThirdParty/Source/tasks.c \
../ThirdParty/Source/timers.c 

OBJS += \
./ThirdParty/Source/croutine.o \
./ThirdParty/Source/event_groups.o \
./ThirdParty/Source/list.o \
./ThirdParty/Source/queue.o \
./ThirdParty/Source/stream_buffer.o \
./ThirdParty/Source/tasks.o \
./ThirdParty/Source/timers.o 

C_DEPS += \
./ThirdParty/Source/croutine.d \
./ThirdParty/Source/event_groups.d \
./ThirdParty/Source/list.d \
./ThirdParty/Source/queue.d \
./ThirdParty/Source/stream_buffer.d \
./ThirdParty/Source/tasks.d \
./ThirdParty/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/Source/%.o ThirdParty/Source/%.su ThirdParty/Source/%.cyclo: ../ThirdParty/Source/%.c ThirdParty/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/Embedded System/STM_proj/MASTER_NODE_RTOS/ThirdParty/Source/include" -I"D:/Embedded System/STM_proj/MASTER_NODE_RTOS/ThirdParty/Source/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ThirdParty-2f-Source

clean-ThirdParty-2f-Source:
	-$(RM) ./ThirdParty/Source/croutine.cyclo ./ThirdParty/Source/croutine.d ./ThirdParty/Source/croutine.o ./ThirdParty/Source/croutine.su ./ThirdParty/Source/event_groups.cyclo ./ThirdParty/Source/event_groups.d ./ThirdParty/Source/event_groups.o ./ThirdParty/Source/event_groups.su ./ThirdParty/Source/list.cyclo ./ThirdParty/Source/list.d ./ThirdParty/Source/list.o ./ThirdParty/Source/list.su ./ThirdParty/Source/queue.cyclo ./ThirdParty/Source/queue.d ./ThirdParty/Source/queue.o ./ThirdParty/Source/queue.su ./ThirdParty/Source/stream_buffer.cyclo ./ThirdParty/Source/stream_buffer.d ./ThirdParty/Source/stream_buffer.o ./ThirdParty/Source/stream_buffer.su ./ThirdParty/Source/tasks.cyclo ./ThirdParty/Source/tasks.d ./ThirdParty/Source/tasks.o ./ThirdParty/Source/tasks.su ./ThirdParty/Source/timers.cyclo ./ThirdParty/Source/timers.d ./ThirdParty/Source/timers.o ./ThirdParty/Source/timers.su

.PHONY: clean-ThirdParty-2f-Source

