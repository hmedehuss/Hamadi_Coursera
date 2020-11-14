

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
 * @brief C file of the first assessments
 *
 * A Simple C program file of the first assessments that calculate some statistics and print them on screen :
 *     -find_median
 *     -find_mean
 *     -find_maximum
 *     -find_minimum
 *     -sort_array
 *
 * @author Hussein HAMADI
 * @date 6-11-2020
 *
 */

#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)




int find_minimum(int *ptr , int count)
{
	int i=0;
	int min=ptr[0];
	for (i=1;i<count;i++)
	{
		if (ptr[i]<min)
		{
			min=ptr[i];
		}
	}
	return min;
}
int find_maximum(int *ptr , int count)
{
	int i=0;
	int max=ptr[0];
	for (i=1;i<count;i++)
	{
		if (ptr[i]>max)
		{
			max=ptr[i];
		}
	}
	return max;
}
int find_mean(int * ptr, int count)
{
	int i;
	int sum=0;
	for(i =0;i<count;i++)
	{
		sum =sum + ptr[i];
	}
	return (sum/count);
}
void sort_array(int * ptr, int count)
{
	int key,j;
	for(int i=1;i<count;i++)
	{
		key = ptr[i];
		j=i-1;
		while(j>=0 && ptr[j]<key)
		{
			ptr[j+1]=ptr[j];
			j=j-1;
		}
		ptr[j+1]=key;
	}
}
int find_median(int * ptr, int count)
{
	int i,median,first_number ,second_number;
	sort_array(ptr,count);
	if(count%2 == 0)
	{
		i = count/2;
		first_number=ptr[i-1];
		second_number=ptr[i];
		median = (first_number+second_number)/2;
	}
	else
	{
		i = count/2;
		median = ptr[i-1];
	}
	return median;
}

void print_array(int * ptr, int count)
{
	#ifdef VERBOSE
	for(int i=0;i<count;i++)
	{
		PRINTF("%d",ptr[i]);
	}
	#endif

}

void print_statistics(int * ptr, int count)
{
	int min = find_minimum(ptr,count);
	int max = find_maximum(ptr,count);
	int medain = find_median(ptr,count);
	int mean = find_mean(ptr,count);
	PRINTF("The minimum number of array = %d\n",min);
	PRINTF("The maximum number of array = %d\n",max);
	PRINTF("The median number of array = %d\n",medain);
	PRINTF("The mean number of array = %d\n",mean);
}
