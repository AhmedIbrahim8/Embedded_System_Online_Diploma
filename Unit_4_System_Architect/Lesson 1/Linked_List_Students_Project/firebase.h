/*
 * firebase.h
 *
 *  Created on: Jan 27, 2024
 *      Author: Ahmed
 */

#ifndef FIREBASE_H_
#define FIREBASE_H_

#define    DPRINTF(...) {fflush(stdout);\
	                     fflush(stdin);\
                         printf(__VA_ARGS__);\
	                     fflush(stdout);\
	                     fflush(stdin);}

typedef  struct{
	int ID;
	char name[40];
	float height;
}Sdata;


struct SStudent{
	Sdata student;
	struct SStudent *PNextStudent;
};



/* APIs Prototypes */


void AddStudent();


int delete_student();

void view_students();


void Delete_All();

unsigned int FireBaseSize();

void GetStudentAtIndexForward();

void GetStudentAtIndexReverse();

void GetStudentAtMiddle();

void CheckFiniteLoop();





#endif /* FIREBASE_H_ */
