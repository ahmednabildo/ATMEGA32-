/*
 * button.h
 *
 * Created: 29/03/2024 07:47:29
 *  Author: DELL
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../mcal/DIO/DIO.h"

void BUTTON_init(uint8_t button_port , uint8_t button_pin);
void BUTTON_read(uint8_t button_port , uint8_t button_pin , uint8_t *value);





#endif /* BUTTON_H_ */