/*

 * DIO_Int.h
 *
 *  Created on: Aug 8, 2024
 *      Author: Abouzaid
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_Prv.h"

/*PORT MACROS*/

#define PORTA 1
#define PORTB 2
#define PORTC 3
#define PORTD 4


/*PIN MACROS*/

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

/*DIRECTION MACROS*/

#define Input 0
#define Output 1

/*PORT DIRECTION MACROS*/

#define PortInput 0
#define PortOutput 255

/*VALUE MACROS*/

#define High 1
#define Low 0


void DIO_SetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN ,u8 Copy_u8Direction);
void DIO_SetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN ,u8 Copy_u8Value);
u8 DIO_GetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN );
void DIO_SetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction);
void DIO_SetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);

// Function to enable internal pull-up resistors
void DIO_EnablePullUp(u8 Copy_u8PORT, u8 Copy_u8PIN);

#endif /* DIO_INT_H_ */
