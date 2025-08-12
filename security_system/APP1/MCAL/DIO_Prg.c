/*
 * DIO_Prg.c
 *
 *  Created on: Aug 8, 2024
 *      Author: Abouzaid
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_Prv.h"
#include "DIO_Int.h"

void DIO_SetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN ,u8 Copy_u8Direction)
{
	switch (Copy_u8PORT)
	{
	case PORTA:
		if(Copy_u8Direction==Input)
		{
			CLR_BIT(DDRA_Register,Copy_u8PIN);
		}
		else if (Copy_u8Direction==Output)
		{
			SET_BIT(DDRA_Register,Copy_u8PIN);
		}
		break ;
	case PORTB:
		if(Copy_u8Direction==Input)
		{
			CLR_BIT(DDRB_Register,Copy_u8PIN);
		}
		else if (Copy_u8Direction==Output)
		{
			SET_BIT(DDRB_Register,Copy_u8PIN);
		}
		break ;
	case PORTC:
		if(Copy_u8Direction==Input)
		{
			CLR_BIT(DDRC_Register,Copy_u8PIN);
		}
		else if (Copy_u8Direction==Output)
		{
			SET_BIT(DDRC_Register,Copy_u8PIN);
		}
		break ;
	case PORTD:
		if(Copy_u8Direction==Input)
		{
			CLR_BIT(DDRD_Register,Copy_u8PIN);
		}
		else if (Copy_u8Direction==Output)
		{
			SET_BIT(DDRD_Register,Copy_u8PIN);
		}
		break ;

	}
}


void DIO_SetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN ,u8 Copy_u8Value)
{
	switch (Copy_u8PORT)
	{
	case PORTA:
		if(Copy_u8Value==High)
		{
			SET_BIT(PORTA_Register,Copy_u8PIN);
		}
		else if (Copy_u8Value==Low)
		{
			CLR_BIT(PORTA_Register,Copy_u8PIN);
		}
		break ;
	case PORTB:
		if(Copy_u8Value==High)
		{
			SET_BIT(PORTB_Register,Copy_u8PIN);
		}
		else if (Copy_u8Value==Low)
		{
			CLR_BIT(PORTB_Register,Copy_u8PIN);
		}
		break ;
	case PORTC:
		if(Copy_u8Value==High)
		{
			SET_BIT(PORTC_Register,Copy_u8PIN);
		}
		else if (Copy_u8Value==Low)
		{
			CLR_BIT(PORTC_Register,Copy_u8PIN);
		}
		break ;
	case PORTD:
		if(Copy_u8Value==High)
		{
			SET_BIT(PORTD_Register,Copy_u8PIN);
		}
		else if (Copy_u8Value==Low)
		{
			CLR_BIT(PORTD_Register,Copy_u8PIN);
		}
		break ;
	}
}
u8 DIO_GetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	u8 Copy_u8LocalVariable ;
	switch (Copy_u8PORT)
	{
	case PORTA:
		Copy_u8LocalVariable=GET_BIT(PINA_Register,Copy_u8PIN);
		break;
	case PORTB:
		Copy_u8LocalVariable=GET_BIT(PINB_Register,Copy_u8PIN);
		break;
	case PORTC:
		Copy_u8LocalVariable=GET_BIT(PINC_Register,Copy_u8PIN);
		break;
	case PORTD:
		Copy_u8LocalVariable=GET_BIT(PIND_Register,Copy_u8PIN);
		break;
	}
	return Copy_u8LocalVariable;
}

void DIO_SetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction)
{
	switch (Copy_u8Port) {
	case PORTA:
		DDRA_Register=Copy_u8Direction;
		break;
	case PORTB:
		DDRB_Register=Copy_u8Direction;
		break;
	case PORTC:
		DDRC_Register=Copy_u8Direction;
		break;
	case PORTD:
		DDRD_Register=Copy_u8Direction;
		break;
	default:
		break;
	}



}
void DIO_SetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{
	switch (Copy_u8Port)
	{
	case PORTA:
		PORTA_Register=Copy_u8Value;
		break;
	case PORTB:
		PORTB_Register=Copy_u8Value;
		break;
	case PORTC:
		PORTC_Register=Copy_u8Value;
		break;
	case PORTD:
		PORTD_Register=Copy_u8Value;
		break;
	default:
		break;
	}

}

// Function to enable internal pull-up resistors
void DIO_EnablePullUp(u8 Copy_u8PORT, u8 Copy_u8PIN) {
    switch (Copy_u8PORT) {
        case PORTA:
            SET_BIT(PORTA_Register, Copy_u8PIN);
            break;
        case PORTB:
            SET_BIT(PORTB_Register, Copy_u8PIN);
            break;
        case PORTC:
            SET_BIT(PORTC_Register, Copy_u8PIN);
            break;
        case PORTD:
            SET_BIT(PORTD_Register, Copy_u8PIN);
            break;
        default:
            break;
    }
}

