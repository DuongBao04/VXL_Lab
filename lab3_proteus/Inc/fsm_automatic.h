/*
 * fsm_automatic.h
 *
 *  Created on: Oct 30, 2024
 *      Author: dgbao
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "global.h"
#include "timer.h"
#include "Seven_Segment.h"
#include "button.h"
#include "modifyLight.h"

void fsm_mode();
void updateLedBuffer();
//void fsm_automatic_run();
//void updateState();
//
//void modifyRed();
//void modifyYellow();
//void modifyGreen();

void verticalTraffic();
void horizontalTraffic();

extern int temp;
extern int redTimer;
extern int yellowTimer;
extern int greenTimer;

#endif /* INC_FSM_AUTOMATIC_H_ */
