/*
 * CA.h
 *
 *  Created on: Jan 28, 2024
 *      Author: Ahmed
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"

//Define States
typedef enum
{
	CA_waiting ,
	CA_driving ,
}CA_state_id ;

//declare states functions CA
STATE_define(CA_waiting);
STATE_define(CA_driving);

//STATE Pointer to function take nothing return void
extern void (*CA_state)();



#endif /* CA_H_ */
