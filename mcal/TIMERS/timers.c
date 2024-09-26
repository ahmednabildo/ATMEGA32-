/*
 * timers.c
 *
 * Created: 30/03/2024 05:04:44
 *  Author: DELL
 */ 
#include "timers.h"
void timer_init()
{
    TCCR0 = 0x00;
    TCNT0 = 0x1E;
}
void delay(uint16_t x)
{

    for (uint16_t i = 0; i < x; ++i)
    {
        for (uint8_t j = 0; j <4 ; ++j)
        {
            TCNT0 = 0x1E;
            SET_BIT(TCCR0 , 0);
            while ((READ_BIT(TIFR , 0) )== 0);
            SET_BIT(TIFR , 0);
            TCCR0 = 0x00;
        }
    }
}
void delay_ms(Str_TimerConfiguration_t *Confg_S , uint16_t x)
{
    for (uint16_t i = 0; i < x; ++i)
    {
        for (uint16_t j = 0; j < 4; ++j)
        {
            Timer_Stop(TIMER0);
            Timer_Start(Confg_S ,117);
            Timer_Init(Confg_S);
            uint8_t flag ;
            Timer_Get_FlagStatus(Confg_S , &flag);
            while (flag == 0)
            {
                Timer_Get_FlagStatus(Confg_S , &flag);
            }
            SET_BIT(TIFR , 0);
            Timer_Stop(TIMER0);
        }

    }
}

