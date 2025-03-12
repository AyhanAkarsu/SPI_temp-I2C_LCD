################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../helper/Src/helper.c 

OBJS += \
./helper/Src/helper.o 

C_DEPS += \
./helper/Src/helper.d 


# Each subdirectory must supply rules for building sources it contributes
helper/Src/%.o helper/Src/%.su: ../helper/Src/%.c helper/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ayhan/STM32CubeIDE/workspace_1.10.1/I2C_lcd_SPI_Temp/Drivers/MyDrivers/I2C_Init/Inc" -I"C:/Users/Ayhan/STM32CubeIDE/workspace_1.10.1/I2C_lcd_SPI_Temp/Drivers/MyDrivers/SPI_Init/Inc" -I"C:/Users/Ayhan/STM32CubeIDE/workspace_1.10.1/I2C_lcd_SPI_Temp/Aplication/Inc" -I"C:/Users/Ayhan/STM32CubeIDE/workspace_1.10.1/I2C_lcd_SPI_Temp/helper/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-helper-2f-Src

clean-helper-2f-Src:
	-$(RM) ./helper/Src/helper.d ./helper/Src/helper.o ./helper/Src/helper.su

.PHONY: clean-helper-2f-Src

