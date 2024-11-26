/*
 * scheduler.h
 *
 *  Created on: Nov 21, 2024
 *      Author: dgbao
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#define SCH_MAX_TASKS 40    // Maximum number of tasks
#define NO_TASK_ID 0

extern int num_task;
#include "main.h"

typedef struct {
    // Pointer to the task (must be a 'void (void)' function)
    void (*pTask)(void);
    // Delay (in ticks) until the function will next be run
    uint32_t Delay;
    // Interval (in ticks) between subsequent runs
    uint32_t Period;
    // Incremented (by scheduler) when task is due to execute
    uint8_t RunMe;
    // Task ID, used to manage tasks
    uint32_t TaskID;
} sTask;

void SCH_Init(void);
void SCH_Update(unsigned char Index);
unsigned char SCH_Add_Task(void (*pFunction)(void), unsigned int DELAY, unsigned int PERIOD);
void SCH_Dispatch_Tasks(void);
void SCH_Delete_Task(const int TASK_INDEX);

#endif /* INC_SCHEDULER_H_ */
