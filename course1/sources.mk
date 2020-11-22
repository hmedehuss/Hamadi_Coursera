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

# Source files for cross compile, target MSP432
SOURCES = ./src/main.c				\
	  ./src/data.c				\
	  ./src/stats.c				\
	  ./src/memory.c			\
	  ./src/course1.c			\
	  ./src/system_msp432p401r.c		\
	  ./src/startup_msp432p401r_gcc.c	\
	  ./src/interrupts_msp432p401r_gcc.c

# Source files for native compile, target HOST
SRCS_HOST = ./src/main.c	\
	    ./src/data.c	\
	    ./src/stats.c	\
	    ./src/memory.c	\
	    ./src/course1.c 

# Include paths for cross compile, target MSP432
INCLUDES = -I./include/CMSIS	\
	   -I./include/common	\
	   -I./include/msp432	\

# Include paths for native compile, target HOST
INC_HOST = -I./include/common
