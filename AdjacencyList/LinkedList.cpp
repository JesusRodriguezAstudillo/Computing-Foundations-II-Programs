/*
Author: 	Jesus Rodriguez
Date:		11/4/2016
Assignment:	Program 2
File:		LinkedList.cpp
Description:	This section of the program holds the constructor for the LinkedList class as well as the
		member functions of the LinkedList class.
*/
#include "LinkedList.h"

//Constructor
LinkedList::LinkedList()
{
    head = new Node;
    head = head -> next = NULL; 
    tail = new Node;
    tail = tail->next = NULL;
    empty = true;
    length = 0;
}

/*
Name:		insert
Parameters:	a node pointer representing a new node that will be added to the linked list
Return:		nothing
Description:	this fucntion takes in a node pointer and adds it to the head of the list
*/
void LinkedList::insert(Node * newNode)
{
    // only add a neighbor to the list if it is not already on the list
    if(!found(newNode->Label))
    {
        length++; // added a new node so increase the count
        if(head == NULL) // add to the head for the first node
        {
            head = tail = newNode;
        }
        else // add to the tail otherwise
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return;
}
/*
Name:		remove
Parameters:	an integer representing a hash key
Return:		a boolean representing whether a node was removed successfully, true, or not, false.
Description:	This function loops through a linked list while an iterator is not null. Inside a while loop,
		the id of the iterator is compared to the hash key paramenter. If the values match, the list
		rearranged before deleting the node and the function returns true. If the loop ends with the
		iterator as null, the parameter is not valid and the function does nothing and returns false.
*/
//bool LinkedList::remove(int NodeKey)
bool LinkedList::remove(char label) // remove a node
{
    Node *iter = head; // a pointer for the current node
    Node *prev = head; // a pointer for the previous node

    while(iter) // iterate while the iterator is not NULL
    {
	if(iter->Label == label) // compare values of current id to the one that needs to be deleted
	{ 
            if(iter == head) // if the node to be removed is the head, simply move the head to the next node
	    {
		head = iter->next;
	    }
	    else // else the deleted node is not the head so link the previous Node to the rest of the list and skip over the current node
	    {
	        prev->next = iter->next;
	        iter->next = NULL;
            }

            delete iter; // delete the node
            length--; // decrease the length of the list
	    return true; // the node was removed successfully
	}
	else // the current node does not have the key so move to the next node
	{
	    prev = iter; // keep track of the previous node
	    iter = iter->next; // move to the next node
        }
    } // loop ends with null iterator

    return false; // the id does not exist and the node was not removed
}
/*
Name:		getNode	
Parameters:	an int representing a hash key
Return:		a node pointer representing an individual
Description:	this function loops through a linked list using a pointer and compares the value of the
		parameter to the each node's id value. If they match, the iterator is returned. Else, the
		iterator becomes null and is then returned.
*/
Node * LinkedList::getNode(int NodeKey)
{
    // TODO
    Node *iter = head; // initialize an iterator to the head

/*    while(iter) // while the iterator is not NULL
    {
	if(iter->id == NodeKey) return iter; // if the key matches the current nodei, return the node
	else iter = iter->next; // else move to the next node
    }*/
    return iter; // return a NULL iter
}

// Prints the linked list
void LinkedList::printList()
{
    // set flags to modify output
    cout.setf(std::ios::showpoint); // Resource: Problem Solving with C++, 9th ed. Savitch, Walter.
    cout.setf(std::ios::right);
    cout.precision(3);

    if (length == 0)
    {
        cout << "\n   { } \n";
        return;
    }
    Node *p = head;
    Node *q = head;
    q = p->next;
  
    while (q)
    {
        p = q;
	cout << p->Label << ", ";		

	// print information for each node
	q = p->next;
    }
    cout << '\n';
}

bool LinkedList::found(char label)
{
    Node *iter = head; // iterator for a linked list initialized to the head
    // check if a particular node Label already exists
    while(iter != NULL) // loop while there are nodes
    {
        if(iter->Label == label) return true; // the node is already a neighbor in the list so return true
	else iter = iter->next; // check the next node
    } // there are no more nodes in the Linked list

    return false; // the node is not in the list
}
Node* LinkedList::getListHead() // return a node
{
	return head;
}

// Get and Return length of the list
int LinkedList::getLength()
{
    return length;
}

bool LinkedList::getempty()
{
    return empty;
}
void LinkedList::setempty(bool val)
{
    empty = val;

    return;
}

// De-Constructor
LinkedList::~LinkedList()
{
    Node *p = head;
    Node *q = head;
    while (q)
    {
        p = q;
        q = p->next;
        if (q) delete p;
    }
}
