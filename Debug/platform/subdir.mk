################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../platform/CCFileUtils.cpp \
../platform/CCGLView.cpp \
../platform/CCImage.cpp \
../platform/CCSAXParser.cpp \
../platform/CCThread.cpp 

OBJS += \
./platform/CCFileUtils.o \
./platform/CCGLView.o \
./platform/CCImage.o \
./platform/CCSAXParser.o \
./platform/CCThread.o 

CPP_DEPS += \
./platform/CCFileUtils.d \
./platform/CCGLView.d \
./platform/CCImage.d \
./platform/CCSAXParser.d \
./platform/CCThread.d 


# Each subdirectory must supply rules for building sources it contributes
platform/%.o: ../platform/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


