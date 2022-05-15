################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../accel.c \
../main.c \
../servo.c \
../twi_master.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
accel.o \
main.o \
servo.o \
twi_master.o

OBJS_AS_ARGS +=  \
accel.o \
main.o \
servo.o \
twi_master.o

C_DEPS +=  \
accel.d \
main.d \
servo.d \
twi_master.d

C_DEPS_AS_ARGS +=  \
accel.d \
main.d \
servo.d \
twi_master.d

OUTPUT_FILE_PATH +=gimbal_test.elf

OUTPUT_FILE_PATH_AS_ARGS +=gimbal_test.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./accel.o: .././accel.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.31
	$(QUOTE)F:\Program Files\Microchip\xc8\v2.31\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega328PB  -mdfp="F:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega328PB__ -DDEBUG  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.31
	$(QUOTE)F:\Program Files\Microchip\xc8\v2.31\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega328PB  -mdfp="F:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega328PB__ -DDEBUG  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./servo.o: .././servo.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.31
	$(QUOTE)F:\Program Files\Microchip\xc8\v2.31\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega328PB  -mdfp="F:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega328PB__ -DDEBUG  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./twi_master.o: .././twi_master.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.31
	$(QUOTE)F:\Program Files\Microchip\xc8\v2.31\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega328PB  -mdfp="F:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega328PB__ -DDEBUG  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking:  XC8 C Linker : 2.31
	$(QUOTE)F:\Program Files\Microchip\xc8\v2.31\bin\xc8-cc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -mcpu=ATmega328PB  -mdfp="F:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\xc8"  -Wl,-Map="gimbal_test.map" -funsigned-char -funsigned-bitfields -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums --memorysummary,memoryfile.xml  
	@echo Finished building target: $@
	"F:\Program Files\Microchip\xc8\v2.31\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "gimbal_test.elf" "gimbal_test.hex"
	"F:\Program Files\Microchip\xc8\v2.31\bin\avr-objcopy.exe" -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O ihex "gimbal_test.elf" "gimbal_test.eep" || exit 0
	"F:\Program Files\Microchip\xc8\v2.31\bin\avr-objdump.exe" -h -S "gimbal_test.elf" > "gimbal_test.lss"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "gimbal_test.elf" "gimbal_test.hex" "gimbal_test.eep" "gimbal_test.map" "gimbal_test.usersignatures" "gimbal_test.a"  "gimbal_test.lss"
	