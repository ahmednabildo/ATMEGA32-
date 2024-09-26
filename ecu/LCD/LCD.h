/*
 * LCD.h
 *
 * Created: 03/04/2024 07:02:45
 *  Author: DELL
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "../../mcal/DIO/DIO.h"
#include "../../mcal/TIMERS/timers.h"


typedef struct
{
    uint8_t PORT_NUMBER;
    uint8_t PORT_NUMBER_control;
    uint8_t rs;
    uint8_t rw;
    uint8_t en;
}LCD_8_BITConfiguration_t;

typedef struct
{
    uint8_t PORT_NUMBER;
    uint8_t PINS[4];
    uint8_t PORT_NUMBER_control;
    uint8_t rs;
    uint8_t rw;
    uint8_t en;
}LCD_4_BITConfiguration_t;

#define LCD_8_BIT_MODE 0x38
#define LCD_8_BIT_DISPLAY_ON_CURSOR_OFF 0x0C
#define LCD_8_BIT_AUTO_INCREMENT_CURSOR 0x06
#define LCD_8_BIT_CLEAR_DISPLAY 0x01
#define LCD_8_BIT_CURSOR_AT_HOME_POS 0x80

#define LCD_4_BIT_MODE 0x02
#define LCD_4_BIT_MODE_2_line_5_7_matrix 0x28
#define LCD_4_BIT_DISPLAY_ON_CURSOR_OFF 0x0c
#define LCD_4_BIT_AUTO_INCREMENT_CURSOR 0x06
#define LCD_4_BIT_CLEAR_DISPLAY 0x01
#define LCD_4_BIT_CURSOR_AT_HOME_POS 0x80

#define LCD_Port PORTA


void LCD_8_BIT_INIT(LCD_8_BITConfiguration_t * confg);
void LCD_8_BIT_SEND_COMMAND(LCD_8_BITConfiguration_t * confg , uint8_t command);
void LCD_8_BIT_SEND_CHAR(LCD_8_BITConfiguration_t * confg , uint8_t character);
void LCD_8_BIT_SEND_STRING(LCD_8_BITConfiguration_t * confg , uint8_t *string);
void LCD_8_BIT_cursor_pos(LCD_8_BITConfiguration_t * confg , uint8_t x , uint8_t y);

void LCD_4_BIT_SEND_4_BITS(LCD_4_BITConfiguration_t * confg , uint8_t command);
void LCD_4_BIT_INIT(LCD_4_BITConfiguration_t * confg);
void LCD_4_BIT_SEND_COMMAND(LCD_4_BITConfiguration_t * confg , uint8_t command);
void LCD_4_BIT_SEND_CHAR(LCD_4_BITConfiguration_t * confg , uint8_t character);
void LCD_4_BIT_SEND_STRING(LCD_4_BITConfiguration_t * confg , uint8_t *string);
void LCD_4_BIT_cursor_pos(LCD_4_BITConfiguration_t * confg , uint8_t x , uint8_t y);

#endif /* LCD_H_ */