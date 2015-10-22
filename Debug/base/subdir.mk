################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../base/CCAsyncTaskPool.cpp \
../base/CCAutoreleasePool.cpp \
../base/CCConfiguration.cpp \
../base/CCConsole.cpp \
../base/CCController-android.cpp \
../base/CCController.cpp \
../base/CCData.cpp \
../base/CCDataVisitor.cpp \
../base/CCDirector.cpp \
../base/CCEvent.cpp \
../base/CCEventAcceleration.cpp \
../base/CCEventController.cpp \
../base/CCEventCustom.cpp \
../base/CCEventDispatcher.cpp \
../base/CCEventFocus.cpp \
../base/CCEventKeyboard.cpp \
../base/CCEventListener.cpp \
../base/CCEventListenerAcceleration.cpp \
../base/CCEventListenerController.cpp \
../base/CCEventListenerCustom.cpp \
../base/CCEventListenerFocus.cpp \
../base/CCEventListenerKeyboard.cpp \
../base/CCEventListenerMouse.cpp \
../base/CCEventListenerTouch.cpp \
../base/CCEventMouse.cpp \
../base/CCEventTouch.cpp \
../base/CCIMEDispatcher.cpp \
../base/CCNS.cpp \
../base/CCNinePatchImageParser.cpp \
../base/CCProfiling.cpp \
../base/CCProperties.cpp \
../base/CCRef.cpp \
../base/CCScheduler.cpp \
../base/CCScriptSupport.cpp \
../base/CCTouch.cpp \
../base/CCUserDefault-android.cpp \
../base/CCUserDefault-winrt.cpp \
../base/CCUserDefault.cpp \
../base/CCValue.cpp \
../base/ObjectFactory.cpp \
../base/TGAlib.cpp \
../base/ZipUtils.cpp \
../base/atitc.cpp \
../base/base64.cpp \
../base/ccCArray.cpp \
../base/ccRandom.cpp \
../base/ccTypes.cpp \
../base/ccUTF8.cpp \
../base/ccUtils.cpp \
../base/etc1.cpp \
../base/pvr.cpp \
../base/s3tc.cpp 

C_SRCS += \
../base/ccFPSImages.c 

OBJS += \
./base/CCAsyncTaskPool.o \
./base/CCAutoreleasePool.o \
./base/CCConfiguration.o \
./base/CCConsole.o \
./base/CCController-android.o \
./base/CCController.o \
./base/CCData.o \
./base/CCDataVisitor.o \
./base/CCDirector.o \
./base/CCEvent.o \
./base/CCEventAcceleration.o \
./base/CCEventController.o \
./base/CCEventCustom.o \
./base/CCEventDispatcher.o \
./base/CCEventFocus.o \
./base/CCEventKeyboard.o \
./base/CCEventListener.o \
./base/CCEventListenerAcceleration.o \
./base/CCEventListenerController.o \
./base/CCEventListenerCustom.o \
./base/CCEventListenerFocus.o \
./base/CCEventListenerKeyboard.o \
./base/CCEventListenerMouse.o \
./base/CCEventListenerTouch.o \
./base/CCEventMouse.o \
./base/CCEventTouch.o \
./base/CCIMEDispatcher.o \
./base/CCNS.o \
./base/CCNinePatchImageParser.o \
./base/CCProfiling.o \
./base/CCProperties.o \
./base/CCRef.o \
./base/CCScheduler.o \
./base/CCScriptSupport.o \
./base/CCTouch.o \
./base/CCUserDefault-android.o \
./base/CCUserDefault-winrt.o \
./base/CCUserDefault.o \
./base/CCValue.o \
./base/ObjectFactory.o \
./base/TGAlib.o \
./base/ZipUtils.o \
./base/atitc.o \
./base/base64.o \
./base/ccCArray.o \
./base/ccFPSImages.o \
./base/ccRandom.o \
./base/ccTypes.o \
./base/ccUTF8.o \
./base/ccUtils.o \
./base/etc1.o \
./base/pvr.o \
./base/s3tc.o 

C_DEPS += \
./base/ccFPSImages.d 

CPP_DEPS += \
./base/CCAsyncTaskPool.d \
./base/CCAutoreleasePool.d \
./base/CCConfiguration.d \
./base/CCConsole.d \
./base/CCController-android.d \
./base/CCController.d \
./base/CCData.d \
./base/CCDataVisitor.d \
./base/CCDirector.d \
./base/CCEvent.d \
./base/CCEventAcceleration.d \
./base/CCEventController.d \
./base/CCEventCustom.d \
./base/CCEventDispatcher.d \
./base/CCEventFocus.d \
./base/CCEventKeyboard.d \
./base/CCEventListener.d \
./base/CCEventListenerAcceleration.d \
./base/CCEventListenerController.d \
./base/CCEventListenerCustom.d \
./base/CCEventListenerFocus.d \
./base/CCEventListenerKeyboard.d \
./base/CCEventListenerMouse.d \
./base/CCEventListenerTouch.d \
./base/CCEventMouse.d \
./base/CCEventTouch.d \
./base/CCIMEDispatcher.d \
./base/CCNS.d \
./base/CCNinePatchImageParser.d \
./base/CCProfiling.d \
./base/CCProperties.d \
./base/CCRef.d \
./base/CCScheduler.d \
./base/CCScriptSupport.d \
./base/CCTouch.d \
./base/CCUserDefault-android.d \
./base/CCUserDefault-winrt.d \
./base/CCUserDefault.d \
./base/CCValue.d \
./base/ObjectFactory.d \
./base/TGAlib.d \
./base/ZipUtils.d \
./base/atitc.d \
./base/base64.d \
./base/ccCArray.d \
./base/ccRandom.d \
./base/ccTypes.d \
./base/ccUTF8.d \
./base/ccUtils.d \
./base/etc1.d \
./base/pvr.d \
./base/s3tc.d 


# Each subdirectory must supply rules for building sources it contributes
base/%.o: ../base/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

base/%.o: ../base/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


