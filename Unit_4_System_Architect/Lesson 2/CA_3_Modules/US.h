/*
 * US.h
 *
 *  Created on: Jan 28, 2024
 *      Author: Ahmed
 */

#ifndef US_H_
#define US_H_


#include "state.h"

//Define States
typedef enum
{
	US_busy
}US_state_id ;

//declare states functions US
STATE_define(US_busy);

void US_init();

//STATE Pointer to function take nothing return void
extern void (*US_state)();



#endif /* US_H_ */
