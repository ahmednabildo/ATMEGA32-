/*
 *UART.c
 *
 * Created: 05/04/2024 06:36:41
 *  Author: DELL
 */ 
#include "UART.h"


void UART_INIT(UART_Configuration_t *confg)
{
    UBRRH = (uint8_t)((confg->Baud_RATE) >> 8);
    UBRRL = (uint8_t)(confg->Baud_RATE);

    SET_BIT(UCSRC , 7);

    if(confg->Rec_or_trans_or_both == Receiver_mode)
    {
        SET_BIT(UCSRB , 4);
    }
    else if(confg->Rec_or_trans_or_both == Transmitter_mode)
    {
        SET_BIT(UCSRB , 3);
    }
    else if(confg->Rec_or_trans_or_both == Rec_and_Trans)
    {
        SET_BIT(UCSRB , 3);
        SET_BIT(UCSRB , 4);
    }



    if(confg->interrupt == INT_EN)
    {
        SET_BIT(UCSRB , 7);
        SET_BIT(UCSRB , 6);
        SET_BIT(UCSRB , 5);
    }
    else if(confg->interrupt == INT_DIS)
    {
        CLEAR_BIT(UCSRB , 7);
        CLEAR_BIT(UCSRB , 6);
        CLEAR_BIT(UCSRB , 5);
    }



    if(confg->NO_OF_DATA_BITS == DATA_BITS_5)
    {

        CLEAR_BIT(UCSRC , 1);
        CLEAR_BIT(UCSRC , 2);
        CLEAR_BIT(UCSRB , 2);
    }
    else if(confg->NO_OF_DATA_BITS == DATA_BITS_6)
    {
        SET_BIT(UCSRC , 1);
        CLEAR_BIT(UCSRC , 2);
        CLEAR_BIT(UCSRB , 2);
    }
    else if(confg->NO_OF_DATA_BITS == DATA_BITS_7)
    {
        CLEAR_BIT(UCSRC , 1);
        SET_BIT(UCSRC , 2);
        CLEAR_BIT(UCSRB , 2);
    }
    else if(confg->NO_OF_DATA_BITS == DATA_BITS_8)
    {
        SET_BIT(UCSRC , 1);
        SET_BIT(UCSRC , 2);
        CLEAR_BIT(UCSRB , 2);
    }
    else if(confg->NO_OF_DATA_BITS == DATA_BITS_9)
    {
        SET_BIT(UCSRC , 1);
        SET_BIT(UCSRC , 2);
        SET_BIT(UCSRB , 2);
    }

    if(confg->PARITY == NO_PARITY)
    {
        CLEAR_BIT(UCSRC , 4);
        CLEAR_BIT(UCSRC , 5);
    }
    else if(confg->PARITY == ODD_PARITY)
    {
        SET_BIT(UCSRC , 4);
        SET_BIT(UCSRC , 5);
    }
    else if(confg->PARITY == EVEN_PARITY)
    {
        CLEAR_BIT(UCSRC , 4);
        SET_BIT(UCSRC , 5);
    }

    if(confg->NO_OF_STOP_BITS == STOP_BIT_1)
    {
        CLEAR_BIT(UCSRC , 3);
    }
    else if(confg->NO_OF_STOP_BITS == STOP_BIT_2)
    {
        SET_BIT(UCSRC , 3);
    }

    if(confg->trans_speed == normal_speed)
    {
        CLEAR_BIT(UCSRA , 1);
    }
    else if(confg->trans_speed == double_speed)
    {
        SET_BIT(UCSRA , 1);
    }

    if(confg->mode == Asynchronous)
    {
        CLEAR_BIT(UCSRC , 6);
    }
    else if(confg->mode == Synchronous)
    {
        SET_BIT(UCSRC , 6);
    }
    else if(confg->mode == Multi_processor_Communication_Mode)
    {
        SET_BIT(UCSRA , 0);
    }
}
void UART_TRANS(uint8_t data)
{
    while(READ_BIT(UCSRA , 5) == 0);
    UDR = data;
}
void UART_REC(uint8_t *data)
{
    while(READ_BIT(UCSRA , 7) == 0);
    *data = UDR;
}