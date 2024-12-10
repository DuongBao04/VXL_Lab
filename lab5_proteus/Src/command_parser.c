/*
 * command_parser.c
 *
 *  Created on: Nov 20, 2024
 *      Author: Onii-Chan
 */

#include "command_parser.h"

int state = 0 ;
int tempcheck = 0;
void command_parser_fsm() {
	    if (strstr((const char *)buffer, "!RST#") != NULL) {
	    	state = INFO;
	    }
	    else if (strstr((const char *)buffer, "!OK#") != NULL) {
	    	state = INIT;
	    	tempcheck = 0;
	    }
}

void uart_communiation_fsm (){
	switch(state){
	case INIT:
		break;
	case INFO:
		if (timer_flag0 == 1){
			if (tempcheck == 0){
				HAL_ADC_Start(&hadc1);
				HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
				HAL_ADC_Stop(&hadc1);
				tempcheck = 1;
			}
			ADC_value = HAL_ADC_GetValue(&hadc1);

			int len = sprintf(str," !ADC=%lu# \r\n",ADC_value);
			HAL_UART_Transmit (&huart2 , ( void *) str , len, 1000);

			memset(buffer, 0, sizeof(buffer));
			index_buffer = 0;
			setTimer0(3000);
		}
		break;
	default:
		break;
	}
}
