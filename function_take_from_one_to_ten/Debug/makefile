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
function_take_from_one_to_ten.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: function_take_from_one_to_ten.elf secondary-outputs

# Tool invocations
function_take_from_one_to_ten.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,function_take_from_one_to_ten.map -mmcu=atmega16 -o "function_take_from_one_to_ten.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

function_take_from_one_to_ten.lss: function_take_from_one_to_ten.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S function_take_from_one_to_ten.elf  >"function_take_from_one_to_ten.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: function_take_from_one_to_ten.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 function_take_from_one_to_ten.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) function_take_from_one_to_ten.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
