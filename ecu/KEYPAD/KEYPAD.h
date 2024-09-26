/*
 * KEYPAD.h
 *
 * Created: 04/04/2024 12:17:02
 *  Author: DELL
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "../../mcal/DIO/DIO.h"
#include "../../mcal/TIMERS/timers.h"

#define ROWS_NUM 4
#define COLS_NUM 4

typedef struct
{
    uint8_t port_ROWS;
    uint8_t port_COLS;
    uint8_t ROWS[ROWS_NUM];
    uint8_t COLS[COLS_NUM];
}KEYPAD_Configuration_t;

void KEYPAD_INIT(KEYPAD_Configuration_t *confg);
void KEYPAD_READ(KEYPAD_Configuration_t *confg , uint8_t *value);





#endif /* KEYPAD_H_ */