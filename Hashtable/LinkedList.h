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

#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;

// TODO: Create a Node that will hold:
//			Student ID (int)
//			Student GPA (double)
//			Student Major (string)
//			Pointer to the next node
struct Node
{
    int id;
    double GPA;
    std::string Major;
    Node *next;
};

class LinkedList
{
private:
    Node *head; // to keep track of the head
    
    int length; // number of values in the list
    
public:
	// Constructor
    LinkedList();
    
    void insert(Node *newNode); // insert new node
    
    bool remove(int NodeKey); // remove a node
    
    Node *getNode(int NodeKey); // return a node
    
    void printList(); // print the linked list
    
    int getLength(); // returns length of the list
    
	// De-constructor
    ~LinkedList();
};
