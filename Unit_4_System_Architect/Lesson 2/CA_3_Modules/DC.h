/*
 * DC.h
 *
 *  Created on: Jan 28, 2024
 *      Author: Ahmed
 */

#ifndef DC_H_
#define DC_H_


#include "state.h"

//Define States
typedef enum
{
	DC_idle ,
	DC_busy ,
}DC_state_id ;

//declare states functions CA
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();

//STATE Pointer to function take nothing return void
extern void (*DC_state)();



#endif /* DC_H_ */
