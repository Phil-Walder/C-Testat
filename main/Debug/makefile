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
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main

dependents:
	-cd /home/hsr/.workspace/Simplecalc/Debug && $(MAKE) all
	-cd /home/hsr/.workspace/pocketcalculator/Debug && $(MAKE) all
	-cd /home/hsr/.workspace/printLargeDigit/Debug && $(MAKE) all

# Tool invocations
main: $(OBJS) $(USER_OBJS) /home/hsr/.workspace/Simplecalc/Debug/libSimplecalc.a /home/hsr/.workspace/pocketcalculator/Debug/libpocketcalculator.a /home/hsr/.workspace/printLargeDigit/Debug/libprintLargeDigit.a
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L"/home/hsr/.workspace/printLargeDigit/Debug" -L"/home/hsr/.workspace/pocketcalculator/Debug" -L"/home/hsr/.workspace/Simplecalc/Debug" -o "main" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) main
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
/home/hsr/.workspace/Simplecalc/Debug/libSimplecalc.a:
/home/hsr/.workspace/pocketcalculator/Debug/libpocketcalculator.a:
/home/hsr/.workspace/printLargeDigit/Debug/libprintLargeDigit.a:

-include ../makefile.targets
