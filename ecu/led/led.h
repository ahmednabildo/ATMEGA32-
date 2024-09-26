/*
 * led.h
 *
 * Created: 29/03/2024 07:43:36
 *  Author: DELL
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../mcal/DIO/DIO.h"

void LED_init(uint8_t ledport , uint8_t ledpin);
void LED_on(uint8_t ledport , uint8_t ledpin);
void LED_off(uint8_t ledport , uint8_t ledpin);
void LED_toggle(uint8_t ledport , uint8_t ledpin);



#endif /* LED_H_ */