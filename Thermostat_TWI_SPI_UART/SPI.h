/*
 * SPI.h
 *
 * Created: 13.09.2022 14:02:51
 *  Author: vadim
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "main.h"

#define SS   PB2
#define MOSI PB3
#define MISO PB4
#define SCK  PB5


void SPI_master_init(void);                               // SPI initialization function;

void SPI_master_transmit(char cData);                     // SPI data send function; 

void SPI_send_t_h(float temperature, float humidity);     // Function sends temperature and humidity to slave microcontroller;


#endif /* SPI_H_ */