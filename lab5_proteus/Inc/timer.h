/*
 * timer.h
 *
 *  Created on: Nov 21, 2024
 *      Author: Onii-Chan
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timer_flag0;
extern int timer_flag1;
void setTimer0(int duration);
void setTimer1(int duration);
void timer_run();

#endif /* INC_TIMER_H_ */
