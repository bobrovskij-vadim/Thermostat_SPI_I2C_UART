/*
 * Thermostat_TWI_SPI_UART.c
 *
 * Created: 05.09.2022 11:28:36
 * Author : vadim
 */ 

#include "main.h"

int main(void)
{
	LCD_ports_settings();             // Microcontroller ports settings which connect with the LCD; 

	LCD_initialization();             // LCD initialization function;
	
	T_H_button_settings();            // Ports settings for buttons;
	
	T_H_controller_port_settings();   // Ports settings for temperature and humidity controller;
	
	I2C_settings();                   // Function TWI/I2C settings;  
	
	SPI_master_init();                // SPI initialization function;
	
	float set_t = EEPROM_read(1);     // Settled temperature;
	float set_h = EEPROM_read(0);	  // Settled humidity;
	
	float cur_t = 0;                  // Current temperature from I2C;
	float cur_h = 0;                  // Current humidity from I2
   
    while (1) 
    { 		
		I2C_get_t_h_data(&cur_t, &cur_h);                // Get temperature and humidity from SHT21;
			
		LCD_show_t_h(set_t, set_h, cur_t, cur_h);        // Display temperature and humidity on LCD; 
 				
		T_H_maintain(set_t, set_h, cur_t, cur_h);	     // Controlling heating and cooling; 
	
		SPI_send_t_h(cur_t, cur_h);                      // Sending data to slave MC;
		
		//----------Humidity controlling----------	
		if(~PIND & (1<<PD0))               //PD0 button pressed, humidity +;
		{
			while(~PIND & (1<<PD0))        //Contact bounce
			;
			set_h++;
			if(set_h > 100)
				set_h = 100;
			EEPROM_write(0, set_h);
		}
		
		if(~PIND & (1<<PD1))               //PD1 button pressed, humidity -;
		{
			while(~PIND & (1<<PD1))        //Contact bounce
			;
			set_h--;
			if(set_h < 0)
				set_h = 0;
			EEPROM_write(0, set_h);
		}
			
		//----------Temperature controlling----------
		if(~PINC & (1<<PC3))               //PC3 button pressed, temperature +;
		{
			while(~PINC & (1<<PC3))        //Contact bounce
			;
			set_t += 0.1;
			if(set_t > 120)
				set_t = 120;
			EEPROM_write(1, set_t);
		}
				
		if(~PINB & (1<<PB7))               //PB7 button pressed, temperature -;
		{
			while(~PINB & (1<<PB7))        //Contact bounce
			;
			set_t -= 0.1;
			if(set_t < -40)
				set_t = -40;
			EEPROM_write(1, set_t);
		}
	}
}
