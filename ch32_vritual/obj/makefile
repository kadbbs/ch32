################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include General_File/driver/subdir.mk
-include General_File/subdir.mk
-include Debug/subdir.mk
-include Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
ch32_vritual.hex \

SECONDARY_LIST += \
ch32_vritual.lst \

SECONDARY_SIZE += \
ch32_vritual.siz \


# 所有目标
all: ch32_vritual.elf secondary-outputs

# 工具调用
ch32_vritual.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "C:\MRS_DATA\workspace\ch32_vritual\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"ch32_vritual.map" --specs=nano.specs --specs=nosys.specs -o "ch32_vritual.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
ch32_vritual.hex: ch32_vritual.elf
	@	riscv-none-embed-objcopy -O ihex "ch32_vritual.elf"  "ch32_vritual.hex"
	@	@
ch32_vritual.lst: ch32_vritual.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "ch32_vritual.elf" > "ch32_vritual.lst"
	@	@
ch32_vritual.siz: ch32_vritual.elf
	@	riscv-none-embed-size --format=berkeley "ch32_vritual.elf"
	@	@
# 其他目标
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) ch32_vritual.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
