






#include <stdio.h>
#include "firebase.h"


int main(){
	char temp_text[40];

	while(1)
	{
		DPRINTF("\n ============================== ");
		DPRINTF("\n \t Choose one of the following Options \n ");
		DPRINTF("\n  1 : Add Student ");
		DPRINTF("\n  2 : Delete Student ");
		DPRINTF("\n  3 : View Students ");
		DPRINTF("\n  4 : Delete All ");
		DPRINTF("\n  5 : Get Student at specified index (Forward) ");
		DPRINTF("\n  6 : Get Student at specified index (Reverse) ");
		DPRINTF("\n  7 : Get Students Number ");

		DPRINTF("\n  8 : Get Students at Middle of FireBase ");
		DPRINTF("\n  9 : Check Finite List (Short Circuit) ");
		DPRINTF("\n  10: Reverse Linked List ");

		DPRINTF("\n  Enter Option Number : ");
		gets(temp_text);

		DPRINTF("\n =============================== ");
		switch(atoi(temp_text))
		{
		case 1:
			AddStudent();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			view_students();
			break;
		case 4:
			Delete_All();
			break;
		case 5:
			GetStudentAtIndexForward();
			break;
		case 6:
			GetStudentAtIndexReverse();
			break;
		case 7:
			printf("\n Student Number : %u ",FireBaseSize());
			break;
		case 8:
			GetStudentAtMiddle();
			break;
		case 9:
			CheckFiniteLoop();
			break;
		case 10:

			break;
		default:
			DPRINTF("\n Wrong Option ");
		}
	}



	return 0;
}
