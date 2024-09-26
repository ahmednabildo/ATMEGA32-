/*
 * interrupts.h
 *
 * Created: 31/03/2024 09:14:55
 *  Author: DELL
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../../bit_wise.h"
#include "../../data_types.h"
#include "../../REGISTERS.h"

#define LOW_LEVEL 0
#define ANY_LOGICAL_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3

#define INT_0 4
#define INT_1 5
#define INT_2 6
/* External Interrupt Request 0 */
#define EXT_INT_0 __vector_1
/* External Interrupt Request 1 */
#define EXT_INT_1 __vector_2
/* External Interrupt Request 2 */
#define EXT_INT_2 __vector_3
/* Macro defines the ISR */
#define ISR(INT_VECT)void INT_VECT(void)__attribute__((signal,used)); \
void INT_VECT(void)

typedef struct
{
    uint8_t interrupt_channel;
    uint8_t Sense_control;
}external_interruptConfiguration_t;






void external_interrupts_enable();
void external_interrupt0_enable();
void external_interrupt1_enable();
void external_interrupt2_enable();
void external_interrupts_configuration(external_interruptConfiguration_t *confg);
void external_interrupts_flag_status(external_interruptConfiguration_t *confg , uint8_t *state);
void external_interrupts_flag_clear(external_interruptConfiguration_t *confg);


#endif /* INTERRUPTS_H_ */