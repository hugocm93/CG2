################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Box.cpp \
../Camera.cpp \
../ColorRGB.cpp \
../Image.cpp \
../Light.cpp \
../Material.cpp \
../Object.cpp \
../Ray.cpp \
../Scene.cpp \
../Sphere.cpp \
../Texture.cpp \
../Triangle.cpp 

OBJS += \
./Box.o \
./Camera.o \
./ColorRGB.o \
./Image.o \
./Light.o \
./Material.o \
./Object.o \
./Ray.o \
./Scene.o \
./Sphere.o \
./Texture.o \
./Triangle.o 

CPP_DEPS += \
./Box.d \
./Camera.d \
./ColorRGB.d \
./Image.d \
./Light.d \
./Material.d \
./Object.d \
./Ray.d \
./Scene.d \
./Sphere.d \
./Texture.d \
./Triangle.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


