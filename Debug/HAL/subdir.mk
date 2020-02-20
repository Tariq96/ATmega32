################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/F90_RTC.c \
../HAL/F91_LCD.c \
../HAL/Keypad.c \
../HAL/LCD.c \
../HAL/LED.c \
../HAL/RTC.c \
../HAL/TEMP.c 

OBJS += \
./HAL/F90_RTC.o \
./HAL/F91_LCD.o \
./HAL/Keypad.o \
./HAL/LCD.o \
./HAL/LED.o \
./HAL/RTC.o \
./HAL/TEMP.o 

C_DEPS += \
./HAL/F90_RTC.d \
./HAL/F91_LCD.d \
./HAL/Keypad.d \
./HAL/LCD.d \
./HAL/LED.d \
./HAL/RTC.d \
./HAL/TEMP.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


