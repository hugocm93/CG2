################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../platform/winrt/CCApplication.cpp \
../platform/winrt/CCCommon.cpp \
../platform/winrt/CCDevice.cpp \
../platform/winrt/CCFileUtilsWinRT.cpp \
../platform/winrt/CCFreeTypeFont.cpp \
../platform/winrt/CCGLViewImpl-winrt.cpp \
../platform/winrt/CCGLViewImpl.cpp \
../platform/winrt/CCPThreadWinRT.cpp \
../platform/winrt/CCPrecompiledShaders.cpp \
../platform/winrt/CCStdC.cpp \
../platform/winrt/CCWinRTUtils.cpp \
../platform/winrt/InputEvent.cpp \
../platform/winrt/Keyboard-winrt.cpp \
../platform/winrt/WICImageLoader-winrt.cpp \
../platform/winrt/inet_ntop_winrt.cpp \
../platform/winrt/inet_pton_winrt.cpp \
../platform/winrt/pch.cpp \
../platform/winrt/sha1.cpp 

OBJS += \
./platform/winrt/CCApplication.o \
./platform/winrt/CCCommon.o \
./platform/winrt/CCDevice.o \
./platform/winrt/CCFileUtilsWinRT.o \
./platform/winrt/CCFreeTypeFont.o \
./platform/winrt/CCGLViewImpl-winrt.o \
./platform/winrt/CCGLViewImpl.o \
./platform/winrt/CCPThreadWinRT.o \
./platform/winrt/CCPrecompiledShaders.o \
./platform/winrt/CCStdC.o \
./platform/winrt/CCWinRTUtils.o \
./platform/winrt/InputEvent.o \
./platform/winrt/Keyboard-winrt.o \
./platform/winrt/WICImageLoader-winrt.o \
./platform/winrt/inet_ntop_winrt.o \
./platform/winrt/inet_pton_winrt.o \
./platform/winrt/pch.o \
./platform/winrt/sha1.o 

CPP_DEPS += \
./platform/winrt/CCApplication.d \
./platform/winrt/CCCommon.d \
./platform/winrt/CCDevice.d \
./platform/winrt/CCFileUtilsWinRT.d \
./platform/winrt/CCFreeTypeFont.d \
./platform/winrt/CCGLViewImpl-winrt.d \
./platform/winrt/CCGLViewImpl.d \
./platform/winrt/CCPThreadWinRT.d \
./platform/winrt/CCPrecompiledShaders.d \
./platform/winrt/CCStdC.d \
./platform/winrt/CCWinRTUtils.d \
./platform/winrt/InputEvent.d \
./platform/winrt/Keyboard-winrt.d \
./platform/winrt/WICImageLoader-winrt.d \
./platform/winrt/inet_ntop_winrt.d \
./platform/winrt/inet_pton_winrt.d \
./platform/winrt/pch.d \
./platform/winrt/sha1.d 


# Each subdirectory must supply rules for building sources it contributes
platform/winrt/%.o: ../platform/winrt/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


