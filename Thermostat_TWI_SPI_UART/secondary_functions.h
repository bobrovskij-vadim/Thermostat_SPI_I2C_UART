/*
 * secondary_functions.h
 *
 * Created: 14.09.2022 14:06:32
 *  Author: vadim
 */ 


#ifndef SECONDARY_FUNCTIONS_H_
#define SECONDARY_FUNCTIONS_H_

#include "main.h"

void reverse(char* str, int len); 

int intToStr(int x, char str[], int d);             // Function convert int to string; 

void ftoa(float n, char* arr, int afterpoint);      // Function convert float to string; 


#endif /* SECONDARY_FUNCTIONS_H_ */