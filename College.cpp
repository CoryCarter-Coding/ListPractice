
#include <iostream>
#include "Student_Node.h"
#include "Student_Commands.h"

using namespace std;

int main() 
{
	int choice, found_flag, n;
	char grade, continue_flag = 'y';
	string input1, input2, class_name;
	
	Student<string>* head;
	Student<string>* tail;
	Student<string>* cursor;
	
	cursor = head;
	tail = head;
	
	cout << "Welcome to CCSU Information Program. " << endl
		 << "0: Quit Program"		<< endl
		 << "1: Add Student" 		<< endl
		 << "2: Add Course"  		<< endl
		 << "3: Delete Student" 	<< endl
		 << "4: Delete Course" 		<< endl
		 << "5: View Student Records" << endl;
	
	cout << "Please Enter A Command Choice: ";
	cin  >> choice;	
	cout << endl;
	
	while(!choice == 0)
	{
		switch (choice) 
		{
	  		case 1:
				cursor = tail;
				cout << "Enter Student Name (First and Last): ";
				cin >> input1 >> input2;
	    		Add_Student(head, tail, cursor, input1, input2, n);
				cout << "Student Added." << endl;
				n++;
	    		break;
	  		case 2:
	    		cout << "Coming Soon..." << endl;
	    		break;
	  		case 3:
				cout << "Enter Student Name (First and Last): ";
				cin >> input1 >> input2;
				
	    		Search_Student(head, tail, cursor, input1, input2, found_flag);
	
				if(found_flag == 1)
				{
					cout << "Student Found." << endl;
					cout << found_flag;
					break;
				}
				else
				{
					cout << "Student Not Found." << endl;
					cout << found_flag;
					cursor = head;
					break;
				}
	  		case 4:
	    		cout << "Coming Soon..." << endl;
	    		break;
	  		case 5:
	    		Head_Print(head, cursor, n);
				cursor = head;
	    		break;
	  		default:
	    		cout << "Bad input. " << endl;
	 	}
				cout << endl;
	 			cout << "Continue Program?" << endl
				 << "0: Quit Program"		<< endl
				 << "1: Add Student" 		<< endl
				 << "2: Add Course"  		<< endl
				 << "3: Delete Student" 	<< endl
				 << "4: Delete Course" 		<< endl
				 << "5: View Student Records" << endl;
				cout << "Please Enter A Command Choice: ";
				cin >> choice;
				cout << endl;
	}
	
	//OPTIONAL: PLACE SAVE COMMANDS HERE.
	
	cout << endl;
	cout << "Program Closed. Goodbye.";
	return 0;
}