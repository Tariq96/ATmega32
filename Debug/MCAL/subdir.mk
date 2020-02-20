################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO.c \
../MCAL/F90_ADC.c \
../MCAL/F90_DIO.c \
../MCAL/F90_I2C.c \
../MCAL/F90_PWM.c \
../MCAL/F90_SPI.c \
../MCAL/F90_TIMER_0.c \
../MCAL/F90_UART2.c 

OBJS += \
./MCAL/DIO.o \
./MCAL/F90_ADC.o \
./MCAL/F90_DIO.o \
./MCAL/F90_I2C.o \
./MCAL/F90_PWM.o \
./MCAL/F90_SPI.o \
./MCAL/F90_TIMER_0.o \
./MCAL/F90_UART2.o 

C_DEPS += \
./MCAL/DIO.d \
./MCAL/F90_ADC.d \
./MCAL/F90_DIO.d \
./MCAL/F90_I2C.d \
./MCAL/F90_PWM.d \
./MCAL/F90_SPI.d \
./MCAL/F90_TIMER_0.d \
./MCAL/F90_UART2.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


