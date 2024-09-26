#include "mcal/DIO/DIO.h"
#include "ecu/LCD/LCD.h"
#include "mcal/TIMERS/timers.h"
#include "ecu/button/button.h"
#include "mcal/INTERRUPTS/interrupts.h"
#include "ecu/STEP/step.h"
#include <stdlib.h>

LCD_4_BITConfiguration_t confg_4_BIT;
LCD_4_BITConfiguration_t *ptr_4_BIT = &confg_4_BIT;

int main(void)
{

    BUTTON_init(PORT_B , PIN0);
    BUTTON_init(PORT_B , PIN1);
    uint8_t state_in = 0;
    uint8_t state_de = 0;

    //LCD confg buttons
    confg_4_BIT.PORT_NUMBER = PORT_A;
    confg_4_BIT.PORT_NUMBER_control = PORT_A;
    confg_4_BIT.PINS[0] = 4;
    confg_4_BIT.PINS[1] = 5;
    confg_4_BIT.PINS[2] = 6;
    confg_4_BIT.PINS[3] = 7;
    confg_4_BIT.en = PIN0;
    confg_4_BIT.rs = PIN1;
    confg_4_BIT.rw = PIN2;
    LCD_4_BIT_INIT(ptr_4_BIT);

    uint8_t string[15] = "The angle is :";
    LCD_4_BIT_SEND_STRING(&confg_4_BIT,string);
    Stepper_voidInit();
    uint16_t current_degree = 0;
    int degree = 0;
    int cycles = 0;
    uint8_t buffer[10] ={0};
    int c = 0;
    int d = 0;
    while (1)
    {
        Stepper_voidOn_Speed(Stepper_CCW , 5);
        BUTTON_read(PORT_B , PIN0 , &state_in);
        BUTTON_read(PORT_B , PIN1 , &state_de);
        if(state_in == 1)
        {
            degree += 15;

        }
        if(state_de == 1)
        {

            degree -= 15;
            if(degree < 0)
            {
                degree +=360;
            }

        }
        if(degree>=360)
        {
            degree-=360;
            cycles++;
        }

        itoa(degree, buffer, 10);
        step(degree , &current_degree , 5);
        if(degree == 0)
        {
            if(c == 0)
            {
                LCD_4_BIT_INIT(ptr_4_BIT);

                uint8_t string[15] = "The angle is :";
                LCD_4_BIT_SEND_STRING(&confg_4_BIT,string);
                LCD_4_BIT_cursor_pos(&confg_4_BIT,1,0);
                LCD_4_BIT_SEND_STRING(&confg_4_BIT,buffer);
                c++;
            }
            else
            {
                LCD_4_BIT_cursor_pos(&confg_4_BIT,1,0);
                LCD_4_BIT_SEND_STRING(&confg_4_BIT,buffer);
            }

        }
        else if(degree == 90)
        {
            if(d == 0)
            {
                LCD_4_BIT_INIT(ptr_4_BIT);

                uint8_t string[15] = "The angle is :";
                LCD_4_BIT_SEND_STRING(&confg_4_BIT,string);
                LCD_4_BIT_cursor_pos(&confg_4_BIT,1,0);
                LCD_4_BIT_SEND_STRING(&confg_4_BIT,buffer);
                d++;
            }
            else
            {
                LCD_4_BIT_cursor_pos(&confg_4_BIT,1,0);
                LCD_4_BIT_SEND_STRING(&confg_4_BIT,buffer);
            }
        }
        else
        {
            LCD_4_BIT_cursor_pos(&confg_4_BIT,1,0);
            LCD_4_BIT_SEND_STRING(&confg_4_BIT,buffer);
            c = 0;
            d = 0;
        }


    }

}