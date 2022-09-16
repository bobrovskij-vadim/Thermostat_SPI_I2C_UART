/*
 * UART.c
 *
 * Created: 12.09.2022 15:59:11
 *  Author: vadim
 */ 

#include "UART.h"

void UART_settings(unsigned int ubrr)                           //The UART initialization function;
{                                                               //ubrr - accepts baud rate settings;
	UBRRH = (unsigned char)(ubrr >> 8);                         //Set the baud rate - 9600 BAUD. fOSC = 1 000 000 Hz.
	UBRRL = (unsigned char)(ubrr);                              //Asynchronous double speed mode (U2X = 1);
	UCSRA |= (1<<U2X);                                          //Double the UART transmission speed;
	UCSRB = (1<<RXEN) | (1<<TXEN);                              //RXEN: Receiver Enable. TXEN: Transmitter Enable;
	UCSRC = (1<<URSEL) | (1<<USBS) | (1<<UCSZ1) | (1<<UCSZ0);   //URSEL: Register Select - Asynchronous mode. USBS: Stop Bit Select - 2-bit. UCSZ1:0: Character Size - 8-bit;
}

void UART_transmit(unsigned char data)                          //Data Transmission function. Sending Frames with 5 to 8 data bits;
{
	while (!( UCSRA & (1<<UDRE)))                               //Wait for empty transmit buffer;
	;
	UDR = data;                                                 //Put data into buffer, sends the data;
}

void UART_print_string(char *str)                               //Function prints sent char array;
{
	while(*str != '\0')
	{
		UART_transmit(*str);
		str++;
	}
}

unsigned char UART_receive(void)                                //Data Receiving function;
{
	while ( !(UCSRA & (1<<RXC)) )                               //Wait for data to be received;
	;
	return UDR;                                                 //Get and return received data from buffer;
}

void UART_show_temperature(char *cur_t, char *cur_h)            //Function returns temperature from sensor to UART;
{
	UART_print_string("Temperature: ");
	UART_print_string(cur_t);
	UART_print_string(" C\r");
	UART_print_string("Humidity: ");
	UART_print_string(cur_h);
	UART_print_string("%\r");	
}


