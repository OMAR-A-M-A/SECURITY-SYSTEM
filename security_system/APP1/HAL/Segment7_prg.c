/*
 * Segment7_prg.c
 *
 *  Created on: Aug 13, 2024
 *      Author: Abouzaid
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_Int.h"
#include "Segment7_cfg.h"
#include "segment7_int.h"



u8 Arr[10] =          {0b00111111,   /* 0 */
                       0b00000110,   /* 1 */
                       0b01011011,   /* 2 */
                       0b01001111,   /* 3 */
                       0b01100110,   /* 4 */
                       0b01101101,   /* 5 */
                       0b01111101,   /* 6 */
                       0b00000111,   /* 7 */
                       0b01111111,   /* 8 */
                       0b01101111    /* 9 */
					  };


void Seg7_init(void)
{

	DIO_SetPinDirection(Seg7_ComPort,Seg7_Pin,Output);

#if (ComType == ComCathode)

	DIO_SetPinValue(Seg7_ComPort,Seg7_Pin,High);

#elif (ComType == ComAnode)

	DIO_SetPinValue(Seg7_ComPort,Seg7_Pin,Low);

#endif




}



void Seg7_DisplayNumber(u8 Copy_u8Number)
{

	DIO_SetPortDirection(Seg7_DisplayPort,PortOutput);

#if (ComType == ComCathode)

	DIO_SetPortValue(Seg7_DisplayPort,~Arr[Copy_u8Number]);


#elif (ComType == ComAnode)
	DIO_SetPortValue(Seg7_DisplayPort,Arr[Copy_u8Number]);


#endif


}

