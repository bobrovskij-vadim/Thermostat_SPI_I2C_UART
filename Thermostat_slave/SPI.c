/*
 * SPI.c
 *
 * Created: 13.09.2022 15:52:01
 *  Author: vadim
 */ 

#include "SPI.h"

void SPI_slave_init(void)       // SPI slave initialization function;
{
	DDRB = (1<<MISO);           // Set MISO output, all others input;
	SPCR = (1<<SPE);            // Enable SPI;
}

char SPI_slave_receive(void)    // SPI slave receive data;
{
	while(!(SPSR & (1<<SPIF)))  // Wait for reception complete;
	;
	return SPDR;                // Return data register;
}

void SPI_get_t_h(char *temperature, char *humidity)     // Function gets char data, temperature and humidity;
{
	for(int i = 0; i < 5; ++i)
	{
		temperature[i] = SPI_slave_receive();
	}
	
	for(int i = 0; i < 3; ++i)
	{
		humidity[i] = SPI_slave_receive();
	}
}


