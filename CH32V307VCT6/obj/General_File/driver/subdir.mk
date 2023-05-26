################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../General_File/driver/font.c \
../General_File/driver/st7789.c 

OBJS += \
./General_File/driver/font.o \
./General_File/driver/st7789.o 

C_DEPS += \
./General_File/driver/font.d \
./General_File/driver/st7789.d 


# Each subdirectory must supply rules for building sources it contributes
General_File/driver/%.o: ../General_File/driver/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V307VCT6\Debug" -I"C:\MRS_DATA\workspace\CH32V307VCT6\Core" -I"C:\MRS_DATA\workspace\CH32V307VCT6\User" -I"C:\MRS_DATA\workspace\CH32V307VCT6\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

