/*
 * button.c
 *
 * Created: 29/03/2024 07:47:44
 *  Author: DELL
 */ 
#include "button.h"

void BUTTON_init(uint8_t button_port , uint8_t button_pin)
{
	DIO_init(button_port , button_pin , INPUT);
}
void BUTTON_read(uint8_t button_port , uint8_t button_pin , uint8_t *value)
{
	DIO_read(button_port , button_pin , value);
	
}
