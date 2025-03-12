################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Aplication/Src/Aplication.c 

OBJS += \
./Aplication/Src/Aplication.o 

C_DEPS += \
./Aplication/Src/Aplication.d 


# Each subdirectory must supply rules for building sources it contributes
Aplication/Src/%.o Aplication/Src/%.su: ../Aplication/Src/%.c Aplication/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ayhan/STM32CubeIDE/workspace_1.10.1/I2C_lcd_SPI_Temp/Drivers/MyDrivers/I2C_Init/Inc" -I"C:/Users/Ayhan/STM32CubeIDE/workspace_1.10.1/I2C_lcd_SPI_Temp/Drivers/MyDrivers/SPI_Init/Inc" -I"C:/Users/Ayhan/STM32CubeIDE/workspace_1.10.1/I2C_lcd_SPI_Temp/Aplication/Inc" -I"C:/Users/Ayhan/STM32CubeIDE/workspace_1.10.1/I2C_lcd_SPI_Temp/helper/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Aplication-2f-Src

clean-Aplication-2f-Src:
	-$(RM) ./Aplication/Src/Aplication.d ./Aplication/Src/Aplication.o ./Aplication/Src/Aplication.su

.PHONY: clean-Aplication-2f-Src

