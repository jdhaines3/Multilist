/*
* David Haines
* 362: Data Structures and Algorithms
* Project 2: Multilist
* Multilist header file
*/

#ifndef MULTILIST_H
#define MULTILIST_H

//2-D Multilist class with nested Node struct
class Multilist {
	private:
		struct Node {
			int studNum;
			int classNum;
			
			//pointers for x and y axis
			Node *nextStudent, *nextClass;
			
			//constructor for node with student number and class number
			Node(int studNum, int classNum);
		};
		
		Node *header;
		//two iterators, one for row one for col
		Node *itrStu;
		Node *itrCla;
		
		
	public:
		//constructor for new empty list
		Multilist();
		
		//destructor
		~Multilist();
		
		void insert(int studNum, int classNum);
		
		void remove(int studNum, int classNum);
		
		void printStudent();
		
		void printClass();
		
};

#endif

		
		
