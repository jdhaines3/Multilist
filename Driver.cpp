/*
* David Haines
* 362: Data Structures and Algorithms
* Project 2: Multilist
* Driver cpp file
*/

#include <string>
#include <iostream>
#include "Multilist.h"
#include <stdlib.h>
#include <sstream>

//function declarations
void menu (Multilist * multi);

//--Menu--//
void menu (Multilist * multi)
{
	//while loop bool
	int keepGoing = 0;
	
	std::cout << "Welcome to Multilist!" << std::endl;
	std::cout << "Please select what you would like to do (enter the number):" << std::endl;
	//while loop for menu
	while (keepGoing == 0)
	{
		std::cout << "" << std::endl;
		std::cout << "1) Add Student/Class Node" << std::endl;
		std::cout << "2) Print out list of students with respective classes" << std::endl;
		std::cout << "3) Print out list of classes with respective students" << std::endl;
		std::cout << "4) Exit Program." << std::endl;
		std::cout << std::endl;
		
		//menu variable
		std::string inputMenu = "";
		
		std::cin >> inputMenu;
		
		/*checking input
		if valid number, do what it says, else re-display menu */
		if (inputMenu == "1")
		{
			//input for student and class, and string stream for conversion string to int
			std::string student = "";
			std::string clas = "";
			std::stringstream ss;
			
			//loop bools and numbers to enter as insert arguments
			int studentGo = 0;
			int classGo = 0;
			int studentNum, clasNum;
			
			while (studentGo == 0)
			{
				std::cout << std::endl;
				std::cout << "Please enter student number (1-10000): " << std::endl;
				std::cin >> student;
				
				int stud = 0;
				
				//convert to int
				ss.clear();
				ss.str("");
				ss << student;
				ss >> stud;
				
				//check if valid range
				if (stud < 1 || stud > 10000)
				{
					std::cout << "Invalid student number, please try again." << std::endl;
				}
				else
				{
					studentNum = stud;
					studentGo = 1;
				}
			}
			
			//same as student entry
			while (classGo == 0)
			{
				std::cout << std::endl;
				std::cout << "Please enter class number (1-3000): " << std::endl;
				std::cin >> clas;
				
				int cl = 0;
				
				ss.clear();
				ss.str("");
				ss << clas;
				ss >> cl;
				
				if (cl < 1 || cl > 3000)
				{
					std::cout << "Invalid class number, please try again." << std::endl;
				}
				else
				{
					clasNum = cl;
					classGo = 1;
				}
			}
			
			multi->insert(studentNum, clasNum);
			
			//choosing this menu option again allows for other student/class additions
		}
		else if (inputMenu == "2")
		{
			//call printstrudents function
			multi->printStudent();
		}
		else if (inputMenu == "3")
		{
			//call printclass function
			multi->printClass();
		}
		else if (inputMenu == "4")
		{
			//exit menu and program
			keepGoing = 1;
		}
		else
		{
			//else display menu again
			std::cout << "Incorrect input, please enter the numeral of what you wish to do.\n" << std::endl;
		}
	}
	std::cout << "" << std::endl;
	std::cout << "Thank you, and goodbye" << std::endl;
}

//main function
int main()
{
	//make new multilist, pass it into menu, delete it when done
	Multilist * multi = new Multilist();
	menu(multi);
	delete multi;
	return 0;
}

