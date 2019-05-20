#include "HashTable.h"
/*
Author: 	Jesus Rodriguez
Date:		11/4/2016
Assignment:	Program 2
File:		HashTable.cpp
Description:	This section of the program holds the function definitions for the HashTable class.
*/

/*void HashTable::insert(LinkedList newList)
{
    int index = newList.getListHead()->Name;

    Node *iter = new Node;
    Node *p = newList.getListHead();
    iter = newList.getListHead();

    if(list[index].getempty() == true)
    {
        list[index].setempty(false);
	while(iter != NULL)
	{
            list[index].insert(iter);
	    iter = iter->next;
	}
    }

    return;
}*/
void HashTable::insert(char HeadLabel, char NodeLabel)
{
    if(list[HeadLabel - 'A'].getempty() == true)
    {
        list[HeadLabel - 'A'].setempty(false);
    }

    if(!list[HeadLabel - 'A'].found(NodeLabel))
    {
        Node *Neighbor = new Node;
        Neighbor->next = NULL;
        Neighbor->Label = NodeLabel;
        Neighbor->Name = Neighbor->Label - 'A';
        list[HeadLabel - 'A'].insert(Neighbor);
    }

    if(list[NodeLabel - 'A'].getempty() == true)
    {
        list[NodeLabel - 'A'].setempty(false);
        insert(NodeLabel,NodeLabel); 
        insert(NodeLabel,HeadLabel); 
    }
    if(!list[NodeLabel - 'A'].found(HeadLabel))
    {
        insert(NodeLabel,HeadLabel);
    }

    return;
}
/*
Name:		insert
Parameters:	
Return:		nothing
Description:	
*/
void HashTable::insert(Node *HeadNode, Node *newNode) // hash insert
{
    Node *temp = new Node;
    temp = newNode;
    if(list[HeadNode->Label - 'A'].getempty() == true)
    {
        list[HeadNode->Label - 'A'].setempty(false);
    }
    list[HeadNode->Label - 'A'].insert(temp);
}

/*
Name:		HashFunction
Parameters:	an int representing a student's ID number
Return:		an int representing a hash key formed from a sudent's ID number
Description:	This function takes a student's ID number and uses modulus and the size of the hash
		table to generate a hash key.
*/
int HashTable::HashFunction(char hashName)
{
    return 'A' - hashName;
}

bool HashTable::remove(char HeadLabel)
{
    if(list[HeadLabel - 'A'].getempty() == false)
    {
        Node *iter = list[HeadLabel - 'A'].getListHead();
        Node *prev = iter;

        while(iter != NULL)
        {
            list[HeadLabel - 'A'].setempty(true);
	    prev = prev->next;
            list[HeadLabel - 'A'].remove(iter->Label);
            iter = prev;
        }
    
        for(int i = 0; i < hashLength; i++)
        {
            if(list[i].getempty() == false) list[i].remove(HeadLabel);
        }
        return true;
    }
    else return false;
}
bool HashTable::remove(char Headlabel, char NodeLabel)
{
    if(Headlabel == NodeLabel)
    {   
        cout << "Invalid Deletion\n";
        return false;
    }
    else return list[Headlabel - 'A'].remove(NodeLabel);
}
/*
Name:		remove
Parameters:	an int representing a student's ID
Return:		a boolean representing whether a student was removed successfully, true, or not, false
Description:	This function determines the hash key value from a student's ID before passing the
		ID to the LinkedList::remove function
*/
/*bool HashTable::remove(char label)
{
   // return list[HashFunction(hashKey)].remove(hashKey); // call the LinkedList remove function
}*/

/*
Name:		lookUp
Parameters:	an int representing a student's ID
Return:		a Node pointer representing a student node
Description:	This function uses the int parameter to generate a hash key before passing it to the
		LinkedList::getNode function.
*/
Node * HashTable::lookUp(int hashKey)
{
   // return list[HashFunction(hashKey)].getNode(hashKey); // call the LinkedList.getNode function
}

// ********** YOU DO NOT NEED TO CHANGE THE BELOW CODE! **********

// ********** YOU DO NOT NEED TO CHANGE THE BELOW CODE! **********

// insert function is given


// Below are functions I used to print my values to the screen
int HashTable::getNumberOfNodes()
{
    int NodeCount = 0;
    for ( int i = 0; i < hashLength; i++ )
    {
        if(list[i].getempty() != true) NodeCount++;
    }
    return NodeCount;
}

void HashTable::printBucketValues()
{
    // print the neighbors of each node in the hash table
    cout << "\nPrinting Adjacency List...\n";
    cout << "The undirected graph has " << getNumberOfNodes() << " nodes total.\n";
    for ( int i = 0; i < hashLength; i++ )
    {
	// print only the buckets that are not empty
	if(list[i].getempty() == false)
	{
	    cout << list[i].getListHead()->Label << ":\t"; 
            list[i].printList();
        }
    }
   
    cout << "\nPrinting Adjacency Matrix...\n";
 
    // print the index of the adjacency matrix
    cout << "  | ";
    for(int i = 0; i < hashLength; i++)
    {
	if(list[i].getempty() == false) cout << list[i].getListHead()->Label << " | ";
    }
    cout << endl;
   
    // print the upper border of the adjacency matrix
    cout << "   ";
    for(int i = 0; i <  hashLength; i++)
    {
	if(list[i].getempty() == false) cout << "----";
    }
    cout << endl;

    // print the array of the adjacency matrix
    for(int i = 0; i <  hashLength; i++)
    {
	if(list[i].getempty() == false)
        {
            cout << list[i].getListHead()->Label << " | ";
	    for(int j = 0; j < hashLength; j++)
 	    {
	        if(i == j) cout << "0 | ";
	        else if(list[j].getempty() == false) cout << list[i].found('A' + j) << " | ";
            }
            cout << endl;
        }
    }
   
    // print the lower border of the adjecency matrix
    cout << "   ";
    for(int i = 0; i <  hashLength; i++)
    {
	if(list[i].getempty() == false) cout << "----";
    }
    cout << endl;

    return;
}

void HashTable::printHistogram()
{
    cout << "\n\nHash Table Contains ";
    cout << getNumberOfNodes() << " Nodes total\n";
    for ( int i = 0; i < hashLength; i++ )
    {
        cout << i + 1 << ":\t";
        for ( int j = 0; j < list[i].getLength(); j++)
            cout << " O";
        cout << "\n";
    }
}

// Constructor
HashTable::HashTable(int hashTableLength)
{
    if (hashTableLength <= 0) hashTableLength = 10;
    list = new LinkedList[hashTableLength];
    hashLength = hashTableLength;
}

// De-constructor
HashTable::~HashTable()
{
    delete [] list;
}
