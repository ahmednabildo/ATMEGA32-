/*
 * step.h
 *
 * Created: 21/09/2024 00:21:03
 *  Author: DELL
 */ 


#ifndef STEP_H_
#define STEP_H_


#include "../../mcal/DIO/DIO.h"
#include "../../mcal/TIMERS/timers.h"
#define Stepper_FullStep				1
#define Stepper_HalfStep				2
#define Stepper_CW					1
#define Stepper_CCW					2

void Stepper_voidInit();
void Stepper_voidOff();
void Stepper_voidOn_Speed(uint8_t Direction,uint16_t Speed);
void step(uint16_t Degree,uint16_t *current_degree, uint16_t speed);
#endif /* STEP_H_ */