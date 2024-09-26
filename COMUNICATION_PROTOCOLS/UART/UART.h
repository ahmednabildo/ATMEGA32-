/*
 * UART.h
 *
 * Created: 05/04/2024 06:36:33
 *  Author: DELL
 */ 


#ifndef UART_H_
#define UART_H_
#include "../../bit_wise.h"
#include "../../data_types.h"
#include "../../REGISTERS.h"

#define normal_speed 0
#define double_speed 1

#define Asynchronous 0
#define Synchronous 1
#define Multi_processor_Communication_Mode 2

#define INT_EN 0
#define INT_DIS 1

#define NO_PARITY 0
#define ODD_PARITY 1
#define EVEN_PARITY 2

#define STOP_BIT_1 0
#define STOP_BIT_2 1

#define DATA_BITS_5 0
#define DATA_BITS_6 1
#define DATA_BITS_7 2
#define DATA_BITS_8 3
#define DATA_BITS_9 4

#define Receiver_mode 0
#define Transmitter_mode 1
#define Rec_and_Trans 2

typedef struct
{
    uint8_t trans_speed;
    uint8_t Baud_RATE;
    uint8_t mode;
    uint8_t Rec_or_trans_or_both;
    uint8_t interrupt;
    uint8_t PARITY;
    uint8_t NO_OF_STOP_BITS;
    uint8_t NO_OF_DATA_BITS;
}UART_Configuration_t;

void UART_INIT(UART_Configuration_t *confg);
void UART_TRANS(uint8_t data);
void UART_REC(uint8_t *data);
//void UART_REC(UART_Configuration_t *confg , uint16_t *data);



#endif /* UART_H_ */