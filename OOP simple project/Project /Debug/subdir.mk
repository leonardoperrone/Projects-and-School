################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../default_menu.cpp \
../global.cpp \
../italian_menu.cpp \
../main.cpp \
../mexican_menu.cpp \
../normal_menu.cpp 

OBJS += \
./default_menu.o \
./global.o \
./italian_menu.o \
./main.o \
./mexican_menu.o \
./normal_menu.o 

CPP_DEPS += \
./default_menu.d \
./global.d \
./italian_menu.d \
./main.d \
./mexican_menu.d \
./normal_menu.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


