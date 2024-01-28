/*
 * firebase.c
 *
 *  Created on: Jan 27, 2024
 *      Author: Ahmed
 */

#include "firebase.h"
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "conio.h"

struct SStudent *gpFirstStudent=NULL;


void AddStudent(){
	struct SStudent *pNewStudent;
	struct SStudent *pLastStudent;
	char temp_text[40];
	/* Create a new student */
	pNewStudent = (struct SStudent *)malloc(sizeof(struct SStudent));

	/* Check if the firebase is empty */
	if(gpFirstStudent == NULL){
		/* Assign the first student pointer to the new record */
		gpFirstStudent = pNewStudent;
	}
	/* if the firebase is not empty */
	else{
		/* Navigate of loop until reach the last student */
		pLastStudent = gpFirstStudent;
		while(pLastStudent->PNextStudent){
			pLastStudent = pLastStudent->PNextStudent;
		}
		/* Assign the last student pointer to the new record */
		pLastStudent->PNextStudent = pNewStudent;
	}

	/* Fill new record */

	/* Gets the ID from the user*/
	DPRINTF("\n Enter the ID : ");
	gets(temp_text);
	pNewStudent->student.ID = atoi(temp_text);

	/* Gets the student name from the user */
	DPRINTF("\n Enter Student Full Name : ");
	gets(pNewStudent->student.name);

	/* Gets the height of student from the user */
	DPRINTF("\n Enter the student height : ");
	gets(temp_text);
	pNewStudent->student.height = atoi(temp_text);


	/* Set the next pointer of the new record to be null */
	pNewStudent->PNextStudent = NULL;

}


int delete_student(){
	char temp_text[40];
	unsigned int selected_id;

	/* Get the ID from the user */
	DPRINTF("\n Enter the student ID ro be deleted : ");
	gets(temp_text);
	selected_id = atoi(temp_text);

	/* Check if the firebase is not empty*/
	if(gpFirstStudent)
	{
		struct SStudent *pSelectedStudent = gpFirstStudent;
		struct SStudent *pPrevStudent = NULL;

		/* Loop until find the selected ID */
		while(pSelectedStudent)
		{
			/* Compare each Node with the selected ID */
			if(pSelectedStudent->student.ID == selected_id)
			{
				/* if prev pointer still Null, the selected id is at the first
				 * of the linked list
				 * */
				if(pPrevStudent)
				{
					pPrevStudent->PNextStudent = pSelectedStudent->PNextStudent;
				}
				else
				{
					gpFirstStudent = gpFirstStudent->PNextStudent;
				}
				/* Delete the node from the FireBase */
				free(pSelectedStudent);
				return 1;
			}
			else
			{
				/* increase the linked list */
				pPrevStudent = pSelectedStudent;
				pSelectedStudent = pSelectedStudent->PNextStudent;
			}
		}
		DPRINTF("\n Can't find the Student ID ");
		return 0;
	}
	/* Here, the firebase is empty so, no need to loop */
	else
	{
		DPRINTF("\n FireBase is Empty ");
		return 0;
	}
}


void view_students(){
	struct SStudent *pCurrentStudent = gpFirstStudent;
	int count=1;
	if(pCurrentStudent == NULL)
	{
		DPRINTF("\n FireBase is Empty ");
	}
	else
	{
		while(pCurrentStudent)
		{
			DPRINTF("\n Record Number %d ",count);
			DPRINTF("\n \t Student ID     : %d ",pCurrentStudent->student.ID);
			DPRINTF("\n \t Student Name   : %s ",pCurrentStudent->student.name);
			DPRINTF("\n \t Student Height : %0.2f ",pCurrentStudent->student.height);
			pCurrentStudent = pCurrentStudent->PNextStudent;
			count++;
		}
	}
}


void Delete_All(){
	struct SStudent *pCurrentStudent = gpFirstStudent;
	struct SStudent *pTempStudent;
	if(pCurrentStudent == NULL)
	{
		DPRINTF("\n FireBase is Empty ");
	}
	else
	{
		while(pCurrentStudent)
		{
			pTempStudent = pCurrentStudent;
			pCurrentStudent = pCurrentStudent->PNextStudent;
			free(pTempStudent);

		}
		DPRINTF("\n Deleted ");
		gpFirstStudent = NULL;
	}
}


