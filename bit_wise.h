/*
 * bit_wise.h
 *
 * Created: 29/03/2024 06:49:24
 *  Author: DELL
 */ 


#ifndef BIT_WISE_H_
#define BIT_WISE_H_

#define SET_BIT(PORT_NU , PIN_NU) (PORT_NU |= (1 << PIN_NU))
#define CLEAR_BIT(PORT_NU , PIN_NU) (PORT_NU &= ~(1 << PIN_NU))
#define TOGGLE_BIT(PORT_NU , PIN_NU) (PORT_NU ^= (1 << PIN_NU))
#define READ_BIT(PORT_NU , PIN_NU)   ((PORT_NU >> PIN_NU) & 1)



#endif /* BIT_WISE_H_ */