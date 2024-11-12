/*
 * timer.c
 *
 *  Created on: Oct 3, 2024
 *      Author: dgbao
 */
//#include "main.h"

#include "timer.h"

int timer_flag[10];
int timer_counter[10];
int HCLK = 8000000;
int Prescaler = 7999;
int Period = 9;
int TIMER_CYCLE = 10;
void setTimer(int timerIndex, int duration) {
    if (timerIndex >= 0 && timerIndex < 10) {
        timer_counter[timerIndex] = duration / TIMER_CYCLE;
        timer_flag[timerIndex] = 0;
    }
}

void timer_run() {
    for (int i = 0; i < 10; ++i) {
        if (timer_counter[i] > 0) {
            timer_counter[i]--;
            if (timer_counter[i] == 0) {
                timer_flag[i] = 1;
            }
        }
    }
}
