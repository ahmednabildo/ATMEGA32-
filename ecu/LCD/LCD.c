/*
 * LCD.c
 *
 * Created: 03/04/2024 07:03:00
 *  Author: DELL
 */ 
#include "LCD.h"
void LCD_8_BIT_INIT(LCD_8_BITConfiguration_t * confg)
{
    PORT_INIT(confg->PORT_NUMBER , port_output);
    DIO_init(confg->PORT_NUMBER_control , confg->rs , OUTPUT);
    DIO_init(confg->PORT_NUMBER_control , confg->rw , OUTPUT);
    DIO_init(confg->PORT_NUMBER_control , confg->en , OUTPUT);
    delay(25);

    LCD_8_BIT_SEND_COMMAND(confg , LCD_8_BIT_MODE);
    LCD_8_BIT_SEND_COMMAND(confg , LCD_8_BIT_DISPLAY_ON_CURSOR_OFF);
    LCD_8_BIT_SEND_COMMAND(confg , LCD_8_BIT_AUTO_INCREMENT_CURSOR);
    LCD_8_BIT_SEND_COMMAND(confg , LCD_8_BIT_CLEAR_DISPLAY);
    LCD_8_BIT_SEND_COMMAND(confg , LCD_8_BIT_CURSOR_AT_HOME_POS);

}
void LCD_8_BIT_SEND_COMMAND(LCD_8_BITConfiguration_t * confg , uint8_t command)
{
    PORT_WRITE(confg->PORT_NUMBER , command);
    DIO_write(confg->PORT_NUMBER_control , confg->rs , LOW);
    DIO_write(confg->PORT_NUMBER_control , confg->rw , LOW);

    DIO_write(confg->PORT_NUMBER_control , confg->en , HIGH);
    delay(10);
    DIO_write(confg->PORT_NUMBER_control , confg->en , LOW);
    delay(10);
}
void LCD_8_BIT_SEND_CHAR(LCD_8_BITConfiguration_t * confg , uint8_t character)
{
    PORT_WRITE(confg->PORT_NUMBER , character);
    DIO_write(confg->PORT_NUMBER_control , confg->rs , HIGH);
    DIO_write(confg->PORT_NUMBER_control , confg->rw , LOW);
    DIO_write(confg->PORT_NUMBER_control , confg->en , HIGH);
    delay(10);
    DIO_write(confg->PORT_NUMBER_control , confg->en , LOW);
    delay(10);
}
void LCD_8_BIT_SEND_STRING(LCD_8_BITConfiguration_t * confg , uint8_t *string)
{
    for (uint16_t i = 0; string[i] != '\0' ; i++)
    {
        //LCD_8_BIT_SEND_CHAR(confg , string[i]);
        if (i==16)
        {
            LCD_8_BIT_SEND_COMMAND(confg , 0xc0);
        }
        LCD_8_BIT_SEND_CHAR(confg , string[i]);
    }
}
void LCD_8_BIT_cursor_pos(LCD_8_BITConfiguration_t * confg , uint8_t x , uint8_t y)
{
    uint8_t pos = 0;
    if (x == 0)
    {
        pos = 0x80;
    }
    else if(x == 1)
    {
        pos = 0xc0;
    }
    if(y < 16)
    {
        pos+=y;
    }
    LCD_8_BIT_SEND_COMMAND(confg , pos);
}


