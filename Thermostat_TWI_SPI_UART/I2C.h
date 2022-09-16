/*
 * I2C.h
 *
 * Created: 05.09.2022 13:13:13
 *  Author: vadim
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "main.h"

void I2C_settings(void);                                        //Function TWI/I2C settings;  

void I2C_start_condition(void);                                 //TWI/I2C start condition function;                

void I2C_stop_condition(void);                                  //TWI/I2C stop condition function;

void I2C_write_command(unsigned char command);                  //Set command TWI;

unsigned char I2C_get_ACK_data(void);                           //Function returns one byte data from the sensor;

void I2C_NACK_checksum(void);                                   //Checksum transmission;

void I2C_get_t_h_data(float *temperature, float *humidity);     //Function sets value temperature and humidity;


#endif /* I2C_H_ */