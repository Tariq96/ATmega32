################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC.c \
../MCAL/DIO.c \
../MCAL/F90_I2C.c \
../MCAL/F90_SPI.c \
../MCAL/F90_UART2.c \
../MCAL/TIMER.c 

OBJS += \
./MCAL/ADC.o \
./MCAL/DIO.o \
./MCAL/F90_I2C.o \
./MCAL/F90_SPI.o \
./MCAL/F90_UART2.o \
./MCAL/TIMER.o 

C_DEPS += \
./MCAL/ADC.d \
./MCAL/DIO.d \
./MCAL/F90_I2C.d \
./MCAL/F90_SPI.d \
./MCAL/F90_UART2.d \
./MCAL/TIMER.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


