/**
 * @file data.c
 * @brief Functions to perform conversion.
 * my_itoa() - Converts integer to ASCII string
 * my_atoi() - Converts ASCII string to integer 
 *
 * @author Hussein HAMADI
 * @date 6 November 2020
 *
 */

#include "data.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  uint8_t length = 0;		//length of ASCII string
  uint8_t negative_sign = 0;	//negative sign flag

  if(data < 0){		//if data is a negative value,
    *ptr++ = '-';	//store ASCII for "-" at ptr location,
    data = data*(-1);	//get magnitude of data,
    negative_sign = 1;	//and set the flag for negative sign
  }

  while(data != 0){
    //convert data to required base, digit by digit, from least significant,
    //and store the ASCII value (digit offset by +48) at ptr location.
    //Note: as digits should start from most significant, need to reverse later
    *ptr++ = (data % base) + 48;
    data = data / base;	//update data to calculate next digit
    length++;		//keep track of number of converted digits 
  }
  *ptr = '\0';		//store NULL terminator

  ptr = ptr - length;	//reset ptr to first converted digit (least significant)
  my_reverse(ptr, (size_t) length);	//reverse digit positions

  return (length + negative_sign + 1);	//return total length of ASCII string
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  uint8_t negative_sign = 0;	//negative sign flag
  int32_t result = 0;		//conversion result
  uint32_t multiplier = 1;	//multiplier, according to digit position 

  if(*ptr == '-'){	//if negative value,
    negative_sign = 1;	//set the negative sign flag
    ptr++;		//increment pointer to bypass negative sign
    digits--;		//decrement digits to bypass negative sign
  }

  //reverse string to simplify calculation with least significant digit first
  my_reverse(ptr, (size_t) (digits-1));

  while(*ptr != '\0'){	//parse through entire string until NULL terminator
    //convert one character at a time, offset(-48) to change back to digit,
    //multiply with multiplier, and accumulate in result
    result = result + ((*ptr++)-48)*multiplier;
    multiplier = multiplier * base;	//update multiplier for next digit    
  }

  ptr = ptr - (digits-1);		//reset ptr
  my_reverse(ptr, (size_t) (digits-1));	//return string to original sequence

  if(negative_sign == 1){	//add negative sign to result if needed
    result = result * (-1);
  }

  return (result);
}
