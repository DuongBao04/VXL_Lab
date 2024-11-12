/*
 * timer.h
 *
 *  Created on: Oct 3, 2024
 *      Author: dgbao
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "button.h"

extern int timer_flag[10];

void setTimer(int timerIndex,int duration);
void timer_run();

#endif /* INC_TIMER_H_ */
