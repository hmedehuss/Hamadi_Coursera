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
 * @file stats.c
 * @brief This simple application performs statistical analytics on a data set.
 *
 * The data set is an array of unsigned char data items.
 * Reported analytics are maximum, minimum, mean and median of the data set.
 * The data set is reordered from largest to smallest value.
 * All statistics are rounded down to the nearest integer.
 * The analysis results and reordered data set are printed out.
 *
 * @author Hussein HAMADI
 * @date 22 October 2020
 *
 */



#include "platform.h"
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/*
int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  print_array(test, SIZE);
  print_statistics(test, SIZE);
  print_array(test, SIZE);
}
*/

/* Add other Implementation File Code Here */
void print_statistics(unsigned char *array, unsigned int size){
  PRINTF("\nMaximum: %d\n", (int) find_maximum(array, size));
  PRINTF("Minimum: %d\n", (int) find_minimum(array, size));
  PRINTF("Mean: %d\n", (int) find_mean(array, size));
  PRINTF("Median: %d\n\n", (int) find_median(array, SIZE));
}

void print_array(unsigned char *array, unsigned int size){
#if defined (VERBOSE)
  int i;	
  PRINTF("\n");
  for(i=0; i<size; i++){
    PRINTF("%-3d\t", array[i]);
    if((i+1) % 8 == 0) PRINTF("\n");
  }
#endif
}

unsigned char find_median(unsigned char *array, unsigned int size){
  sort_array(array, size);
  if(size % 2 == 0){
    return((array[size/2] + array[(size/2)-1])/2);
  }
  else return(array[size/2]);
}

unsigned char find_mean(unsigned char *array, unsigned int size){
  int i, sum = 0;
  for(i=0; i<size; i++){
    sum += array[i];
  }
 return(sum/size); 
}

unsigned char find_maximum(unsigned char *array, unsigned int size){
  int i, maximum = 0;
  for(i=0; i<size; i++){
    if(array[i] > maximum){
      maximum = array[i];
    }
  }
  return(maximum);
}

unsigned char find_minimum(unsigned char *array, unsigned int size){
  int i, minimum = 255;
  for(i=0; i<size; i++){
    if(array[i] < minimum){
      minimum = array[i];
    }
  }
  return(minimum);
}

void sort_array(unsigned char *array, unsigned int size){
  int i, j, temp;
  for(i=0; i<size; i++){
    for(j=size-1; j>i; j--){
      if(array[j-1] < array[j]){
         temp = array[j-1];
	 array[j-1] = array[j];
	 array[j] = temp;
      }
    }
  }
}


