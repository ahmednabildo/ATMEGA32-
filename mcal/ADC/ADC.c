/*
 * ADC.c
 *
 * Created: 01/04/2024 03:34:47
 *  Author: DELL
 */ 
#include "ADC.h"
void ADC_enable()
{
    SET_BIT(ADCSRA , 7);
}
void ADC_start()
{
    SET_BIT(ADCSRA , 6);
}


void ADC_interrupt_enable()
{
    SET_BIT(ADCSRA , 3);
}

void ADC_interrupt_flag_read(uint8_t *state)
{
    *state = READ_BIT(ADCSRA , 4);
}

void ADC_configuration(ADC_Configuration_t *confg)
{
    CLEAR_BIT(DDRA , confg->PIN);

    if(confg->REF == REF_AREF)
    {
        CLEAR_BIT(ADMUX , 6);
        CLEAR_BIT(ADMUX , 7);
    }
    else if(confg->REF == REF_AVCC)
    {
        SET_BIT(ADMUX , 6);
        CLEAR_BIT(ADMUX , 7);
    }
    else if(confg->REF == REF_internal)
    {
        SET_BIT(ADMUX , 6);
        SET_BIT(ADMUX , 7);
    }

    if(confg->adjustment_direction == left_adjustment)
    {
        SET_BIT(ADMUX , 5);
    }
    else if (confg->adjustment_direction ==right_adjustment)
    {
        CLEAR_BIT(ADMUX , 5);
    }

    if(confg->Pre_scalar == Pre_scalar_2)
    {
        CLEAR_BIT(ADCSRA , 0);
        CLEAR_BIT(ADCSRA , 1);
        CLEAR_BIT(ADCSRA , 2);
    }
    else if(confg->Pre_scalar == Pre_scalar_4)
    {
        CLEAR_BIT(ADCSRA , 0);
        SET_BIT(ADCSRA , 1);
        CLEAR_BIT(ADCSRA , 2);
    }
    else if(confg->Pre_scalar == Pre_scalar_8)
    {
        SET_BIT(ADCSRA , 0);
        SET_BIT(ADCSRA , 1);
        CLEAR_BIT(ADCSRA , 2);
    }
    else if(confg->Pre_scalar == Pre_scalar_16)
    {
        CLEAR_BIT(ADCSRA , 0);
        CLEAR_BIT(ADCSRA , 1);
        SET_BIT(ADCSRA , 2);
    }
    else if(confg->Pre_scalar == Pre_scalar_32)
    {
        SET_BIT(ADCSRA , 0);
        CLEAR_BIT(ADCSRA , 1);
        SET_BIT(ADCSRA , 2);
    }
    else if(confg->Pre_scalar == Pre_scalar_64)
    {
        CLEAR_BIT(ADCSRA , 0);
        SET_BIT(ADCSRA , 1);
        SET_BIT(ADCSRA , 2);
    }
    else if(confg->Pre_scalar == Pre_scalar_128)
    {
        SET_BIT(ADCSRA , 0);
        SET_BIT(ADCSRA , 1);
        SET_BIT(ADCSRA , 2);
    }

    if(confg->trigger == normal_trigger)
    {
        CLEAR_BIT(ADCSRA , 5);
    }
    else if(confg->trigger == auto_trigger)
    {
        SET_BIT(ADCSRA , 5);
        ADC_auto_trigger_mode_configuration(confg);
    }

    if(confg->Input_Channel_and_Gain == SINGLE_ENDED)
    {
        if(confg->PIN == channel_0)
        {
            CLEAR_BIT(ADMUX , 0);
            CLEAR_BIT(ADMUX , 1);
            CLEAR_BIT(ADMUX , 2);
            CLEAR_BIT(ADMUX , 3);
            CLEAR_BIT(ADMUX , 4);
        }
        else if(confg->PIN == channel_1)
        {
            SET_BIT(ADMUX , 0);
            CLEAR_BIT(ADMUX , 1);
            CLEAR_BIT(ADMUX , 2);
            CLEAR_BIT(ADMUX , 3);
            CLEAR_BIT(ADMUX , 4);
        }
        else if(confg->PIN == channel_2)
        {
            CLEAR_BIT(ADMUX , 0);
            SET_BIT(ADMUX , 1);
            CLEAR_BIT(ADMUX , 2);
            CLEAR_BIT(ADMUX , 3);
            CLEAR_BIT(ADMUX , 4);
        }
        else if(confg->PIN == channel_3)
        {
            SET_BIT(ADMUX , 0);
            SET_BIT(ADMUX , 1);
            CLEAR_BIT(ADMUX , 2);
            CLEAR_BIT(ADMUX , 3);
            CLEAR_BIT(ADMUX , 4);
        }
        else if(confg->PIN == channel_4)
        {
            CLEAR_BIT(ADMUX , 0);
            CLEAR_BIT(ADMUX , 1);
            SET_BIT(ADMUX , 2);
            CLEAR_BIT(ADMUX , 3);
            CLEAR_BIT(ADMUX , 4);
        }
        else if(confg->PIN == channel_5)
        {
            SET_BIT(ADMUX , 0);
            CLEAR_BIT(ADMUX , 1);
            SET_BIT(ADMUX , 2);
            CLEAR_BIT(ADMUX , 3);
            CLEAR_BIT(ADMUX , 4);
        }
        else if(confg->PIN == channel_6)
        {
            CLEAR_BIT(ADMUX , 0);
            SET_BIT(ADMUX , 1);
            SET_BIT(ADMUX , 2);
            CLEAR_BIT(ADMUX , 3);
            CLEAR_BIT(ADMUX , 4);
        }
        else if(confg->PIN == channel_7)
        {
            SET_BIT(ADMUX , 0);
            SET_BIT(ADMUX , 1);
            SET_BIT(ADMUX , 2);
            CLEAR_BIT(ADMUX , 3);
            CLEAR_BIT(ADMUX , 4);
        }
    }
    else if(confg->Input_Channel_and_Gain == POS_DIF)
    {

    }
    else if(confg->Input_Channel_and_Gain == NEG_DIF)
    {

    }

}
void ADC_auto_trigger_mode_configuration(ADC_Configuration_t *confg)
{
    if(confg->auto_mode == free_running_mode)
    {
        CLEAR_BIT(SFIOR , 5);
        CLEAR_BIT(SFIOR , 6);
        CLEAR_BIT(SFIOR , 7);
    }
    else if(confg->auto_mode == analog_comparator)
    {
        SET_BIT(SFIOR , 5);
        CLEAR_BIT(SFIOR , 6);
        CLEAR_BIT(SFIOR , 7);
    }
    else if(confg->auto_mode == EXT_INT__0)
    {
        CLEAR_BIT(SFIOR , 5);
        SET_BIT(SFIOR , 6);
        CLEAR_BIT(SFIOR , 7);
    }
    else if(confg->auto_mode == TIMER_0_COMPARE)
    {
        SET_BIT(SFIOR , 5);
        SET_BIT(SFIOR , 6);
        CLEAR_BIT(SFIOR , 7);
    }
    else if(confg->auto_mode == TIMER_0_OVERFLOW)
    {
        CLEAR_BIT(SFIOR , 5);
        CLEAR_BIT(SFIOR , 6);
        SET_BIT(SFIOR , 7);
    }
    else if(confg->auto_mode == TIMER_1_COMPARE)
    {
        SET_BIT(SFIOR , 5);
        CLEAR_BIT(SFIOR , 6);
        SET_BIT(SFIOR , 7);
    }
    else if(confg->auto_mode == TIMER_1_OVERFLOW)
    {
        CLEAR_BIT(SFIOR , 5);
        SET_BIT(SFIOR , 6);
        SET_BIT(SFIOR , 7);
    }
    else if(confg->auto_mode == TIMER_1_CAPTURE_EVENT)
    {
        SET_BIT(SFIOR , 5);
        SET_BIT(SFIOR , 6);
        SET_BIT(SFIOR , 7);
    }
    else if(confg->auto_mode == not_auto)
    {

    }

}

void ADC_get_conversion_value(ADC_Configuration_t *confg , uint32__t *value)
{
    if(confg->adjustment_direction == left_adjustment)
    {
        *value = (ADCL >> 6) + (ADCH << 2);
    }
    else if(confg->adjustment_direction == right_adjustment)
    {
        *value = ADCL + (ADCH << 8);
    }
    //SET_BIT(ADCSRA , 4);
}


