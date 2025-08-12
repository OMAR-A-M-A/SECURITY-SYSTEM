/*
 * LCD_cfg.h
 *
 *  Created on: Aug 13, 2024
 *      Author: Abouzaid
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_DataPort PORTB
/*
 * Select
 *
 * PORTA
 * OR
 * PORTB
 * OR
 * PORTC
 * OR
 * PORTD
 *
 *
 */


#define LCD_ControlPort PORTA
/*
 * Select
 *
 * PORTA
 * OR
 * PORTB
 * OR
 * PORTC
 * OR
 * PORTD
 *
 *
 */
//control pins


#define RS_PIN PIN_3

/*
 * select
 *
 * PIN_0
 * OR
 * PIN_1
 * OR
 * PIN_2
 * OR
 * PIN_3
 * OR
 * PIN_4
 * OR
 * PIN_5
 * OR
 * PIN_6
 * OR
 * PIN_7
 */
#define RW_PIN PIN_4

/*
 * select
 *
 * PIN_0
 * OR
 * PIN_1
 * OR
 * PIN_2
 * OR
 * PIN_3
 * OR
 * PIN_4
 * OR
 * PIN_5
 * OR
 * PIN_6
 * OR
 * PIN_7
 */
#define E_PIN PIN_5

/*
 * select
 *
 * PIN_0
 * OR
 * PIN_1
 * OR
 * PIN_2
 * OR
 * PIN_3
 * OR
 * PIN_4
 * OR
 * PIN_5
 * OR
 * PIN_6
 * OR
 * PIN_7
 */

#endif /* LCD_CFG_H_ */
