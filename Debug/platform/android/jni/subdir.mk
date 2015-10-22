################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../platform/android/jni/CocosPlayClient.cpp \
../platform/android/jni/DPIJni.cpp \
../platform/android/jni/IMEJni.cpp \
../platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxAccelerometer.cpp \
../platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxBitmap.cpp \
../platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxHelper.cpp \
../platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxRenderer.cpp \
../platform/android/jni/JniHelper.cpp \
../platform/android/jni/TouchesJni.cpp 

OBJS += \
./platform/android/jni/CocosPlayClient.o \
./platform/android/jni/DPIJni.o \
./platform/android/jni/IMEJni.o \
./platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxAccelerometer.o \
./platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxBitmap.o \
./platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxHelper.o \
./platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxRenderer.o \
./platform/android/jni/JniHelper.o \
./platform/android/jni/TouchesJni.o 

CPP_DEPS += \
./platform/android/jni/CocosPlayClient.d \
./platform/android/jni/DPIJni.d \
./platform/android/jni/IMEJni.d \
./platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxAccelerometer.d \
./platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxBitmap.d \
./platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxHelper.d \
./platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxRenderer.d \
./platform/android/jni/JniHelper.d \
./platform/android/jni/TouchesJni.d 


# Each subdirectory must supply rules for building sources it contributes
platform/android/jni/%.o: ../platform/android/jni/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


