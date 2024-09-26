/*
 * step.c
 *
 * Created: 21/09/2024 00:21:19
 *  Author: DELL
 */ 
#include "step.h"

uint8_t i = 0;
uint8_t *coil = &i;
void Stepper_voidInit()
{
    DIO_init(PORT_C, PIN0, OUTPUT);
    DIO_init(PORT_C, PIN1, OUTPUT);
    DIO_init(PORT_C, PIN2, OUTPUT);
    DIO_init(PORT_C, PIN3, OUTPUT);

    DIO_write(PORT_C , PIN0, LOW);
    DIO_write(PORT_C , PIN1, LOW);
    DIO_write(PORT_C , PIN2, LOW);
    DIO_write(PORT_C , PIN3, LOW);
}

void Stepper_voidOff()
{
    DIO_write(PORT_C , PIN3, LOW);
    DIO_write(PORT_C , PIN2, LOW);
    DIO_write(PORT_C , PIN1, LOW);
    DIO_write(PORT_C , PIN0, LOW);
}
void step(uint16_t Degree,uint16_t *current_degree, uint16_t speed)
{
    uint16_t degree_copy = Degree;
    uint16_t current_degree_copy = *current_degree;
    if(Degree > *current_degree)
    {
        if(Degree - *current_degree <= 180)
        {
            degree_copy = Degree;
            current_degree_copy = *current_degree;
        }
        else
        {
            degree_copy = 0;
            current_degree_copy = *current_degree + (360-Degree);
        }
    }
    else if(Degree < *current_degree)
    {
        if(*current_degree - Degree <= 180)
        {
            degree_copy = Degree;
            current_degree_copy = *current_degree;
        }
        else
        {
            degree_copy = Degree + (360-*current_degree);
            current_degree_copy = 0;
        }
    }

    uint16_t delay_val = 1250 / speed;
    uint8_t PINS[4] = {PIN0 , PIN1 ,PIN2 , PIN3};
    if(degree_copy > current_degree_copy)
        {
            uint8_t Steps = (degree_copy - current_degree_copy) / 7.5;
            while(Steps > 0)
            {

                if(*coil < 3)
                {
                    DIO_write(PORT_C , PINS[*coil] , HIGH);
                    DIO_write(PORT_C , PINS[*coil+1] , HIGH);
                    delay(delay_val);
                    DIO_write(PORT_C , PINS[*coil] , LOW);
                    DIO_write(PORT_C , PINS[*coil+1] , LOW);
                }
                else if(*coil == 3)
                {
                    DIO_write(PORT_C , PINS[3] , HIGH);
                    DIO_write(PORT_C , PINS[0] , HIGH);
                    delay(delay_val);
                    DIO_write(PORT_C , PINS[3] , LOW);
                    DIO_write(PORT_C , PINS[0] , LOW);
                }
                Steps--;
                (*coil)++;
                if(*coil == 4)
                {
                    *coil = 0;
                }
            }
            *current_degree = Degree;
        }
    else if(degree_copy < current_degree_copy)
        {

            uint16_t Steps = (current_degree_copy - degree_copy) / 7.5;
            while(Steps > 0)
            {
                (*coil)++;
                if(*coil == 4)
                {
                    *coil = 0;
                }
                if(*coil == 0)
                {
                    DIO_write(PORT_C , PINS[0] , HIGH);
                    DIO_write(PORT_C , PINS[3] , HIGH);
                    delay(delay_val);
                    DIO_write(PORT_C , PINS[0] , LOW);
                    DIO_write(PORT_C , PINS[3] , LOW);
                }
                else if(*coil == 1)
                {
                    DIO_write(PORT_C , PINS[2] , HIGH);
                    DIO_write(PORT_C , PINS[3] , HIGH);
                    delay(delay_val);
                    DIO_write(PORT_C , PINS[2] , LOW);
                    DIO_write(PORT_C , PINS[3] , LOW);
                }
                else if(*coil == 2)
                {
                    DIO_write(PORT_C , PINS[2] , HIGH);
                    DIO_write(PORT_C , PINS[1] , HIGH);
                    delay(delay_val);
                    DIO_write(PORT_C , PINS[2] , LOW);
                    DIO_write(PORT_C , PINS[1] , LOW);
                }
                else if(*coil == 3)
                {
                    DIO_write(PORT_C , PINS[1] , HIGH);
                    DIO_write(PORT_C , PINS[0] , HIGH);
                    delay(delay_val);
                    DIO_write(PORT_C , PINS[1] , LOW);
                    DIO_write(PORT_C , PINS[0] , LOW);
                }

                Steps--;

            }
            *current_degree = Degree;
        }






}
void Stepper_voidOn_Speed(uint8_t Direction,uint16_t Speed)
{
    uint8_t PINS[4] = {PIN0 , PIN1 ,PIN2 , PIN3};
    uint16_t delay_val = 1250 / Speed;
    if(Direction == Stepper_CCW)
    {
        if(*coil < 3)
        {
            DIO_write(PORT_C , PINS[*coil] , HIGH);
            DIO_write(PORT_C , PINS[*coil+1] , HIGH);
            delay(delay_val);
            DIO_write(PORT_C , PINS[*coil] , LOW);
            DIO_write(PORT_C , PINS[*coil+1] , LOW);
        }
        else if(*coil == 3)
        {
            DIO_write(PORT_C , PINS[3] , HIGH);
            DIO_write(PORT_C , PINS[0] , HIGH);
            delay(delay_val);
            DIO_write(PORT_C , PINS[3] , LOW);
            DIO_write(PORT_C , PINS[0] , LOW);
        }
        (*coil)++;
        if(*coil == 4)
        {
            *coil = 0;
        }
    }
    else if(Direction == Stepper_CW)
    {
        (*coil)++;
        if(*coil == 4)
        {
            *coil = 0;
        }
        if(*coil == 0)
        {
            DIO_write(PORT_C , PINS[0] , HIGH);
            DIO_write(PORT_C , PINS[3] , HIGH);
            delay(delay_val);
            DIO_write(PORT_C , PINS[0] , LOW);
            DIO_write(PORT_C , PINS[3] , LOW);
            DIO_toggle(PORT_D , PIN0);
        }
        else if(*coil == 1)
        {
            DIO_write(PORT_C , PINS[2] , HIGH);
            DIO_write(PORT_C , PINS[3] , HIGH);
            delay(delay_val);
            DIO_write(PORT_C , PINS[2] , LOW);
            DIO_write(PORT_C , PINS[3] , LOW);
            DIO_toggle(PORT_D , PIN1);
        }
        else if(*coil == 2)
        {
            DIO_write(PORT_C , PINS[2] , HIGH);
            DIO_write(PORT_C , PINS[1] , HIGH);
            delay(delay_val);
            DIO_write(PORT_C , PINS[2] , LOW);
            DIO_write(PORT_C , PINS[1] , LOW);
            DIO_toggle(PORT_D , PIN2);
        }
        else if(*coil == 3)
        {
            DIO_write(PORT_C , PINS[1] , HIGH);
            DIO_write(PORT_C , PINS[0] , HIGH);
            delay(delay_val);
            DIO_write(PORT_C , PINS[1] , LOW);
            DIO_write(PORT_C , PINS[0] , LOW);
            DIO_toggle(PORT_D , PIN3);
        }
    }
}





