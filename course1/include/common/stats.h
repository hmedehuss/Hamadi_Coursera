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
 * @brief header file of the first assessments
 *
 * A header file of the first assessments that contain prototypes of functions:
 *     -print_statistics
 *     -print_array
 *     -find_median
 *     -find_mean
 * 	   -find_maximum
 *     -find_minimum
 *     -sort_array
 *
 * @author Hussein HAMADI
 * @date 6-11-2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Size of the Data Set */
#define SIZE (40)

 /******************************************************************************
 * Function: print_statistics
 * Description:
 *     This function prints the statistics of an array including minimum, maximum, mean, and median.
 * Parameters:
 *     int * ptr: Pointer to a data set
 *     int count: Number of items in data set
 * Return:
 *     void
 *****************************************************************************/
 
void print_statistics(int * ptr, int count);

/******************************************************************************
* Function: print_array
* Description:
*     This function takes an array of data and a length, prints the array to the screen
* Parameters:
*     int * ptr: Pointer to a data set
*     int count: Number of items in data set
* Return:
*     void
*****************************************************************************/
void print_array(int * ptr, int count);

/******************************************************************************
* Function: find_median
* Description:
*     This function takes an array of data and a length, returns the median value
* Parameters:
*     int * ptr: Pointer to a data set
*     int count: Number of items in data set
* Return:
*     int median : the median value
*****************************************************************************/
int find_median(int * ptr, int count);

/******************************************************************************
* Function: find_mean
* Description:
*     This function takes an array of data and a length, returns the mean
* Parameters:
*     int * ptr: Pointer to a data set
*     int count: Number of items in data set
* Return:
*     int mean : the mean value
*****************************************************************************/
int find_mean(int * ptr, int count);

/******************************************************************************
* Function: find_maximum
* Description:
*     This function takes an array of data and a length, returns the maximum value
* Parameters:
*     int * ptr: Pointer to a data set
*     int count: Number of items in data set
* Return:
*     int max : the maximum value
*****************************************************************************/

int find_maximum(int * ptr, int count);
 
/******************************************************************************
* Function: find_minimum
* Description:
*     This function takes an array of data and a length, returns the minimum value
* Parameters:
*     int * ptr: Pointer to a data set
*     int count: Number of items in data set
* Return:
*     int min : the minimum value
*****************************************************************************/

int find_minimum(int * ptr, int count);

/******************************************************************************
* Function: sort_array
* Description:
*     an array of data and a length, sorts the array from largest to smallest.
*     (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
* Parameters:
*     int * ptr: Pointer to a data set
*     int count: Number of items in data set
* Return:
*     void
*****************************************************************************/

void sort_array(int * ptr, int count);


#endif /* __STATS_H__ */
