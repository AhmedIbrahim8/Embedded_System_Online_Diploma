/*
 * CA.c
 *
 *  Created on: Jan 28, 2024
 *      Author: Ahmed
 */

#include "CA.h"

//variables
int CA_speed = 0 ;
int CA_distance = 0 ;
int CA_threshold = 50 ;

//STATE Pointer to function take nothing return void
void (*CA_state)();
CA_state_id CA_state_id_;

void US_Set_distance (int d)
{
	CA_distance = d ;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving)) ;
	printf("US -------distance=%d---------> CA \n", CA_distance);

}



STATE_define (CA_waiting)
{
	//state_Name
	CA_state_id_ = CA_waiting ;
	printf("CA_waiting State: distance = %d  Speed = %d \n", CA_distance, CA_speed);

	//state_Action
	CA_speed = 0 ;
	DC_motor (CA_speed) ;
	//Event_Check
	//Ultrasonic_Get_Distance(CA_distance)


}

STATE_define (CA_driving)
{
	//state_Name
	CA_state_id_ = CA_driving ;
	printf("CA_driving State: distance = %d Speed = %d \n", CA_distance, CA_speed);

	//State action
	CA_speed = 30 ;
	DC_motor (CA_speed);
}
