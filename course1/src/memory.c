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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
#include "stdlib.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
  uint8_t temp[length];		//temporary storage to move bytes
  uint8_t *temp_ptr = temp;	//pointer to temporary storage
  for(int i=0; i<length; i++){
    *temp_ptr++ = *src++;	//move bytes from src to temporary storage
  }
  temp_ptr = temp_ptr - length;	//reset pointer to temporary storage

  for(int j=0; j<length; j++){
    *dst++ = *temp_ptr++;	//move bytes from temporary storage to dst
  }
  dst = dst - length;		//reset dst pointer for return

  return (dst);
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  for(int i=0; i<length; i++){
    *dst++ = *src++;		//copy from src to dst, assume no overlap
  }
  return (dst - length);	//reset dst pointer for return
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
  for(int i=0; i<length; i++){
    *src++ = value;		//set memory to given value
  }
  return (src - length);	//reset src pointer for return
}

uint8_t * my_memzero(uint8_t * src, size_t length){
  for(int i=0; i<length; i++){
    *src++ = 0;			//zero out the specified memory locations
  }
  return (src - length);	//reset src pointer for return
}

uint8_t * my_reverse(uint8_t * src, size_t length){
  uint8_t temp[length];		//temporary storage for bytes to reverse
  uint8_t *temp_ptr = temp;	//pointer to temporary storage
  for(int i=0; i<length; i++){
    *temp_ptr++ = *src++;	//copy data to temporary storage
  }
  temp_ptr = temp_ptr - length;	//reset pointer to temporary storage

  for(int i=0; i<length; i++){
    *--src = *temp_ptr++;	//reverse data in src
  }

  return (src);
}

uint32_t * reserve_words(size_t length){	
  //multiply 4 to convert 32-bit words to 8-bit bytes	
  return ((uint32_t *) malloc(length*4));
}

void free_words(uint32_t * src){
  free(src);	//free allocated memory from heap
}

