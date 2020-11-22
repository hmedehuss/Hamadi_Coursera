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
 * @file stats.h 
 * @brief Function declarations and documentation for stats.c
 *
 * print_statistics()	- gven an array and length, 
 * 			- prints minimum, maximum, mean and median of the array
 * print_array()	- given an array and length, prints array to the screen
 * find_median()	- given an array and length, returns the median value
 * find_mean()		- given an array and length, returns the mean
 * find_maximum()	- given an array and length, returns the maximum
 * find_minimum()	- given an array and length, returns the minimum
 * sort_array()		- given an array and length, sorts largest to smallest
 *
 * @author Hussein HAMADI
 * @date 22 October 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistics of an array.
 *
 * This functions prints the minimum, maximum, mean and median values
 * from a given array of unsigned char data items.
 *
 * @param array Pointer to an n-element data array.
 * @param size Size of the array.
 * @return none
 */
void print_statistics(unsigned char *array, unsigned int size);

/**
 * @brief Prints a given array to the screen.
 *
 * The array consists of unsigned char data.
 *
 * @param array Pointer to an n-element data array.
 * @param size Size of the array.
 * @return none.
 */
void print_array(unsigned char *array, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the median value.
 *
 * The array consists of unsigned char data.
 *
 * @param array Pointer to an n-element data array.
 * @param size Size of the array.
 * @return Median value in unsigned char type.
 */
unsigned char find_median(unsigned char *array, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the mean.
 *
 * The array consists of unsigned char data
 *
 * @param array Pointer to an n-element data array.
 * @param size Size of the array.
 * @return Mean value in unsigned char type.
 */
unsigned char find_mean(unsigned char *array, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the maximum.
 *
 * The array consists of unsigned char data.
 *
 * @param array Pointer to an n-element data array.
 * @param size Size of the array.
 * @return Maximum value in unsigned char type.
 */
unsigned char find_maximum(unsigned char *array, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the minimum.
 *
 * The array consists of unsigned char data.
 *
 * @param array Pointer to an n-element data array.
 * @param size Size of the array.
 * @return Minimum value in unsigned char type.
 */
unsigned char find_minimum(unsigned char *array, unsigned int size);

/**
 * @brief Given an array of data and a length, sorts the array.
 *
 * The array consists of unsigned char data.
 *
 * Array is sorted from largest to smallest value.
 * The zeroth element has the largest value.
 * The last element (n-1) has the smallest value.
 *
 * @param array Pointer to an n-element data array.
 * @param size Size of the array.
 * @return none
 */
void sort_array(unsigned char *array, unsigned int size);
 
#endif /* __STATS_H__ */
