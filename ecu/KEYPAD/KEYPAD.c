/*
 * KEYPAD.c
 *
 * Created: 04/04/2024 12:17:15
 *  Author: DELL
 */ 
#include "KEYPAD.h"
static const uint8_t btn_values [ROWS_NUM][COLS_NUM] = {	{'7' , '8' , '9' , '/'},
                                                            {'4' , '5' , '6' , '*'},
                                                            {'1' , '2' , '3' , '+'},
                                                            {'#' , '0' , '=' , '-'}


};
void KEYPAD_INIT(KEYPAD_Configuration_t *confg)
{
    for (uint8_t i = 0; i < ROWS_NUM; ++i)
    {
        DIO_init(confg->port_ROWS , confg->ROWS[i] , OUTPUT);
        DIO_write(confg->port_ROWS , confg->ROWS[i] , LOW);
    }

    for (uint8_t i = 0; i < COLS_NUM ; ++i)
    {
        DIO_init(confg->port_COLS , confg->COLS[i] , INPUT);
    }
}
void KEYPAD_READ(KEYPAD_Configuration_t *confg , uint8_t *value)
{
	uint8_t state = LOW;
	for (uint8_t i = 0; i < ROWS_NUM; ++i)
	{
		for (uint8_t j = 0; j < ROWS_NUM; ++j)
		{
			DIO_write(confg->port_ROWS , confg->ROWS[j] , LOW);
		}
		DIO_write(confg->port_ROWS , confg->ROWS[i] , HIGH);
		delay(50);
		for (uint8_t j = 0; j < COLS_NUM; ++j)
		{
			DIO_read(confg->port_COLS , confg->COLS[j] , &state);
			if(state != LOW)
			{
				*value = btn_values[i][j];
			}
		}
	}
}