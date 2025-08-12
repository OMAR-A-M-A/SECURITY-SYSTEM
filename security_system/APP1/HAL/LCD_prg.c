/*
 * LCD_prg.c
 *
 *  Created on: Aug 13, 2024
 *      Author: Abouzaid
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_Int.h"
#include "LCD_Int.h"
#include "LCD_cfg.h"
#include <util/delay.h>
void LCD_init(void)
{
	DIO_SetPortDirection(LCD_DataPort,PortOutput);
	DIO_SetPinDirection(LCD_ControlPort,RS_PIN,Output);
	DIO_SetPinDirection(LCD_ControlPort,RW_PIN,Output);
	DIO_SetPinDirection(LCD_ControlPort,E_PIN,Output);
	DIO_SetPinValue(LCD_ControlPort,E_PIN,Low);

	_delay_ms(100);
	LCD_WriteCommand(lcd_FunctionSet8bit);
	_delay_ms(5);
	LCD_WriteCommand(lcd_DisplayOn);
	_delay_ms(5);
	LCD_WriteCommand(lcd_Clear);
	_delay_ms(5);
	LCD_WriteCommand(lcd_EntryMode);
}
void LCD_WriteCommand(u8 Copy_u8Command)
{
	//RS-->0
	DIO_SetPinValue(LCD_ControlPort,RS_PIN,Low);
	//RW-->0	//write
	DIO_SetPinValue(LCD_ControlPort,RW_PIN,Low);
	//E-->0
	DIO_SetPinValue(LCD_ControlPort,E_PIN,Low);
	//write command
	DIO_SetPortValue(LCD_DataPort,Copy_u8Command);
	//E-->1 delay 5ms E-->0
	DIO_SetPinValue(LCD_ControlPort,E_PIN,High);
	_delay_ms(5);
	DIO_SetPinValue(LCD_ControlPort,E_PIN,Low);


}
void LCD_WriteCharacter(u8 Copy_u8Character)
{
	//RS-->1
	DIO_SetPinValue(LCD_ControlPort,RS_PIN,High);
	//RW-->0	//write
	DIO_SetPinValue(LCD_ControlPort,RW_PIN,Low);
	//E-->0
	DIO_SetPinValue(LCD_ControlPort,E_PIN,Low);
	//write character
	DIO_SetPortValue(LCD_DataPort,Copy_u8Character);
	//E-->1 delay 5ms E-->0
	DIO_SetPinValue(LCD_ControlPort,E_PIN,High);
	_delay_ms(5);
	DIO_SetPinValue(LCD_ControlPort,E_PIN,Low);


}
//Null char \0
void LCD_WriteString(u8 *Copy_u8ptr)
{
	u8 i = 0;
	while (Copy_u8ptr[i] != '\0')
	{
		LCD_WriteCharacter(Copy_u8ptr[i]);
		i++;
	}
}


void LCD_GoTo(u8 Copy_u8line,u8 Copy_u8Column)
{
	u8 Copy_u8LocalVariable;
	if(Copy_u8Column>=0 && Copy_u8Column<=15)
	{
		switch (Copy_u8line)
		{
		case Line_1 :
			Copy_u8LocalVariable=Copy_u8Column+128-1;//0x80
			break;
		case Line_2 :
			Copy_u8LocalVariable=Copy_u8Column+192-1;//0x80+0x40
			break;
		}
		LCD_WriteCommand(Copy_u8LocalVariable);
	}

}
