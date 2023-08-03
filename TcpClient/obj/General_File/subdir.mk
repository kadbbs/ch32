################################################################################
# MRS Version: {"version":"1.8.5","date":"2023/05/22"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../General_File/system.c 

OBJS += \
./General_File/system.o 

C_DEPS += \
./General_File/system.d 


# Each subdirectory must supply rules for building sources it contributes
General_File/%.o: ../General_File/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\ch32\data\CH32V307EVT\EVT\EXAM\ETH\NetLib" -I"C:\ch32\data\CH32V307EVT\EVT\EXAM\SRC\Core" -I"C:\ch32\data\CH32V307EVT\EVT\EXAM\SRC\Debug" -I"C:\ch32\data\CH32V307EVT\EVT\EXAM\SRC\Peripheral\inc" -I"C:\ch32\data\CH32V307EVT\EVT\EXAM\ETH\TcpClient\User" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

