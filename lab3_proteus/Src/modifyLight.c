/*
 * modifyLight.c
 *
 *  Created on: Nov 3, 2024
 *      Author: dgbao
 */

#include "modifyLight.h"

void modify_red(void) {
	if (timer_flag[0] == 1) {
		HAL_GPIO_TogglePin(GPIOA, Red1_Pin);
		HAL_GPIO_TogglePin(GPIOA, Red2_Pin);
		setTimer(0,500);
	}

	if (is_button_pressed(1)) {
		if (temp >= 1000 && temp <= 99000) {
			temp += 1000;
		}
		if (temp > 99000) {
			temp = 1000;
		}
	}

	if (is_button_pressed(2)) {
		redTimer = temp;
	}
}

void modify_yellow(void) {
	if (timer_flag[0] == 1) {
		HAL_GPIO_TogglePin(GPIOA, Yellow1_Pin);
		HAL_GPIO_TogglePin(GPIOA, Yellow2_Pin);
		setTimer(0,500);
	}

	if (is_button_pressed(1)) {
		if (temp >= 1000 && temp <= 99000) {
			temp += 1000;
		}
		if (temp > 99000) {
			temp = 1000;
		}
	}

	if (is_button_pressed(2)) {
		yellowTimer = temp;
	}

}

void modify_green(void) {
	if (timer_flag[0] == 1) {
		HAL_GPIO_TogglePin(GPIOA, Green1_Pin);
		HAL_GPIO_TogglePin(GPIOA, Green2_Pin);
		setTimer(0,500);
	}

	if (is_button_pressed(1)) {
		if (temp >= 1000 && temp <= 99000) {
			temp += 1000;
		}
		if (temp > 99000) {
			temp = 1000;
		}
	}

	if (is_button_pressed(2)) {
		greenTimer = temp;
	}

}

