/*
 * US.c
 *
 *  Created on: Jan 28, 2024
 *      Author: Ahmed
 */



#include "US.h"

US_state_id US_state_id_;

//variables
int US_distance = 0 ;

//STATE Pointer to function take nothing return void
void (*US_state)();
int Ultrasonic_Get_Distance_Random (int l, int r, int count);

void US_init()
{
	//init US Driver
	printf("US_init \n");
}

STATE_define (US_busy)
{
	//state_Name
	US_state_id_ = US_busy ;

	//state action
	US_distance = Ultrasonic_Get_Distance_Random (45, 55, 1) ;

	printf("US_waiting State: distance = %d \n", US_distance);
	US_Set_distance(US_distance);
	US_state = STATE(US_busy) ;

}


int Ultrasonic_Get_Distance_Random (int l, int r, int count)
{
		// this will generate random number in range l and r
		int i, rand_num = 0;
		for (i = 0; i < count; i++)
		{
			rand_num = (rand() % (r - l + 1)) + l ;
		}

			return rand_num ;

}
