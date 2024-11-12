/*
 * Seven_Segment.h
 *
 *  Created on: Oct 3, 2024
 *      Author: dgbao
 */

#ifndef INC_SEVEN_SEGMENT_H_
#define INC_SEVEN_SEGMENT_H_

extern int led_buffer[4];
extern int ledHor, ledVer;
extern int led_index;
void display7SEG(int num, int led_index);
void update7SEG(int index);

#endif /* INC_SEVEN_SEGMENT_H_ */
