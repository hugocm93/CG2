################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../platform/win32/CCApplication-win32.cpp \
../platform/win32/CCCommon-win32.cpp \
../platform/win32/CCDevice-win32.cpp \
../platform/win32/CCFileUtils-win32.cpp \
../platform/win32/CCStdC-win32.cpp \
../platform/win32/inet_pton_mingw.cpp 

OBJS += \
./platform/win32/CCApplication-win32.o \
./platform/win32/CCCommon-win32.o \
./platform/win32/CCDevice-win32.o \
./platform/win32/CCFileUtils-win32.o \
./platform/win32/CCStdC-win32.o \
./platform/win32/inet_pton_mingw.o 

CPP_DEPS += \
./platform/win32/CCApplication-win32.d \
./platform/win32/CCCommon-win32.d \
./platform/win32/CCDevice-win32.d \
./platform/win32/CCFileUtils-win32.d \
./platform/win32/CCStdC-win32.d \
./platform/win32/inet_pton_mingw.d 


# Each subdirectory must supply rules for building sources it contributes
platform/win32/%.o: ../platform/win32/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


