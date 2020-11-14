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
# Author- Hussein HAMADI
# Date:   November 13 2020
# Source Paths
SRCS =  main.c \
	data.c \
	course1.c \
	memory.c \
	stats.c

# Include Paths
INCLUDES = -I ../include/common \
	   -I ../include/CMSIS \
	   -I ../include/msp432 
