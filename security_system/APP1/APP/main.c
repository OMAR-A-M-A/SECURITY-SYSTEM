#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_Int.h"
#include "LCD_Int.h"
#include "KPD_Int.h"
#include "segment7_int.h"
#include <util/delay.h>


#define BUZZER_PIN   PIN_0
#define BUZZER_PORT  PORTA
#define GREEN_LED    PIN_1
#define RED_LED      PIN_2
#define LED_PORT     PORTA
#define PASSWORD_LENGTH 4
#define CORRECT_PASSWORD 1,2,3,4

void init_system() {
    LCD_init();
    KPD_init();
    Seg7_init();
    DIO_SetPinDirection(LED_PORT, GREEN_LED, Output);
    DIO_SetPinDirection(LED_PORT, RED_LED, Output);
    DIO_SetPinDirection(BUZZER_PORT, BUZZER_PIN, Output);
	Seg7_DisplayNumber(3);
}

u8 get_password(u8* pass) {
   LCD_GoTo(Line_2, 0);
    for(u8 i=0; i<PASSWORD_LENGTH; i++) {
        while(1) {
            u8 key = KPD_GetKey();
            if(key != 16) {
				if (key== 11)
				{
					--i;
					LCD_GoTo(Line_2, i);
					LCD_WriteCharacter(' ');
					LCD_GoTo(Line_2, i);
					
				}
				else
				{
                pass[i] = key;
				key = key + '0';
				LCD_WriteCharacter(key);
				_delay_ms(400);
				LCD_GoTo(Line_2, i);
                LCD_WriteCharacter('*');
                _delay_ms(200);
				
                break;
				}
            }
        }
    }
    return 1;
}

u8 check_password(u8* entered) {
    const u8 correct[PASSWORD_LENGTH] = {CORRECT_PASSWORD};
    for(u8 i=0; i<PASSWORD_LENGTH; i++) {
        if(entered[i] != correct[i]) return 0;
    }
    return 1;
}

void countdown() {
    LCD_WriteCommand(lcd_Clear);
    LCD_GoTo(Line_1, 4);
    LCD_WriteString("WARNING!");
    LCD_GoTo(Line_2, 2);
    LCD_WriteString("EXPLODE IN: ");

    for(u8 i=9; i>0; i--) {
        LCD_GoTo(Line_2, 13);
        LCD_WriteCharacter(i+'0');
        Seg7_DisplayNumber(i);
        DIO_SetPinValue(LED_PORT, RED_LED, High);
        DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, High);
        _delay_ms(500);
        DIO_SetPinValue(LED_PORT, RED_LED, Low);
        DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, Low);
        _delay_ms(500);
    }

    LCD_WriteCommand(lcd_Clear);
    LCD_GoTo(Line_1, 2);
    LCD_WriteString("SYSTEM LOCKED");
    LCD_GoTo(Line_2, 5);
    LCD_WriteString("ALARM!");
    Seg7_DisplayNumber(0);
    while(1) {
        DIO_SetPinValue(LED_PORT, RED_LED, High);
        DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, High);
    }
}

int main() {
    init_system();
    u8 attempts = 0;


    while(1) {
        LCD_WriteCommand(lcd_Clear);
        LCD_GoTo(Line_1, 0);
        LCD_WriteString("ENTER PASSWORD:");
        LCD_GoTo(Line_2, 0);

        u8 password[PASSWORD_LENGTH];
        get_password(password);

        if(check_password(password)) {
            LCD_WriteCommand(lcd_Clear);
            LCD_GoTo(Line_1, 3);
            LCD_WriteString("ACCESS OK");
            LCD_GoTo(Line_2, 3);
            LCD_WriteString("WELCOME!");
            DIO_SetPinValue(LED_PORT, GREEN_LED, High);
            _delay_ms(2000);
            DIO_SetPinValue(LED_PORT, GREEN_LED, Low);
			attempts = 0;
			init_system();

        }
        else {
            if(++attempts >= 3) {
                LCD_WriteCommand(lcd_Clear);
                LCD_GoTo(Line_1, 4);
                LCD_WriteString("DENIED");
                LCD_GoTo(Line_2, 2);
                LCD_WriteString("LOCKING SYSTEM");
				Seg7_DisplayNumber(0);
                _delay_ms(1000);
                countdown();
            }
            else {
                LCD_WriteCommand(lcd_Clear);
                LCD_GoTo(Line_1, 0);
                LCD_WriteString("WRONG PASSWORD");
                LCD_GoTo(Line_2, 4);
                LCD_WriteString("LEFT: ");
                LCD_WriteCharacter('0'+(3-attempts));
				Seg7_DisplayNumber(3-attempts);
				DIO_SetPinValue(LED_PORT, RED_LED, High);
				DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, High);
				_delay_ms(500);
				DIO_SetPinValue(LED_PORT, RED_LED, Low);
				DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, Low);
				_delay_ms(500);
                _delay_ms(2000);
            }
        }
    }
}
