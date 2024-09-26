/*
 * REGISTERS.h
 *
 * Created: 29/03/2024 06:48:54
 *  Author: DELL
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "data_types.h"
//PORTA
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA  *((volatile uint8_t*)0x39)
#define PORTA *((volatile uint8_t*)0x3B)

//PORTB
#define DDRB *((volatile uint8_t*)0x37)
#define PINB  *((volatile uint8_t*)0x36)
#define PORTB *((volatile uint8_t*)0x38)

//PORTC
#define DDRC *((volatile uint8_t*)0x34)
#define PINC  *((volatile uint8_t*)0x33)
#define PORTC *((volatile uint8_t*)0x35)

//PORTD
#define DDRD *((volatile uint8_t*)0x31)
#define PIND  *((volatile uint8_t*)0x30)
#define PORTD *((volatile uint8_t*)0x32)




//***********************************************************TIMERS****************************************************************

//TIMERS
#define TIFR *((volatile uint8_t*)0x58)
#define TIMSK *((volatile uint8_t*)0x59)
#define SREG *((volatile uint8_t*)0x5F)
//TIMER0
#define TCNT0 *((volatile uint8_t*)0x52)
#define TCCR0  *((volatile uint8_t*)0x53)
#define OCR0  *((volatile uint8_t*)0x5C)
//TIMER1
#define TCCR1A *((volatile uint8_t*)0x4F)
#define TCCR1B  *((volatile uint8_t*)0x4E)
#define TCNT1H  *((volatile uint8_t*)0x4D)
#define TCNT1L *((volatile uint8_t*)0x4C)
#define OCR1AH  *((volatile uint8_t*)0x4B)
#define OCR1AL  *((volatile uint8_t*)0x4A)
#define OCR1BH  *((volatile uint8_t*)0x49)
#define OCR1BL *((volatile uint8_t*)0x48)
#define ICR1H  *((volatile uint8_t*)0x47)
#define ICR1L  *((volatile uint8_t*)0x46)

//TIMER2
#define TCNT2 *((volatile uint8_t*)0x44)
#define TCCR2  *((volatile uint8_t*)0x45)
#define OCR2  *((volatile uint8_t*)0x43)


//***********************************************************INTERRUPTS****************************************************************
#define GICR *((volatile uint8_t*)0x5B)
#define GIFR  *((volatile uint8_t*)0x5A)
#define MCUCR  *((volatile uint8_t*)0x55)
#define MCUCSR *((volatile uint8_t*)0x54)

//***********************************************************ADC****************************************************************
#define ADMUX *((volatile uint8_t*)0x27)
#define ADCSRA  *((volatile uint8_t*)0x26)
#define SFIOR  *((volatile uint8_t*)0x50)
#define ADCH  *((volatile uint8_t*)0x25)
#define ADCL  *((volatile uint8_t*)0x24)
//***********************************************************UART****************************************************************
#define UDR   *((volatile uint8_t*)0x2C)
#define UCSRA *((volatile uint8_t*)0x2B)
#define UCSRB *((volatile uint8_t*)0x2A)
#define UCSRC *((volatile uint8_t*)0x40)
#define UBRRL *((volatile uint8_t*)0x29)
#define UBRRH *((volatile uint8_t*)0x40)
//***********************************************************UART****************************************************************
#define SPDR   *((volatile uint8_t*)0x2F)
#define SPSR *((volatile uint8_t*)0x2E)
#define SPCR *((volatile uint8_t*)0x2D)
#endif /* REGISTERS_H_ */