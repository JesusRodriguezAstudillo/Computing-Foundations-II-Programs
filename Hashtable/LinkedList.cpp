#include "LinkedList.h"

//Constructor
LinkedList::LinkedList()
{
    head = new Node;
    head = head -> next = NULL;
    length = 0;
}

void LinkedList::insert(Node * newNode)
{
    length++; // added a new node so increase the count

    newNode->next = head; // Link the node at the head of the list
    head = newNode; // Move the head to point to the first element in the list
}
bool LinkedList::remove(int NodeKey)
{
    Node *iter = head; // a pointer for the current node
    Node *prev = head; // a pointer for the previous node

    while(iter) // iterate while the iterator is not NULL
    {
	if(iter->id == NodeKey) // compare values of current id to the one that needs to be deleted
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
    }

    return false; // the id does not exist and the node was not removed
}

Node * LinkedList::getNode(int NodeKey)
{
    // TODO
    Node *iter = head; // initialize an iterator to the head

    while(iter) // while the iterator is not NULL
    {
	if(iter->id == NodeKey) return iter; // if the key matches the current node return the node
	else iter = iter->next; // else move to the next node
    }
    return iter; // return a NULL iter
}

// Prints the linked list
void LinkedList::printList()
{
    // set flags to modify output
    cout.setf(std::ios::showpoint);
    cout.setf(std::ios::right);
    cout.precision(3);

    if (length == 0)
    {
        cout << "\n   { } \n";
        return;
    }
    Node *p = head;
    Node *q = head;
    cout << "\n";
    while (q)
    {
        p = q;

	// print information for each node
        cout << "   { " << "ID| " << p->id << "   ";
        cout << "Major| ";
        cout.width(2);
        cout << p->Major << "   ";
        cout << "GPA| " << p->GPA << " }\n"; 
	q = p->next;
    }
}

// Get and Return length of the list
int LinkedList::getLength()
{
    return length;
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
