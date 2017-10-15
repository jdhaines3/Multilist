/*
* David Haines
* 362: Data Structures and Algorithms
* Project 2: Multilist
* Multilist cpp file
*/

#include <iostream>
#include <string>
#include "Multilist.h"


Multilist::Node::Node(int stu, int cla)
{
	this->studNum = stu;
	this->classNum = cla;
}

Multilist::Multilist()
{
	this->header = new Node(0,0);
	this->itrStu = this->header;
	this->itrCla = this->header;
}

void Multilist::insert(int stu, int cla)
{
	//create possible index nodes and new node to be added
	Multilist::Node *temp;
	Multilist::Node * addNode = new Node(stu, cla);
	
	//set student iterator to header to start
	this->itrStu = this->header;
	
	//iterate through list until the next number is greater than pointer or you reach end
	while (this->itrStu->nextStudent != NULL && this->itrStu->nextStudent->studNum < stu)
	{
		this->itrStu = this->itrStu->nextStudent;
	}
	//if reached end
	if (this->itrStu->nextStudent == NULL)
	{
		Multilist::Node * stuIndx = new Node(0, stu);
		//make next student the new index node
		this->itrStu->nextStudent = stuIndx;
		//make stuIndex nextStudent pointer to Null
		stuIndx->nextStudent = NULL;
		//increment 
		this->itrStu = this->itrStu->nextStudent;
	}
	else if(this->itrStu->nextStudent->studNum > stu)
	{
		//create index
		Multilist::Node * stuIndx = new Node(0, stu);
		//set temp to next node
		temp = this->itrStu->nextStudent;
		//set next node to new index node
		this->itrStu->nextStudent = stuIndx;
		//set next next node to old temp node
		this->itrStu->nextStudent->nextStudent = temp;
		//increment iterator to get to correct new index
		this->itrStu = this->itrStu->nextStudent;
	}
	//if equal, iterator in correct spot and no new node needed
	
	//set class iterator to student iterator to go down the column
	this->itrCla = this->itrStu;
	
	//from student col, iterate down
	while (this->itrCla->nextClass != NULL && this->itrCla->nextClass->classNum < cla)
	{
		this->itrCla = this->itrCla->nextClass;
	}
	if (this->itrCla->nextClass == NULL)
	{
		//if itr reaches end, add the new node
		this->itrCla->nextClass = addNode;
		//set pointer for new node to NULL after
		addNode->nextClass = NULL;
	}
	else if(this->itrCla->nextClass->classNum > cla)
	{
		//set next node to temp and insert new node
		temp = this->itrCla->nextClass;
		this->itrCla->nextClass = addNode;
		this->itrCla->nextClass->nextClass = temp;
		//no need to iterate again due to resetting back to header for row insertion
	}
	else if(this->itrCla->nextClass->classNum == cla)
	{
		//if node already there, delete the newly created one
		delete addNode;
		std::cout << "Node already exists." <<std::endl;
	}
	
	//reset iterators for insertion into class index
	this->itrCla = this->header;
	this->itrStu = this->header;
	
	//repeat for class index
	while (this->itrCla->nextClass != NULL && this->itrCla->nextClass->classNum < cla)
	{
		this->itrCla = this->itrCla->nextClass;
	}
	//if reached end
	if (this->itrCla->nextClass == NULL)
	{
		Multilist::Node * classIndx = new Node(cla, 0);
		this->itrCla->nextClass = classIndx;
		classIndx->nextClass = NULL;
		this->itrCla = this->itrCla->nextClass;
	}
	else if (this->itrCla->nextClass->classNum > cla)
	{
		Multilist::Node * classIndx = new Node(cla, 0);
		temp = this->itrCla->nextClass;
		this->itrCla->nextClass = classIndx;
		this->itrCla->nextClass->nextClass = temp;
		this->itrCla = this->itrCla->nextClass;
	}
	//if equal, iterator in correct spot and no new node needed
	
	//set class iterator to student iterator to go down the column
	this->itrStu = this->itrCla;
	
	//from student col, iterate down
	while (this->itrStu->nextStudent != NULL && this->itrStu->nextStudent->studNum < stu)
	{
		this->itrStu = this->itrStu->nextStudent;
	}
	if (this->itrStu->nextStudent == NULL)
	{
		//if itr reaches end, add the new node
		this->itrStu->nextStudent = addNode;
		//set pointer for new node to NULL after
		addNode->nextStudent = NULL;
	}
	else if(this->itrStu->nextStudent->studNum > stu)
	{
		//set next node to temp and insert new node
		temp = this->itrStu->nextStu;
		this->itrStu->nextStudent = addNode;
		this->itrStu->nextStudent->nextStudent = temp;
		//no need to iterate again due to resetting back to header for row insertion
	}
	else if(this->itrStu->nextStudent->studNum == stu)
	{
		//if node already there, delete the newly created one
		delete addNode;
		std::cout << "Node already exists." <<std::endl;
	}
	
	this->itrStu = this->header;
	this->itrCla = this->header;
	
}

void Multilist::printStudent()
{
	//make sure itr is at beginning
	this->itrStu = this->header;
	//while loop going through students
	while (this->itrStu != NULL)
	{
		//increment before printing due to starting at header to reach next index node
		this->itrStu = this->itrStu->nextStudent;
		//set class itr to stud itr to be in same col
		this->itrCla = this->itrStu;
		//increment to get to non-index node
		this->itrCla = this->itrCla->nextClass;
		//start print, flush to stay on same line
		std::cout << "Student #" + this->itrStu->studNum + ", Classes: " << std::flush;
		while (this->itrCla != NULL)
		{
			//add class num of next node, then iterate to next node
			std::cout << this->itrCla->classNum + "   " << std::flush;
			this->itrCla = this->itrCla->nextClass;
		}
		
		//print endl
		std::cout << std::endl;
	}
}
	
void Multilist::printClass()
{
	//same thing as print student but with class and student swapped\
	//make sure itr is at beginning
	this->itrCla = this->header;
	//while loop going through students
	while (this->itrCla != NULL)
	{
		//increment before printing due to starting at header to reach next index node
		this->itrCla = this->itrCla->nextClass;
		//set class itr to stud itr to be in same col
		this->itrStu = this->itrCla;
		//increment to get to non-index node
		this->itrStu = this->itrStu->nextStudent;
		//start print, flush to stay on same line
		std::cout << "Class #" + this->itrCla->classNum + ", Students: " << std::flush;
		while (this->itrStu != NULL)
		{
			//add class num of next node, then iterate to next node
			std::cout << this->itrStu->studNum + "   " << std::flush;
			this->itrStu = this->itrStu->nextStudent;
		}
		
		//print endl
		std::cout << std::endl;
	}
}

void Multilist::remove(int stu, int cla)
{
}
