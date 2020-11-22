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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__
#include <stdint.h>
#include <stddef.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves data from source to destination
 *
 * This function takes two byte pointers (one source and one destination)
 * and a length of bytes to move from the source location to the destination.
 * Overlap of source and destination is permitted.
 * All operations are performed using pointer arithmetic.
 *
 * @param src Pointer to start address of bytes to move
 * @param dst Pointer to start address where copied bytes are moved to
 * @param length Number of bytes to move
 *
 * @return Pointer to start address where copied bytes are stored
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies data from source to destination
 *
 * This function takes two byte pointers (one source and one destination)
 * and a length of bytes to copy from the source location to the destination.
 * The behaviour is undefined if there is overlap of source and destination.
 * Copy will still occur, but will likely corrupt your data.
 * All operations are performed using pointer arithmetic.
 *
 * @param src Pointer to start address of bytes to copy
 * @param dst Pointer to start address where bytes are copied to
 * @param length Number of bytes to move
 *
 * @return Pointer to start address where copied bytes are stored
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * brief Sets byte value from source to destination
 *
 * This function takes a byte pointer to a source memory location,
 * a length in bytes, and sets all locations of that memory to a given value.
 * All operations are performed using pointer arithmetic.
 * The set_all() function will not be reused here.
 *
 * @param src Pointer to start address of bytes to set
 * @param length Number of bytes to set
 * @param value Byte value to place in memory
 *
 * @return Pointer to start address where bytes are set
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * brief Zero out bytes from source to destination
 *
 * This function takes a byte pointer to a source memory location
 * and a length in bytes, and then zero out all of the memory.
 * All operations are performed using pointer arithmetic.
 * The clear_all() function will not be reused here.
 *
 * @param src Pointer to start address of bytes to zero
 * @param length Number of bytes to zero
 *
 * @return Pointer to start address where bytes are zeroed
 */
uint8_t * my_memzero(uint8_t * src, size_t length); 

/**
 * brief Reverse the order of bytes
 *
 * This function takes a byte pointer to a source memory location
 * and a length in bytes, and then reverses the order of all the bytes.
 * All operations are performed using pointer arithmetic.
 *
 * @param src Pointer to start address of bytes to reverse
 * @param length Number of bytes to reverse
 *
 * @return Pointer to start address of reversed bytes
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * brief Reserve memory in the heap
 *
 * This function takes a length in bytes to allocate in dynamic memory.
 * All operations are performed using pointer arithmetic.
 * If allocation is successful, pointer to allocated memory is returned,
 * else a Null pointer is returned if memory allocation is not successful.
 *
 * @param length Number of bytes to reserve in memory
 *
 * @return Pointer to start address of reserved memory (or NULL if none)
 */
uint32_t * reserve_words(size_t length);

/**
 * brief Release reserved memory in the heap
 *
 * This function takes a pointer to previously allocated dynamic memory,
 * and releases the allocated memory.
 * All operations are performed using pointer arithmetic.
 *
 * @param src Pointer to perviously allocated dynamic memory
 *
 * @return void
 */
void free_words(uint32_t *src);


#endif /* __MEMORY_H__ */
