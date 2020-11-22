#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material.
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile using native HOST compiler, and MSP432 cross compiler
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      <FILE>.i - Generates <FILE>.i preprocessed output
#      <FILE>.asm - Generate <FILE>.asm assembly output
#      compile-all - Compiles all source files without linking
#      build - Builds and links all source files
#      clean - Removes all generated files
#
# Platform Overrides:
#      PLATFORM - Supported platform (HOST, MSP432)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides, default PLATFORM=HOST
ifndef PLATFORM
	PLATFORM := HOST
endif	

ifndef COURSE
	COURSE := COURSE1
endif

ifndef VERBOSE 
	VERBOSE := NOT_VERBOSE
endif

# Architectures Specific Flags, for PLATFORM=MSP432
LINKER_FILE = -T msp432p401r.lds
CPU = cortex-m4
STATE = thumb
ARCH = armv7e-m
FLOAT_ABI = hard
FPU = fpv4-sp-d16
SPECS = nosys.specs

# Compiler Flags and Defines
TARGET = main
ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	SZ = arm-none-eabi-size
	OD = arm-none-eabi-objdump
	AFLAGS  = -mcpu=$(CPU) -m$(STATE) -march=$(ARCH) \
		  -mfloat-abi=$(FLOAT_ABI) -mfpu=$(FPU) \
		  --specs=$(SPECS)
	LDFLAGS = -Wl,-Map=$(TARGET).map -Wl,$(LINKER_FILE)
	SRCS = $(SOURCES)
	INC = $(INCLUDES)
else
	CC = gcc	
	SZ = size
	OD = objdump
	LDFLAGS = -Wl,-Map=$(TARGET).map
	SRCS = $(SRCS_HOST)
	INC = $(INC_HOST)
endif

CFLAGS = -Wall -Werror -g -O0 -std=c99 
CPPFLAGS = -MD $(INCLUDES)  -Wp,-D$(PLATFORM) -Wp,-D$(COURSE) -Wp,-D$(VERBOSE)

# Use Pattern matching operator to simplify makefile
%.o: %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) $(AFLAGS) -o $@

%.i: %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

%.asm: %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) $(AFLAGS) -o $@ 

.PHONY: compile-all
compile-all:
	$(CC) -c $(SRCS) $(CPPFLAGS) $(CFLAGS) $(AFLAGS)
	
.PHONY: build
build: $(TARGET).out
$(TARGET).out: $(SRCS:.c=.o)
	$(CC) $(SRCS:.c=.o) $(CPPFLAGS) $(CFLAGS) \
		$(AFLAGS) $(LDFLAGS) -o $@
	$(SZ) $(TARGET).out
	$(OD) -D $(TARGET).out > $(TARGET).asm


OBJS_o = $(SOURCES:.c=.o)
OBJS_i = $(SOURCES:.c=.i)
OBJS_a = $(SOURCES:.c=.asm)
OBJS_d = $(SOURCES:.c=.d)

.PHONY: clean
clean: 
	rm -f $(OBJS_o) $(OBJS_i) $(OBJS_a) $(OBJS_d) \
	       	$(TARGET).out $(TARGET).map $(TARGET).asm \
		*.d *.o
	
