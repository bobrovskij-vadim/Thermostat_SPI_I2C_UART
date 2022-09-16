/*
 * SPI.h
 *
 * Created: 13.09.2022 15:51:51
 *  Author: vadim
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "main.h"

#define SS   PB2
#define MOSI PB3
#define MISO PB4
#define SCK  PB5


void SPI_slave_init(void);                             // SPI slave initialization function;

char SPI_slave_receive(void);                          // SPI slave receive data;

void SPI_get_t_h(char *temperature, char *humidity);   // Function displays current temperature and humidity from master MC;  


#endif /* SPI_H_ */