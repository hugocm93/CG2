################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../platform/win8.1-universal/Cocos2dRenderer.cpp \
../platform/win8.1-universal/OpenGLES.cpp \
../platform/win8.1-universal/OpenGLESPage.xaml.cpp \
../platform/win8.1-universal/pch.cpp 

OBJS += \
./platform/win8.1-universal/Cocos2dRenderer.o \
./platform/win8.1-universal/OpenGLES.o \
./platform/win8.1-universal/OpenGLESPage.xaml.o \
./platform/win8.1-universal/pch.o 

CPP_DEPS += \
./platform/win8.1-universal/Cocos2dRenderer.d \
./platform/win8.1-universal/OpenGLES.d \
./platform/win8.1-universal/OpenGLESPage.xaml.d \
./platform/win8.1-universal/pch.d 


# Each subdirectory must supply rules for building sources it contributes
platform/win8.1-universal/%.o: ../platform/win8.1-universal/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


