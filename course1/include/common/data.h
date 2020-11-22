/**
 * @file data.h
 * @brief function declaration & documentation for data.c
 *
 * my_itoa() - convert data from standard integer to ASCII string
 * my_atoi() - convert data from ASCII string to integer
 *
 * @author Hussein HAMADI
 * @date 6 November 2020
 *
 */
#ifndef __DATA_H__
#define __DATA_H__
#include <stdint.h>

#define BASE_2  (2)
#define BASE_8  (8)
#define BASE_10 (10)
#define BASE_16 (16)

/**
 * @brief convert data from standard integer type to ASCII string
 *
 * This function converts data from a standard integer type,
 * into an ASCII string.
 * Positive and negative integers are accepted.
 * All operations are performed using pointer arithmetic.
 * The number to be converted is passed in as a signed 32-bit integer (data).
 * Bases 2 to 16 are supported by specifying the integer value of the base
 * to convert to (base).
 * The converted character string is copied to the memory location
 * indicated by the input pointer (ptr).
 * The maximum string size is 32 characters (in binary) + 1 NULL character.
 * The function will return the length of the converted data,
 * which includes the negative sign and NULL character.
 * String functions and libraries are not used.
 *
 * @param data Signed integer to be converted to ASCII string
 * @param ptr Pointer to memory where converted string is stored
 * @param base Integer value of the base to convert to (base 2-16 supported)
 * 
 * @return Length of ASCII string in bytes (includes -ve sign and NULL).
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief convert data from ASCII string to integer type
 *
 * This function converts data from an ASCII represented string
 * into an integer type. Positive and negative values are accepted.
 * All operations are performed using pointer arithmetic.
 * The character string to convert is passed in as a pointer (ptr).
 * The number of digits in the string is passed in as an integer (digits).
 * Bases 2-16 are supported.
 * The function will return the converted 32-bit signed integer.
 * String functions and libraries are not used.
 *
 * @param ptr Pointer to ASCII string to be converted to integer
 * @param digits Number of digits in the ASCII string
 * @param base Integer value of the base to convert to (base 2-16 supported)
 *
 * @return Result of conversion (32-bit signed integer)
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
