#include "HashTable.h"

void HashTable::insert(Node *newNode)
{
    list[HashFunction(newNode->id)].insert(newNode); // call the LinkedList insert function
}

int HashTable::HashFunction(int hashKey)
{
   // return ((893*hashKey+791)%(38*19))/38; //https://courses.cs.washinton.edu/courses/cse326/00wi/handouts/lecture15/sld022.htm
    return hashKey % hashLength;
}

bool HashTable::remove(int hashKey)
{
    return list[HashFunction(hashKey)].remove(hashKey); // call the LinkedList remove function
}

Node * HashTable::lookUp(int hashKey)
{
    return list[HashFunction(hashKey)].getNode(hashKey); // call the LinkedList.getNode function
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
        NodeCount += list[i].getLength();
    }
    return NodeCount;
}

void HashTable::printBucketValues()
{
    cout << "\n\nHash Table Bucket Values:\n";
    for ( int i = 0; i < hashLength; i++ )
    {
        cout << "Bucket " << i + 1 << ": ";
        list[i].printList();
    }
}

void HashTable::printHistogram()
{
    cout << "\n\nHash Table Contains ";
    cout << getNumberOfNodes() << " Nodes total\n";
    for ( int i = 0; i < hashLength; i++ )
    {
        cout << i + 1 << ":\t";
        for ( int j = 0; j < list[i].getLength(); j++ )
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
