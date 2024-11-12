/*
 * fsm_automatic.c
 *
 *  Created on: Oct 30, 2024
 *      Author: dgbao
 */
#include "fsm_automatic.h"
int mode = 1;
int temp = 1000;
int set = 0;

int redTimer = 5000;
int yellowTimer = 2000;
int greenTimer = 3000;

void updateLedBuffer(){
	led_buffer[0] = ledHor/10;
	led_buffer[1] = ledHor%10;
	led_buffer[2] = ledVer/10;
	led_buffer[3] = ledVer%10;
}

void fsm_mode(){
	if (is_button_pressed(0)) {
		HAL_GPIO_WritePin(GPIOA, Red1_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, Yellow1_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, Green1_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, Green2_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, Red2_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, Yellow2_Pin, SET);
		if (mode >=1 && mode <= 4) {
			setTimer(0,10);
			mode++;
			temp = 1000;
		}
		if (mode > 4) { //Reset
			mode = 1;
			statusHor = Red;
			statusVer = Green;
			setTimer(0, 10);
			setTimer(1, 10);
			setTimer(2, 1000);
			setTimer(3, 200);
		}
	}

	switch (mode) {
	case 1:
		verticalTraffic();
		horizontalTraffic();
		break;

	case 2:
		modify_red();
		break;

	case 3:
		modify_yellow();
		break;

	case 4:
		modify_green();
		break;
	}

	if (mode != 1){
		ledHor = temp / 1000;
		ledVer = mode;
	}

	if (timer_flag[3] == 1){
		if (led_index == 1) led_index = 2;
		else led_index = 1;
		updateLedBuffer();
		update7SEG(led_index);
		setTimer(3, 200);
	}

	if (timer_flag[2] == 1 && mode == 1){
		ledHor--;
		ledVer--;
		setTimer(2,1000);
	}
}

void verticalTraffic(){
	switch (statusVer) {
		case Red:
			if (timer_flag[0] == 1){
				HAL_GPIO_WritePin(GPIOA, Red2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOA, Yellow2_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, Green2_Pin, SET);
				statusVer = Green;
				ledVer = redTimer / 1000;
				setTimer(0, redTimer);
			}
			break;
		case Yellow:
			if (timer_flag[0] == 1){
				HAL_GPIO_WritePin(GPIOA, Red2_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, Yellow2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOA, Green2_Pin, SET);
				statusVer = Red;
				ledVer = yellowTimer / 1000;
				setTimer(0, yellowTimer);
			}
			break;
		case Green:
			if (timer_flag[0] == 1){
				HAL_GPIO_WritePin(GPIOA, Red2_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, Yellow2_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, Green2_Pin, RESET);
				statusVer = Yellow;
				ledVer = greenTimer / 1000;
				setTimer(0, greenTimer);
			}
			break;
		default:
			break;
	}
}

void horizontalTraffic(){
	switch (statusHor) {
		case Red:
			if (timer_flag[1] == 1){
				HAL_GPIO_WritePin(GPIOA, Red1_Pin, RESET);
				HAL_GPIO_WritePin(GPIOA, Yellow1_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, Green1_Pin, SET);
				statusHor = Green;
				ledHor = redTimer / 1000;
				setTimer(1, redTimer);
			}
			break;
		case Yellow:
			if (timer_flag[1] == 1){
				HAL_GPIO_WritePin(GPIOA, Red1_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, Yellow1_Pin, RESET);
				HAL_GPIO_WritePin(GPIOA, Green1_Pin, SET);
				statusHor = Red;
				ledHor = yellowTimer / 1000;
				setTimer(1, yellowTimer);
			}
			break;
		case Green:
			if (timer_flag[1] == 1){
				HAL_GPIO_WritePin(GPIOA, Red1_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, Yellow1_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, Green1_Pin, RESET);
				ledHor = greenTimer / 1000;
				statusHor = Yellow;
				setTimer(1, greenTimer);
			}
			break;
		default:
			break;
	}
}
