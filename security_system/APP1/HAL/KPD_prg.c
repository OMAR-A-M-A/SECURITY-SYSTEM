/*
 * KPD_Prg.c
 *
 *  Created on: Aug 14, 2024
 *      Author: Abouzaid
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_Int.h"
#include "KPD_Int.h"
#include "KPD_cfg.h"

u8 Key_Arr[4][4] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11},
    {12, 13, 14, 15},
};

void KPD_init(void) {
    u8 i;

    // Initialize row pins
    for (i = Row_Start; i <= Row_End; i++) {
        DIO_SetPinDirection(KPD_Port, i, Input);
        DIO_SetPinValue(KPD_Port, i, High); // Enable internal pull-up
    }

    // Initialize column pins
    for (i = Column_Start; i <= Column_End; i++) {
        DIO_SetPinDirection(KPD_Port, i, Output);
        DIO_SetPinValue(KPD_Port, i, High); // Set columns high
    }
}

u8 KPD_GetKey(void) {
    u8 i, j;
    u8 Key = 16; // Default to 16 (no key pressed)
    u8 Value;

    for (i = Column_Start; i <= Column_End; i++) {
        // Activate one column at a time
        DIO_SetPinValue(KPD_Port, i, Low); // Set current column low

        for (j = Row_Start; j <= Row_End; j++) {
            // Read the state of each row
            Value = DIO_GetPinValue(KPD_Port, j);
            if (Value == 0) { // Check if the key is pressed
                Key = Key_Arr[j - Row_Start][i - Column_Start]; // Map to key number

                // Debounce: Wait until key is released
                while (DIO_GetPinValue(KPD_Port, j) == 0);
                break; // Break if a key is pressed
            }
        }

        // Restore column state
        DIO_SetPinValue(KPD_Port, i, High); // Set current column back high
        if (Key != 16) {
            break; // Exit outer loop if a key was detected
        }
    }
    return Key; // Return the detected key or 16
}
