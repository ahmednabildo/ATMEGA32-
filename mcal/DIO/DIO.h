/*
 * DIO.h
 *
 * Created: 29/03/2024 06:50:05
 *  Author: DELL
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../REGISTERS.h"
#include "../../BIT_WISE.h"

//***********************************************************includes****************************************************************
#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH (uint8_t)0x01

#define port_input 0x00
#define port_output 0xff

#define port_low 0x00
#define port_high 0xff


#define PORT_A 1
#define PORT_B 2
#define PORT_C 3
#define PORT_D 4

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//**************************************functions*************************************
void PORT_INIT(uint8_t port_nu, uint8_t direction);
void PORT_WRITE(uint8_t port_nu, uint8_t value);
void PORT_TOGGLE(uint8_t port_nu);


void DIO_init(uint8_t port_nu , uint8_t pin_nu , uint8_t direction);
void DIO_read(uint8_t port_nu , uint8_t pin_nu , uint8_t *value);
void DIO_write(uint8_t port_nu , uint8_t pin_nu , uint8_t value);
void DIO_toggle(uint8_t port_nu , uint8_t pin_nu);



#endif /* DIO_H_ */