void LCD_4_BIT_INIT(LCD_4_BITConfiguration_t * confg)
{
    PORT_INIT(confg->PORT_NUMBER , port_output);			/* Make LCD port direction as o/p */
    delay(20); /* LCD Power ON delay always >15ms */
    LCD_4_BIT_SEND_COMMAND(confg , 0x02);		/* send for 4 bit initialization of LCD  */
    LCD_4_BIT_SEND_COMMAND(confg ,0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
    LCD_4_BIT_SEND_COMMAND(confg ,0x0c);              /* Display on cursor off*/
    LCD_4_BIT_SEND_COMMAND(confg ,0x06);              /* Increment cursor (shift cursor to right)*/
    LCD_4_BIT_SEND_COMMAND(confg ,0x01);              /* Clear display screen*/
    delay(2);
}
void LCD_4_BIT_SEND_COMMAND(LCD_4_BITConfiguration_t * confg , uint8_t command)
{
    /* sending upper nibble */
    if(confg->PORT_NUMBER == PORT_A)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTA & 0x0F) | (command & 0xF0)); /* sending upper nibble */
    }
    else if(confg->PORT_NUMBER == PORT_B)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTB & 0x0F) | (command & 0xF0)); /* sending upper nibble */
    }
    else if(confg->PORT_NUMBER == PORT_C)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTC & 0x0F) | (command & 0xF0)); /* sending upper nibble */
    }
    else if(confg->PORT_NUMBER == PORT_D)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTD & 0x0F) | (command & 0xF0)); /* sending upper nibble */
    }
    DIO_write(confg->PORT_NUMBER_control , confg->rs , LOW);	/* RS=1, data reg. */
    DIO_write(confg->PORT_NUMBER_control , confg->en , HIGH);
    delay(1);
    DIO_write(confg->PORT_NUMBER_control , confg->en , LOW);
    delay(1);

    /* sending lower nibble */
    if(confg->PORT_NUMBER == PORT_A)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTA & 0x0F) | (command << 4)); /* sending upper nibble */
    }
    else if(confg->PORT_NUMBER == PORT_B)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTB & 0x0F) | (command << 4)); /* sending upper nibble */
    }
    else if(confg->PORT_NUMBER == PORT_C)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTC & 0x0F) | (command << 4)); /* sending upper nibble */
    }
    else if(confg->PORT_NUMBER == PORT_D)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTD & 0x0F) | (command << 4)); /* sending upper nibble */
    }
    DIO_write(confg->PORT_NUMBER_control , confg->en , HIGH);
    delay(1);
    DIO_write(confg->PORT_NUMBER_control , confg->en , LOW);
    delay(2);




}
void LCD_4_BIT_SEND_CHAR(LCD_4_BITConfiguration_t * confg , uint8_t character)
{
    if(confg->PORT_NUMBER == PORT_A)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTA & 0x0F) | (character & 0xF0)); /* sending upper nibble */
    }
    else if(confg->PORT_NUMBER == PORT_B)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTB & 0x0F) | (character & 0xF0)); /* sending upper nibble */
    }
    else if(confg->PORT_NUMBER == PORT_C)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTC & 0x0F) | (character & 0xF0)); /* sending upper nibble */
    }
    else if(confg->PORT_NUMBER == PORT_D)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTD & 0x0F) | (character & 0xF0)); /* sending upper nibble */
    }

    DIO_write(confg->PORT_NUMBER_control , confg->rs , HIGH);	/* RS=1, data reg. */
    DIO_write(confg->PORT_NUMBER_control , confg->en , HIGH);
    delay(1);
    DIO_write(confg->PORT_NUMBER_control , confg->en , LOW);
    delay(1);

    /* sending lower nibble */
    if(confg->PORT_NUMBER == PORT_A)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTA & 0x0F) | (character << 4)); /* sending upper nibble */
    }
    else if(confg->PORT_NUMBER == PORT_B)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTB & 0x0F) | (character << 4)); /* sending upper nibble */
    }
    else if(confg->PORT_NUMBER == PORT_C)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTC & 0x0F) | (character << 4)); /* sending upper nibble */
    }
    else if(confg->PORT_NUMBER == PORT_D)
    {
        PORT_WRITE(confg->PORT_NUMBER , (PORTD & 0x0F) | (character << 4)); /* sending upper nibble */
    }
    DIO_write(confg->PORT_NUMBER_control , confg->en , HIGH);
    delay(1);
    DIO_write(confg->PORT_NUMBER_control , confg->en , LOW);
    delay(2);


}
void LCD_4_BIT_SEND_STRING(LCD_4_BITConfiguration_t * confg , uint8_t *string)
{
    for (uint16_t i = 0; string[i] != '\0'; ++i)
    {
        if (i==16)
        {
            LCD_4_BIT_SEND_COMMAND(confg , 0xc0);
        }
        LCD_4_BIT_SEND_CHAR(confg , string[i]);
    }
}
void LCD_4_BIT_cursor_pos(LCD_4_BITConfiguration_t * confg , uint8_t x , uint8_t y)
{
    uint8_t pos = 0;
    if (x == 0)
    {
        pos = 0x80;
    }
    else if(x == 1)
    {
        pos = 0xc0;
    }
    if(y < 16)
    {
        pos+=y;
    }
    LCD_4_BIT_SEND_COMMAND(confg , pos);
}