/**
 * @file data.c
 * @brief Performs simple data manipulation
 *
 * @author Hussein HAMADI
 * @date November 13 2020
 */

#include "data.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	int length = 0;
	int digit;
	int is_neg = -1;
	int i;
	
	if(data = 0){
		*ptr = 48;
		return length;
	}
	else if(data < 0){
		is_neg = 1;
		data *= -1;
	}

	while(data != 0){
		digit = num % base;
		num /= base;

		if(digit > 9){
			*(ptr + length) = 55 + digit;
		}
		else{
			*(ptr + length) = 48 + digit;
		}

		length++;
	}

	/* Add Null terminator */
	*(ptr + length) = '\0'; 

	if(is_neg){
		my_memmove(ptr, ptr + 1, length);
		*ptr = 45;
		length++;
	}

	return length;
}

uint32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	
}
