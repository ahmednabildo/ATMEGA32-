/*
 * ADC.h
 *
 * Created: 01/04/2024 03:34:34
 *  Author: DELL
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "../../bit_wise.h"
#include "../../REGISTERS.h"
#include "../../data_types.h"

#define channel_0 0
#define channel_1 1
#define channel_2 2
#define channel_3 3
#define channel_4 4
#define channel_5 5
#define channel_6 6
#define channel_7 7

#define SINGLE_ENDED 0
#define POS_DIF 1
#define NEG_DIF 2

#define REF_AREF 0
#define REF_AVCC 1
#define REF_internal 2

#define left_adjustment 0
#define right_adjustment 1

#define Pre_scalar_2 0
#define Pre_scalar_4 1
#define Pre_scalar_8 2
#define Pre_scalar_16 3
#define Pre_scalar_32 4
#define Pre_scalar_64 5
#define Pre_scalar_128 6

#define auto_trigger 0
#define normal_trigger 1


#define free_running_mode 0
#define analog_comparator 1
#define EXT_INT__0 2
#define TIMER_0_COMPARE 3
#define TIMER_0_OVERFLOW 4
#define TIMER_1_COMPARE 5
#define TIMER_1_OVERFLOW 6
#define TIMER_1_CAPTURE_EVENT 7
#define not_auto 8


typedef struct
{
    uint8_t PIN;
    uint8_t REF;
    uint8_t adjustment_direction;
    uint8_t Pre_scalar;
    uint8_t trigger;
    uint8_t auto_mode;
    uint8_t  Input_Channel_and_Gain;

}ADC_Configuration_t;

void ADC_enable();
void ADC_start();
void ADC_interrupt_enable();

void ADC_configuration(ADC_Configuration_t *confg);
void ADC_auto_trigger_mode_configuration(ADC_Configuration_t *confg);

void ADC_interrupt_flag_read(uint8_t *state);
void ADC_get_conversion_value(ADC_Configuration_t *confg , uint32__t *value);






#endif /* ADC_H_ */