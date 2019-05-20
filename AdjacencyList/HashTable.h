/*
Author: 	Jesus Rodriguez
Date:		11/4/2016
Assignment:	Program 2
File:		HashTable.h
Description:	This section of the program is the header file used for HashTable.cpp. It holds the member 
		function declarations for the HashTable class.
*/
#include "LinkedList.h"

class HashTable
{
private:
    
    LinkedList *list; // linked list
    
    int hashLength; // size of the hash table
    
    int HashFunction(char hashName); //returns the hash value
    
public:
    
	//Constructor
    HashTable(int hashTableLength = 25); // Set by default 
	//Don't forget to update the HashTable value
    
    void insert(char HeadLabel, char NodeLabel);

    void insert(LinkedList newList);
  
    void insert(Node *HeadNode, Node *newNode); // hash insert
    
    bool remove(char HeadLabel);

    bool remove(char Headlabel, char NodeLabel);
    
    Node *lookUp(int hashKey); // hash lookup
    
    int getLength(); // returns number of locations
    
    int getNumberOfNodes(); // returns number of nodes in the hash table
	
    void printBucketValues(); // detailed print of the hash table
    
    void printHistogram(); // higher-level view of the table

	//De-constructor
    ~HashTable();
};
