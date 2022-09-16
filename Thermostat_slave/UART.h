/*
 * UART.h
 *
 * Created: 12.09.2022 15:58:38
 *  Author: vadim
 */ 


#ifndef UART_H_
#define UART_H_

#include "main.h"


void UART_settings(unsigned int ubrr);                    //The UART initialization function;

void UART_transmit(unsigned char data);                   //Data Transmission function. Sending Frames with 5 to 8 data bits;

void UART_print_string(char *str);                        //Function prints sent char array;

unsigned char UART_receive(void);                         //Data Receiving function;

void UART_show_temperature(char *cur_t, char *cur_h);     //Function displays current temperature from master MC;    


#endif /* UART_H_ */