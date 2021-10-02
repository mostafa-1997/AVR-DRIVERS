################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
LSS += \
Switch_Driver_PrebuildConfiguration.lss \

FLASH_IMAGE += \
Switch_Driver_PrebuildConfiguration.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Switch_Driver_PrebuildConfiguration.elf secondary-outputs

# Tool invocations
Switch_Driver_PrebuildConfiguration.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Switch_Driver_PrebuildConfiguration.map -mmcu=atmega32 -o "Switch_Driver_PrebuildConfiguration.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Switch_Driver_PrebuildConfiguration.lss: Switch_Driver_PrebuildConfiguration.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Switch_Driver_PrebuildConfiguration.elf  >"Switch_Driver_PrebuildConfiguration.lss"
	@echo 'Finished building: $@'
	@echo ' '

Switch_Driver_PrebuildConfiguration.hex: Switch_Driver_PrebuildConfiguration.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Switch_Driver_PrebuildConfiguration.elf  "Switch_Driver_PrebuildConfiguration.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Switch_Driver_PrebuildConfiguration.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Switch_Driver_PrebuildConfiguration.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Switch_Driver_PrebuildConfiguration.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
