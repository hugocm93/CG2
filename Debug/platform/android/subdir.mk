################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../platform/android/CCApplication-android.cpp \
../platform/android/CCCommon-android.cpp \
../platform/android/CCDevice-android.cpp \
../platform/android/CCEnhanceAPI-android.cpp \
../platform/android/CCFileUtils-android.cpp \
../platform/android/CCGLViewImpl-android.cpp \
../platform/android/javaactivity-android.cpp 

OBJS += \
./platform/android/CCApplication-android.o \
./platform/android/CCCommon-android.o \
./platform/android/CCDevice-android.o \
./platform/android/CCEnhanceAPI-android.o \
./platform/android/CCFileUtils-android.o \
./platform/android/CCGLViewImpl-android.o \
./platform/android/javaactivity-android.o 

CPP_DEPS += \
./platform/android/CCApplication-android.d \
./platform/android/CCCommon-android.d \
./platform/android/CCDevice-android.d \
./platform/android/CCEnhanceAPI-android.d \
./platform/android/CCFileUtils-android.d \
./platform/android/CCGLViewImpl-android.d \
./platform/android/javaactivity-android.d 


# Each subdirectory must supply rules for building sources it contributes
platform/android/%.o: ../platform/android/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


