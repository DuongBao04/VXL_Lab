/*
 * button.h
 *
 *  Created on: Oct 30, 2024
 *      Author: dgbao
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_


#define BUTTON_RELEASED GPIO_PIN_SET
#define BUTTON_PRESSED GPIO_PIN_RESET
#define NO_OF_BUTTONS 3

#include "main.h"

void button_reading();
int is_button_pressed(int index);

#endif /* INC_BUTTON_H_ */
