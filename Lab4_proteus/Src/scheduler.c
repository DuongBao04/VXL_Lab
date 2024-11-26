/*
 * scheduler.c
 *
 *  Created on: Nov 21, 2024
 *      Author: dgbao
 */

#include "scheduler.h"

int num_task = 0;
// Array of tasks

unsigned char Error_code_G = 0;

sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void) {
    unsigned char i;
    for (i = 0; i < SCH_MAX_TASKS; i++) {
        SCH_Delete_Task(i);
    }
    // Reset the global error variable
    // SCH_Delete_Task() will generate an error code
    // (because the task array is empty)
    Error_code_G = 0;
}

void SCH_Update(unsigned char Index) {
	// Check if there is a task at this location
	if (SCH_tasks_G[Index].pTask) {
		if (SCH_tasks_G[Index].Delay == 0) {
			SCH_tasks_G[Index].RunMe += 1;
			if (SCH_tasks_G[Index].Period) {
				SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
			}
		} else {
			SCH_tasks_G[Index].Delay -= 1;
		}
		return;
	}
	else return;
}

unsigned char SCH_Add_Task(void (*pFunction)(void), unsigned int DELAY, unsigned int PERIOD) {
	unsigned char Index = 0;
	while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)) {
		Index++;
	}

	// Have we reached the end of the list?
	if (Index == SCH_MAX_TASKS){
		// Also return an error code
		return SCH_MAX_TASKS;
	}

	// If we're here, there is a space in the task array
	SCH_tasks_G[Index].pTask = pFunction;
	SCH_tasks_G[Index].Delay = DELAY;
	SCH_tasks_G[Index].Period = PERIOD;
	SCH_tasks_G[Index].RunMe = 0;
	num_task++;

	// Return position of task (to allow later deletion)
	return Index;
}

void SCH_Dispatch_Tasks(void) {
    unsigned char Index;
    // Dispatches (runs) the next task if one is ready
    for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
        if (SCH_tasks_G[Index].RunMe > 0) {
            (*SCH_tasks_G[Index].pTask)();  // Run the task
            SCH_tasks_G[Index].RunMe -= 1;  // Reset/reduce RunMe flag

            // Periodic tasks will automatically run again
            // If this is a 'one shot' task, remove it from the array
            if (SCH_tasks_G[Index].Period == 0) {
                SCH_Delete_Task(Index);
            }
        }
    }
}
void SCH_Delete_Task(const int TASK_INDEX) {
    // Reset the task attributes
    SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
    SCH_tasks_G[TASK_INDEX].Delay = 0;
    SCH_tasks_G[TASK_INDEX].Period = 0;
    SCH_tasks_G[TASK_INDEX].RunMe = 0;
	for(int i = TASK_INDEX; i < num_task-1;i++){
		SCH_tasks_G[TASK_INDEX] = SCH_tasks_G[TASK_INDEX + 1];
	}
	num_task--;
    return;  // Return status
}
