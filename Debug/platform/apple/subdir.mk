################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../platform/apple/CCLock-apple.cpp 

OBJS += \
./platform/apple/CCLock-apple.o 

CPP_DEPS += \
./platform/apple/CCLock-apple.d 


# Each subdirectory must supply rules for building sources it contributes
platform/apple/%.o: ../platform/apple/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


