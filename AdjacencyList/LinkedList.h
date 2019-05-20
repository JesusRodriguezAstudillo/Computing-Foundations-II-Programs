/* ** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * A 'bare-bones' version of a linked list.  								 *
 *																			 *
 * You are welcomed to use your own. 										 *
 * This is a NOT a one-size fits all!		 								 *
 * You are also allowed to use the C++ Linked List template.				 *
 * You are still NOT ALLOWED to use the standard library!!! 				 *
 *		(You will get a 0 if you do!)										 *
 * 																			 *
 * Below you will find some includes that I used in my implementation.		 *
 * 																			 *
 * Should you choose to use the C++ Linked List template, you may need to 	 *
 * move your similar definitions into HashTable.h							 *	
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*
Author: 	Jesus Rodriguez
Date:		11/4/2016
Assignment:	Program 2
File:		LinkedList.h
Resources:	Problem Solving with C++, 9th ed. Savitch, Walter.
Description:	This section of the program is the header file used for LinkedList.cpp. The file holds
		the libraries to compile the entire program as well as the functions declarations
		used for the LinkedList class.
*/

#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;

struct Node
{
    int Name;
    char Label;
    Node *next;
};

class LinkedList
{
private:
    Node *head; // to keep track of the head
    Node *tail;    
    bool empty;
    int length; // number of values in the list
    
public:
	// Constructor
    LinkedList();
    
    void insert(Node *newNode); // insert new node
    
    //bool remove(int NodeKey); // remove a node
    bool remove(char label); // remove a node
    
    Node *getNode(int NodeKey); // return a node
    Node *getListHead(); // return a node
    
    void printList(); // print the linked list
    
    int getLength(); // returns length of the list

    bool found(char label);

    bool getempty();
    void setempty(bool val);

	// De-constructor
    ~LinkedList();
};
