################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../math/MathUtil.cpp \
../math/Quaternion.cpp \
../math/TransformUtils.cpp \
../math/Vec2.cpp \
../math/Vec3.cpp \
../math/Vec4.cpp 

OBJS += \
./math/MathUtil.o \
./math/Quaternion.o \
./math/TransformUtils.o \
./math/Vec2.o \
./math/Vec3.o \
./math/Vec4.o 

CPP_DEPS += \
./math/MathUtil.d \
./math/Quaternion.d \
./math/TransformUtils.d \
./math/Vec2.d \
./math/Vec3.d \
./math/Vec4.d 


# Each subdirectory must supply rules for building sources it contributes
math/%.o: ../math/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


