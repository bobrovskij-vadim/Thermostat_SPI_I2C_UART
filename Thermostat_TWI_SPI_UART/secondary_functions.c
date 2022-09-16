/*
 * secondary_functions.c
 *
 * Created: 14.09.2022 14:07:09
 *  Author: vadim
 */ 

#include "secondary_functions.h"

void reverse(char* str, int len)
{
	int i = 0, j = len - 1, temp;
	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int intToStr(int x, char str[], int d)          // Function convert int to string;
{
	int i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
	str[i++] = '0';
	
	reverse(str, i);
	str[i] = '\0';
	return i;
}

void ftoa(float n, char* arr, int afterpoint)     // Function convert float to string;
{
	int ipart = (int)n;                           // Extract integer part;
	float fpart = n - (float)ipart;               // Extract floating part
	int i = intToStr(ipart, arr, 0);              // convert integer part to string
	
	if (afterpoint != 0)                          // check for display option after point
	{
		arr[i] = '.';                             // add dot
		fpart = fpart * pow(10, afterpoint);
		intToStr((int)fpart, arr + i + 1, afterpoint);
	}
}