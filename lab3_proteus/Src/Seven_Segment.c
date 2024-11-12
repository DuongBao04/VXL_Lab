/*
 * Seven_Segment.c
 *
 *  Created on: Oct 28, 2024
 *      Author: dgbao
 */
#include "main.h"
#include "Seven_Segment.h"
#include "global.h"

int led_buffer[4] = {0,0,0,0}; //led1 - led2
int ledHor = 0, ledVer = 0;
int led_index = 1;

void display7SEG(int num, int led_index){
	GPIO_TypeDef* GPIO_Port;
	uint16_t a_Pin;
	uint16_t b_Pin;
	uint16_t c_Pin;
	uint16_t d_Pin;
	uint16_t e_Pin;
	uint16_t f_Pin;
	uint16_t g_Pin;
	if (led_index == 1){
		GPIO_Port = GPIOA;
		a_Pin = a1_Pin;
		b_Pin = b1_Pin;
		c_Pin = c1_Pin;
		d_Pin = d1_Pin;
		e_Pin = e1_Pin;
		f_Pin = f1_Pin;
		g_Pin = g1_Pin;

	}
	if (led_index == 2){
		GPIO_Port = GPIOB;
		a_Pin = a2_Pin;
		b_Pin = b2_Pin;
		c_Pin = c2_Pin;
		d_Pin = d2_Pin;
		e_Pin = e2_Pin;
		f_Pin = f2_Pin;
		g_Pin = g2_Pin;
	}
	switch (num) {
		case 1:
			HAL_GPIO_WritePin(GPIO_Port, a_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, b_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, c_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, d_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, e_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, f_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, g_Pin,GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIO_Port, a_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, b_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, c_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, d_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, e_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, f_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, g_Pin,GPIO_PIN_RESET);
			break;

		case 3:
			HAL_GPIO_WritePin(GPIO_Port, a_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, b_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, c_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, d_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, e_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, f_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, g_Pin,GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIO_Port, a_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, b_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, c_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, d_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, e_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, f_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, g_Pin,GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIO_Port, a_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, b_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, c_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, d_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, e_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, f_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, g_Pin,GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIO_Port, a_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, b_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, c_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, d_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, e_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, f_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, g_Pin,GPIO_PIN_RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIO_Port, a_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, b_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, c_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, d_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, e_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, f_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, g_Pin,GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIO_Port, a_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, b_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, c_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, d_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, e_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, f_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, g_Pin,GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIO_Port, a_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, b_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, c_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, d_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, e_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIO_Port, f_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, g_Pin,GPIO_PIN_RESET);
			break;
		case 0:
			HAL_GPIO_WritePin(GPIO_Port, a_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, b_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, c_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, d_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, e_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, f_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIO_Port, g_Pin,GPIO_PIN_SET);
			break;
	}
}

void update7SEG(int index){
	if (index == 1){
		HAL_GPIO_WritePin(GPIOA, EN1_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, EN2_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, EN3_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, EN4_Pin,GPIO_PIN_SET);
		display7SEG(led_buffer[0], 1);
		display7SEG(led_buffer[1], 2);
	}
	else{
		HAL_GPIO_WritePin(GPIOA, EN1_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, EN2_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, EN3_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, EN4_Pin,GPIO_PIN_RESET);
		display7SEG(led_buffer[2], 1);
		display7SEG(led_buffer[3], 2);
	}
}
