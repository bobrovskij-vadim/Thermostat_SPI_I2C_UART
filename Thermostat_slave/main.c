/*
 * Thermostat_slave.c
 *
 * Created: 12.09.2022 13:35:28
 * Author : vadim
 */ 

#include "main.h"


int main(void)
{	
	UART_settings(12);           // Set the baud rate - 9600 BAUD. fOSC = 1 000 000 Hz. Asynchronous double speed mode (U2X = 1); 
	
	SPI_slave_init();            // SPI slave initialization;
	
	char cur_t[5];               // Current temperature; 
	char cur_h[3];               // Current humidity;

    while (1) 
    {
		SPI_get_t_h(cur_t, cur_h);              // Function gets char data, temperature and humidity;
		UART_show_temperature(cur_t, cur_h);    // Function displays current temperature and humidity from master MC;    
    }
}

