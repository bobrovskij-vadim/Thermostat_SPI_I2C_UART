/*
 * SPI.c
 *
 * Created: 13.09.2022 14:03:01
 *  Author: vadim
 */ 

#include "SPI.h"

void SPI_master_init(void)                             // SPI initialization function;
{
 	DDRB = (1<<SS) | (1<<MOSI) | (1<<SCK);             // Set MOSI and SCK output, all others input;
 	SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0);           // Enable SPI, Master, set clock rate fck/16;
}
 
void SPI_master_transmit(char cData)                   // SPI data send function; 
{
	SPDR = cData;                                      // Start transmission;
	while(!(SPSR & (1<<SPIF)))                         // Wait for transmission complete;
	;
}

void SPI_send_t_h(float temperature, float humidity)   // Function sends temperature and humidity to slave microcontroller;
{
	char t_str[5];                                     // Char array to temperature;
	char h_str[3];                                     // Char array to humidity;

	ftoa(temperature, t_str, 1);                       // Convert float to string;  
	for(int i = 0; i < 5; ++i)
	{
		SPI_master_transmit(t_str[i]);                 // Send char data to slave MC;
	}
	
	ftoa(humidity, h_str, 0);                          // Convert float to string;
	for(int i = 0; i < 3; ++i)
	{
		SPI_master_transmit(h_str[i]);                 // Send char data to slave MC;
	}
}
