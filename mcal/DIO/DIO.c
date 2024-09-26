#include "DIO.h"

//***********************************************************port****************************************************************

void PORT_INIT(uint8_t port_nu, uint8_t direction)
{
	if (direction == port_input)
	{
		if (port_nu == PORT_A)
		{
			DDRA = port_input;
		}
		else if (port_nu == PORT_B)
		{
			DDRB =port_input;
		}
		else if (port_nu == PORT_C)
		{
			DDRC =port_input;
		}
		else if (port_nu == PORT_D)
		{
			DDRD =port_input;
		}
	}
	else if (direction == port_output)
	{
		if (port_nu == PORT_A)
		{
			DDRA =port_output;
		}
		else if (port_nu == PORT_B)
		{
			DDRB =port_output;
		}
		else if (port_nu == PORT_C)
		{
			DDRC =port_output;
		}
		else if (port_nu == PORT_D)
		{
			DDRD =port_output;
		}
	}
	
}
void PORT_WRITE(uint8_t port_nu, uint8_t value)
{
    if (port_nu == PORT_A)
    {
        PORTA = value;
    }
    else if (port_nu == PORT_B)
    {
        PORTB = value;
    }
    else if (port_nu == PORT_C)
    {
        PORTC = value;
    }
    else if (port_nu == PORT_D)
    {
        PORTD = value;
    }
}
void PORT_TOGGLE(uint8_t port_nu)
{
	if (port_nu == PORT_A)
	{
		if (PORTA == port_low)
		{
			PORT_WRITE(port_nu , port_high);
		}
		else if (PORTA == port_high)
		{
			PORT_WRITE(port_nu , port_low);
		}
	}
	
	else if (port_nu == PORT_B)
	{
		if (PORTB == port_low)
		{
			PORT_WRITE(port_nu , port_high);
		}
		else if (PORTB == port_high)
		{
			PORT_WRITE(port_nu , port_low);
		}
	}
	else if (port_nu == PORT_C)
	{
		if (PORTC == port_low)
		{
			PORT_WRITE(port_nu , port_high);
		}
		else if (PORTC == port_high)
		{
			PORT_WRITE(port_nu , port_low);
		}
	}
	else if (port_nu == PORT_D)
	{
		if (PORTD == port_low)
		{
			PORT_WRITE(port_nu , port_high);
		}
		else if (PORTD == port_high)
		{
			PORT_WRITE(port_nu , port_low);
		}
	}
}
//***********************************************************pin****************************************************************
void DIO_init(uint8_t port_nu , uint8_t pin_nu , uint8_t direction)
{
	if (direction == INPUT)
	{
		if (port_nu == PORT_A)
		{
			CLEAR_BIT(DDRA , pin_nu);
		}
		else if (port_nu == PORT_B)
		{
			CLEAR_BIT(DDRB , pin_nu);
		}
		else if (port_nu == PORT_C)
		{
			CLEAR_BIT(DDRC , pin_nu);
		}	
		else if (port_nu == PORT_D)
		{
			CLEAR_BIT(DDRD , pin_nu);
		}
	}
	else if (direction == OUTPUT)
	{
		if (port_nu == PORT_A)
		{
			SET_BIT(DDRA , pin_nu);
		}
		else if (port_nu == PORT_B)
		{
			SET_BIT(DDRB , pin_nu);
		}
		else if (port_nu == PORT_C)
		{
			SET_BIT(DDRC , pin_nu);
		}
		else if (port_nu == PORT_D)
		{
			SET_BIT(DDRD , pin_nu);
		}
	}
	
}
void DIO_read(uint8_t port_nu , uint8_t pin_nu , uint8_t *value)
{
	if (port_nu == PORT_A)
	{
		*value = READ_BIT(PINA , pin_nu);
	}
	else if (port_nu == PORT_B)
	{
		*value = READ_BIT(PINB , pin_nu);
	}
	else if (port_nu == PORT_C)
	{
		*value = READ_BIT(PINC , pin_nu);
	}
	else if (port_nu == PORT_D)
	{
		*value = READ_BIT(PIND , pin_nu);
	}
	
}

void DIO_write(uint8_t port_nu , uint8_t pin_nu , uint8_t value)
{
	if (value == LOW)
	{
		if (port_nu == PORT_A)
		{
			CLEAR_BIT(PORTA , pin_nu);
		}
		else if (port_nu == PORT_B)
		{
			CLEAR_BIT(PORTB , pin_nu);
		}
		else if (port_nu == PORT_C)
		{
			CLEAR_BIT(PORTC , pin_nu);
		}
		else if (port_nu == PORT_D)
		{
			CLEAR_BIT(PORTD , pin_nu);
		}
	}
	else if (value == HIGH)
	{
		if (port_nu == PORT_A)
		{
			SET_BIT(PORTA , pin_nu);
		}
		else if (port_nu == PORT_B)
		{
			SET_BIT(PORTB , pin_nu);
		}
		else if (port_nu == PORT_C)
		{
			SET_BIT(PORTC , pin_nu);
		}
		else if (port_nu == PORT_D)
		{
			SET_BIT(PORTD , pin_nu);
		}
	}
		
}
void DIO_toggle(uint8_t port_nu , uint8_t pin_nu)
{
	uint8_t *value = 0;
	
	DIO_read(port_nu , pin_nu ,value);
	if (port_nu == PORT_A)
	{
		if (*value == LOW)
		{
			DIO_write(port_nu , pin_nu ,HIGH);
		}
		else if (*value == 1)
		{
			DIO_write(port_nu , pin_nu ,LOW);
		}
	}
	
	else if (port_nu == PORT_B)
	{
		if (*value == LOW)
		{
			DIO_write(port_nu , pin_nu ,HIGH);
		}
		else if (*value == 1)
		{
			DIO_write(port_nu , pin_nu ,LOW);
		}
	}
	else if (port_nu == PORT_C)
	{
		if (*value == LOW)
		{
			DIO_write(port_nu , pin_nu ,HIGH);
		}
		else if (*value == 1)
		{
			DIO_write(port_nu , pin_nu ,LOW);
		}
	}
	else if (port_nu == PORT_D)
	{
		if (*value == LOW)
		{
			DIO_write(port_nu , pin_nu ,HIGH);
		}
		else if (*value == 1)
		{
			DIO_write(port_nu , pin_nu ,HIGH);
		}
	}
}