void Timer_Init(Str_TimerConfiguration_t *Confg_S)
{
    if (Confg_S->Timer_Mode == TIMER_MODE)
    {
        if (Confg_S->timer_mode == normal_mode)
        {
            if(Confg_S->Timer_Channel == TIMER0)
            {

                if(Confg_S->Timer_Psc == NO_CLOCK_TIMER_0)
                {

                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_TIMER_0)
                {
                    SET_BIT(TCCR0 , 0);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_0)
                {
                    SET_BIT(TCCR0 , 1);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_0)
                {
                    SET_BIT(TCCR0 , 0);
                    SET_BIT(TCCR0 , 1);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_0)
                {
                    SET_BIT(TCCR0 , 2);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_1024_TIMER_0)
                {
                    SET_BIT(TCCR0 , 0);
                    SET_BIT(TCCR0 , 2);
                }

            }

            else if(Confg_S->Timer_Channel == TIMER2)
            {
                if(Confg_S->Timer_Psc == NO_CLOCK_TIMER_2)
                {

                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_TIMER_2)
                {
                    SET_BIT(TCCR2 , 0);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_2)
                {
                    SET_BIT(TCCR2 , 1);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_32_TIMER_2)
                {
                    SET_BIT(TCCR2 , 0);
                    SET_BIT(TCCR2 , 1);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_2)
                {
                    SET_BIT(TCCR2 , 2);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_128_TIMER_2)
                {
                    SET_BIT(TCCR2 , 0);
                    SET_BIT(TCCR2 , 2);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_2)
                {
                    SET_BIT(TCCR2 , 1);
                    SET_BIT(TCCR2 , 2);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_1024_TIMER_2)
                {
                    SET_BIT(TCCR2 , 0);
                    SET_BIT(TCCR2 , 1);
                    SET_BIT(TCCR2 , 2);
                }
            }
        }
        else if (Confg_S->timer_mode == ctc_mode)
        {
            if(Confg_S->Timer_Channel == TIMER0)
            {
                SET_BIT(TCCR0 , 3);
                if(Confg_S->Timer_Psc == NO_CLOCK_TIMER_0)
                {

                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_TIMER_0)
                {
                    SET_BIT(TCCR0 , 0);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_0)
                {
                    SET_BIT(TCCR0 , 1);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_0)
                {
                    SET_BIT(TCCR0 , 0);
                    SET_BIT(TCCR0 , 1);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_0)
                {
                    SET_BIT(TCCR0 , 2);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_1024_TIMER_0)
                {
                    SET_BIT(TCCR0 , 0);
                    SET_BIT(TCCR0 , 2);
                }

            }

            else if(Confg_S->Timer_Channel == TIMER2)
            {
                SET_BIT(TCCR2 , 3);
                if(Confg_S->Timer_Psc == NO_CLOCK_TIMER_2)
                {

                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_TIMER_2)
                {
                    SET_BIT(TCCR2 , 0);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_2)
                {
                    SET_BIT(TCCR2 , 1);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_32_TIMER_2)
                {
                    SET_BIT(TCCR2 , 0);
                    SET_BIT(TCCR2 , 1);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_2)
                {
                    SET_BIT(TCCR2 , 2);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_128_TIMER_2)
                {
                    SET_BIT(TCCR2 , 0);
                    SET_BIT(TCCR2 , 2);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_2)
                {
                    SET_BIT(TCCR2 , 1);
                    SET_BIT(TCCR2 , 2);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_1024_TIMER_2)
                {
                    SET_BIT(TCCR2 , 0);
                    SET_BIT(TCCR2 , 1);
                    SET_BIT(TCCR2 , 2);
                }
            }
        }
        else if (Confg_S->timer_mode == pwm_mode)
        {
            if (Confg_S->Timer_Channel==TIMER0)
            {
                SET_BIT(TCCR0 , 6);
                if(Confg_S->Timer_Psc == NO_CLOCK_TIMER_0)
                {

                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_TIMER_0)
                {
                    SET_BIT(TCCR0 , 0);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_0)
                {
                    SET_BIT(TCCR0 , 1);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_0)
                {
                    SET_BIT(TCCR0 , 0);
                    SET_BIT(TCCR0 , 1);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_0)
                {
                    SET_BIT(TCCR0 , 2);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_1024_TIMER_0)
                {
                    SET_BIT(TCCR0 , 0);
                    SET_BIT(TCCR0 , 2);
                }
            }
            else if (Confg_S->Timer_Channel==TIMER2)
            {
                SET_BIT(TCCR2 , 6);
                if(Confg_S->Timer_Psc == NO_CLOCK_TIMER_2)
                {

                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_TIMER_2)
                {
                    SET_BIT(TCCR2 , 0);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_8_TIMER_2)
                {
                    SET_BIT(TCCR2 , 1);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_32_TIMER_2)
                {
                    SET_BIT(TCCR2 , 0);
                    SET_BIT(TCCR2 , 1);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_64_TIMER_2)
                {
                    SET_BIT(TCCR2 , 2);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_128_TIMER_2)
                {
                    SET_BIT(TCCR2 , 0);
                    SET_BIT(TCCR2 , 2);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_256_TIMER_2)
                {
                    SET_BIT(TCCR2 , 1);
                    SET_BIT(TCCR2 , 2);
                }
                else if(Confg_S->Timer_Psc == F_CPU_CLOCK_1024_TIMER_2)
                {
                    SET_BIT(TCCR2 , 0);
                    SET_BIT(TCCR2 , 1);
                    SET_BIT(TCCR2 , 2);
                }
            }
        }

    }
    else if (Confg_S->Timer_Mode == COUNTER_MODE)
    {
        if (Confg_S->timer_mode == normal_mode)
        {
            if(Confg_S->Timer_Channel == TIMER0)
            {
                if(Confg_S->Timer_Psc == F_EXTERNAL_CLOCK_FALLING_TIMER_0)
                {
                    SET_BIT(TCCR0 , 1);
                    SET_BIT(TCCR0 , 2);
                }
                else if(Confg_S->Timer_Psc == F_EXTERNAL_CLOCK_RISING_TIMER_0)
                {
                    SET_BIT(TCCR0 , 0);
                    SET_BIT(TCCR0 , 1);
                    SET_BIT(TCCR0 , 2);
                }

            }
        }
        else if (Confg_S->timer_mode == ctc_mode)
        {
            if(Confg_S->Timer_Channel == TIMER0)
            {
                if(Confg_S->Timer_Psc == F_EXTERNAL_CLOCK_FALLING_TIMER_0)
                {
                    SET_BIT(TCCR0 , 1);
                    SET_BIT(TCCR0 , 2);
                    SET_BIT(TCCR0 , 3);
                }
                else if(Confg_S->Timer_Psc == F_EXTERNAL_CLOCK_RISING_TIMER_0)
                {
                    SET_BIT(TCCR0 , 0);
                    SET_BIT(TCCR0 , 1);
                    SET_BIT(TCCR0 , 2);
                    SET_BIT(TCCR0 , 3);
                }
            }
        }
    }
}
void Timer_Start(Str_TimerConfiguration_t  *Copy_u8_timerChannel,uint32__t Copy_u32_tickCounts)
{
    if(Copy_u8_timerChannel->Timer_Channel==TIMER0)
    {
        if(Copy_u8_timerChannel->timer_mode==normal_mode)
        {
            TCNT0=256-Copy_u32_tickCounts;
        }
        else if(Copy_u8_timerChannel->timer_mode==ctc_mode||Copy_u8_timerChannel->timer_mode==pwm_mode)
        {
            TCNT0=0;
            OCR0=Copy_u32_tickCounts-1;
        }
    }
    else if(Copy_u8_timerChannel->Timer_Channel==TIMER2)
    {
        if(Copy_u8_timerChannel->timer_mode==normal_mode)
        {
            TCNT2=256-Copy_u32_tickCounts;
        }
        else if(Copy_u8_timerChannel->timer_mode==ctc_mode||Copy_u8_timerChannel->timer_mode==pwm_mode)
        {
            TCNT2=0;
            OCR2=Copy_u32_tickCounts-1;
        }
    }

}
void Timer_Stop(uint8_t Copy_u8_timerChannel)
{
    if(Copy_u8_timerChannel==TIMER0)
    {
        TCCR0=0 ;
        TCNT0 = 0;
    }
    else if(Copy_u8_timerChannel==TIMER2)
    {
        TCCR2=0 ;
        TCNT2 = 0;
    }
}
void Timer_Reset(uint8_t Copy_u8_timerChannel)
{
    if(Copy_u8_timerChannel==TIMER0)
    {
        TCNT0=0x00;
    }
    else if(Copy_u8_timerChannel==TIMER2)
    {
        TCNT2=0x00;
    }
}
void Timer_Get_TickTime(uint8_t Copy_u8_timerChannel, uint32__t *Copy_uint8Ptr_TimerTickTime)
{
    if(Copy_u8_timerChannel==TIMER0)
    {
        *Copy_uint8Ptr_TimerTickTime=TCNT0;
    }
    else if(Copy_u8_timerChannel==TIMER2)
    {
        *Copy_uint8Ptr_TimerTickTime=TCNT2;
    }
}
void Timer_Get_FlagStatus(Str_TimerConfiguration_t *Copy_u8_timerChannel, uint8_t *Copy_uint8Ptr_FlagStatus)
{
    if(Copy_u8_timerChannel->timer_mode==normal_mode)
    {
        if(Copy_u8_timerChannel->Timer_Channel==TIMER0)
        {
            *Copy_uint8Ptr_FlagStatus= READ_BIT(TIFR,0);
        }
        else if(Copy_u8_timerChannel->Timer_Channel==TIMER2)
        {
            *Copy_uint8Ptr_FlagStatus= READ_BIT(TIFR,6);
        }
    }
    else if(Copy_u8_timerChannel->timer_mode==ctc_mode)
    {
        if(Copy_u8_timerChannel->Timer_Channel==TIMER0)
        {
            *Copy_uint8Ptr_FlagStatus= READ_BIT(TIFR,1);
        }
        else if(Copy_u8_timerChannel->Timer_Channel==TIMER2)
        {
            *Copy_uint8Ptr_FlagStatus= READ_BIT(TIFR,7);
        }
    }

    else if(Copy_u8_timerChannel->timer_mode==pwm_mode)
    {
        if(Copy_u8_timerChannel->Timer_Channel==TIMER0)
        {
            *Copy_uint8Ptr_FlagStatus= READ_BIT(TIFR,1);
        }
        else if(Copy_u8_timerChannel->Timer_Channel==TIMER2)
        {
            *Copy_uint8Ptr_FlagStatus= READ_BIT(TIFR,7);
        }
    }
}