unsigned int FireBaseSize()
{
	struct SStudent *pCurrentStudent = gpFirstStudent;
	unsigned int counter = 0;
	while(pCurrentStudent)
	{
		counter++;
		pCurrentStudent = pCurrentStudent->PNextStudent;
	}
	return counter;
}

void GetStudentAtIndexForward()
{
	struct SStudent *pCurrentStudent;
	unsigned int counter = 0;
	unsigned int selected_index=0;
	char temp_text[40];
	DPRINTF("\n Enter the index you want : ");
	gets(temp_text);
	selected_index = atoi(temp_text);
	/* Check if the FireBase is empty */
	if( FireBaseSize() == 0)
	{
		DPRINTF("\n FireBase is Empty ");
	}
	/* Check if the selected index is greater than size of the FireBase*/
	else if(selected_index >= FireBaseSize() )
	{
		DPRINTF("\n The selected index is greater than the FireBase Size ")
	}
	else
	{
		pCurrentStudent = gpFirstStudent;
		for(counter = 0 ; counter < selected_index ;counter++)
		{
			pCurrentStudent = pCurrentStudent->PNextStudent;
		}

		DPRINTF("\n \t Student ID     : %d ",pCurrentStudent->student.ID);
		DPRINTF("\n \t Student Name   : %s ",pCurrentStudent->student.name);
		DPRINTF("\n \t Student Height : %0.2f ",pCurrentStudent->student.height);
	}
}


void GetStudentAtIndexReverse()
{
	struct SStudent *pMainStudent;
	struct SStudent *pRefStudent;
	unsigned int counter = 0;
	unsigned int selected_index=0;
	char temp_text[40];
	DPRINTF("\n Enter the index you want : ");
	gets(temp_text);
	selected_index = atoi(temp_text);
	/* Check if the FireBase is empty */
	if( FireBaseSize() == 0)
	{
		DPRINTF("\n FireBase is Empty ");
	}
	/* Check if the selected index is greater than size of the FireBase*/
	else if(selected_index >= FireBaseSize() )
	{
		DPRINTF("\n The selected index is greater than the FireBase Size ")
	}
	else
	{
		pMainStudent = gpFirstStudent;
		pRefStudent = gpFirstStudent;
		for(counter = 0 ; counter < selected_index ; counter++)
		{
			pRefStudent = pRefStudent->PNextStudent;
		}
		while(pRefStudent->PNextStudent)
		{
			pMainStudent = pMainStudent->PNextStudent;
			pRefStudent = pRefStudent->PNextStudent;

		}
		DPRINTF("\n \t Student ID     : %d ",pMainStudent->student.ID);
		DPRINTF("\n \t Student Name   : %s ",pMainStudent->student.name);
		DPRINTF("\n \t Student Height : %0.2f ",pMainStudent->student.height);

	}

}


void GetStudentAtMiddle()
{
	struct SStudent *pMainStudent = gpFirstStudent;
	struct SStudent *pRefStudent = gpFirstStudent;
	unsigned int counter = 0;

	while(pRefStudent->PNextStudent)
	{
		/* We have 2 Pointers, one move at double speed and the other
		 * move at normal speed. when the pointer that move with double speed
		 * reach the end of the FireBase, the pointer that move with normal speed
		 * will be at the middle of the FireBase
		 * */
		pRefStudent = pRefStudent->PNextStudent;
		counter++;
		if(counter == 2)
		{
			pMainStudent = pMainStudent->PNextStudent;
			counter = 0;
		}
	}
	/* */
	DPRINTF("\n Student At Middle of the FireBase ");
	DPRINTF("\n \t Student ID     : %d ",pMainStudent->student.ID);
	DPRINTF("\n \t Student Name   : %s ",pMainStudent->student.name);
	DPRINTF("\n \t Student Height : %0.2f ",pMainStudent->student.height);
}


void CheckFiniteLoop()
{
	struct SStudent *pMainStudent = gpFirstStudent;
	struct SStudent *pRefStudent = gpFirstStudent;
	unsigned int counter = 0;
	while(pRefStudent->PNextStudent)
	{
		pRefStudent = pRefStudent->PNextStudent;
		counter++;
		if(pRefStudent == pMainStudent)
		{
			DPRINTF("\n There is Finite Loop (Short Circuit Exist) ");
			return ;
		}
		if(counter == 2)
		{
			pMainStudent = pMainStudent->PNextStudent;
			counter = 0;
		}
	}
	DPRINTF("\n There is No Finite Loop (Short Circuit Not Exist) ");
}








