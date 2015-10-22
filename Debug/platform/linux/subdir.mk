################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../platform/linux/CCApplication-linux.cpp \
../platform/linux/CCCommon-linux.cpp \
../platform/linux/CCDevice-linux.cpp \
../platform/linux/CCFileUtils-linux.cpp \
../platform/linux/CCStdC-linux.cpp 

OBJS += \
./platform/linux/CCApplication-linux.o \
./platform/linux/CCCommon-linux.o \
./platform/linux/CCDevice-linux.o \
./platform/linux/CCFileUtils-linux.o \
./platform/linux/CCStdC-linux.o 

CPP_DEPS += \
./platform/linux/CCApplication-linux.d \
./platform/linux/CCCommon-linux.d \
./platform/linux/CCDevice-linux.d \
./platform/linux/CCFileUtils-linux.d \
./platform/linux/CCStdC-linux.d 


# Each subdirectory must supply rules for building sources it contributes
platform/linux/%.o: ../platform/linux/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


