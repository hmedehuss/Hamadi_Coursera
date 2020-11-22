/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main entry point to the Course1 Final Assessment
 *
 * This file contains the main code for the Course1 Final assesment.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "platform.h"

#if defined (COURSE1)
#include "course1.h"
#endif

int main(void) {
	
#if defined (COURSE1)
  course1();
#else
  PRINTF("Please compile with COURSE=<OPTION> and PLATFORM=<OPTION>\n\
for correct course and platform e.g. COURSE=COURSE1 PLATFORM=HOST.\n"); 
#endif

  return 0;
}

