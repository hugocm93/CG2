################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Camera.cpp \
../Image.cpp \
../MainWindow.cpp \
../Object.cpp \
../Ray.cpp \
../Scene.cpp \
../main.cpp 

OBJS += \
./Camera.o \
./Image.o \
./MainWindow.o \
./Object.o \
./Ray.o \
./Scene.o \
./main.o 

CPP_DEPS += \
./Camera.d \
./Image.d \
./MainWindow.d \
./Object.d \
./Ray.d \
./Scene.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


