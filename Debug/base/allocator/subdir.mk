################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../base/allocator/CCAllocatorDiagnostics.cpp \
../base/allocator/CCAllocatorGlobal.cpp \
../base/allocator/CCAllocatorGlobalNewDelete.cpp 

OBJS += \
./base/allocator/CCAllocatorDiagnostics.o \
./base/allocator/CCAllocatorGlobal.o \
./base/allocator/CCAllocatorGlobalNewDelete.o 

CPP_DEPS += \
./base/allocator/CCAllocatorDiagnostics.d \
./base/allocator/CCAllocatorGlobal.d \
./base/allocator/CCAllocatorGlobalNewDelete.d 


# Each subdirectory must supply rules for building sources it contributes
base/allocator/%.o: ../base/allocator/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


