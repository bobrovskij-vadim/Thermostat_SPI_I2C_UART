/*
 * I2c.c
 *
 * Created: 05.09.2022 13:13:38
 *  Author: vadim
 */ 

#include "I2C.h"

void I2C_settings(void)
{
	TWBR = 2;                                       //TWI Bit Rate Register - Clock line frequency = 50. Fcpu = 1MHz;
	TWSR &= ~((1<<TWPS1) | (1<<TWPS0)); 	        //No frequency divider;
}

void I2C_start_condition(void)
{
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);     //TWINT: TWI Interrupt Flag. TWSTA: TWI START Condition Bit. TWEN: TWI Enable Bit;
	while (!(TWCR&(1<<TWINT)))                      //TWINT bit is set by hardware when the TWI has finished its current job and expects application software response;
	;
}

void I2C_stop_condition(void)
{
	TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);     //TWINT: TWI Interrupt Flag. TWSTO: TWI STOP Condition Bit. TWEN: TWI Enable Bit;
}

void I2C_write_command(unsigned char command)       //Set command TWI;   
{
	TWDR = command;                                 //TWDR - TWI Data Register;
	TWCR = (1<<TWINT) | (1<<TWEN);                  //TWINT: TWI Interrupt Flag. TWEN: TWI Enable Bit;
	while(!(TWCR&(1<<TWINT)))                       //TWINT bit is set by hardware when the TWI has finished its current job and expects application software response;
	;
}

unsigned char I2C_get_byte_data(void)               //Function returns one byte data from the sensor;
{
	TWCR = (1<<TWEA) | (1<<TWINT) | (1<<TWEN);
	while (!(TWCR&(1<<TWINT)))
	;
	
	return TWDR;
}

void I2C_NACK_checksum(void)                        //Checksum transmission;  
{
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR&(1<<TWINT)))
	;
}

void I2C_get_t_h_data(float *temperature, float *humidity)        //Function sets value temperature and humidity;
{
	unsigned char T_msb = 0;            //Temperature most significant byte; 
	unsigned char T_lsb = 0;            //Temperature least significant byte; 
	unsigned int  T_16 = 0;             //Temperature two byte data;       

	unsigned char H_msb = 0;            //Humidity most significant byte;  
	unsigned char H_lsb = 0;            //Humidity least significant byte; 
	unsigned int  H_16 = 0;             //Humidity two byte data;   
	
	//--------------Getting temperature--------------
	I2C_start_condition();
	I2C_write_command(0x080);            //I2C address + write;
	I2C_write_command(0xF3);             //Access to the temperature sensor;  
	_delay_ms(150);                      //Delay for command processing;
	I2C_start_condition();
	I2C_write_command(0x080 + 1);        //I2C address + read;
	
	T_msb = I2C_get_byte_data();         //Getting temperature data, first byte;
	
	T_lsb = I2C_get_byte_data();         //Getting temperature data, second byte;
	
	I2C_NACK_checksum();                 //Checksum transmission;                         
	
	I2C_stop_condition();                //Stop data transmission;
	
	T_16 = (T_msb<<8) | T_lsb;	
	*temperature = -46.85 + (175.72 * T_16) / 65536.0;
	
    //--------------Getting humidity--------------
	I2C_start_condition();
	I2C_write_command(0x080);            //I2C address + write;
	I2C_write_command(0xF5);             //Access to the humidity sensor;
	_delay_ms(150);                      //Delay for command processing;
	I2C_start_condition();
	I2C_write_command(0x080 + 1);        //I2C address + read;
	
	H_msb = I2C_get_byte_data();         //Getting temperature data, first byte;
	
	H_lsb = I2C_get_byte_data();         //Getting temperature data, second byte;
	
	I2C_NACK_checksum();                 //Checksum transmission;
	
	I2C_stop_condition();                //Stop data transmission;
	
	H_16 = (H_msb<<8) | H_lsb;
	*humidity = (-6.0 + (125.0 * H_16) / 65536.0);
}
