/*
Author: 	Jesus Rodriguez
Date:		11/4/2016
Assignment:	Program 2
File:		main.cpp
File Structure:	main.cpp and HashTable.cpp is dependent on HashTable.h
		HashTable.h and LinkedList.cpp is dependent on LinkedList.h
		LinkedList.h is not dependent on other files
Description:	This section of the program holds the main body of the program. The main body creates an
		ifstream object to read from the file "input.txt". If the file opens successfully, the program
		reads individually characters from the input file. Different input functions are then used to 
		determine the data type of input file before adding them to a node that is then inserted in the
		HashTable object. Finally, two functions display views of the hash table; one prints an overview
		of the hash table while the other prints the details of each node.
*/
#include "HashTable.h"

void readgraph(HashTable& table);
void readcommands(HashTable& table);

int main()
{
	// Create new nodes
	//*****************START*****************
//    Node *A = new Node;
	//*****************DONE*****************

    // create an istream object and open the file to be read
    std::ifstream in;
    in.open("graphtest.txt");

	//Create new (empty) hash table
    HashTable table;

    // check if the file opened correctly
    if(in.fail())
    {
	cout << "Failed to open the file.\n";
    }
    else
    {   
        char HeadLabel; // the characters label from the input file
	int count = 0; // a counter used to determine if a new linked list head is needed
	std::string input;
	
        in >> input; // prime the loop

        // loop until the end of the file
	while(!in.eof())
        {
            HeadLabel = input[0];
            for(int i = 0; i < input.size(); i++)
	    {
                if(isalpha(input[i])) table.insert(HeadLabel,input[i]);
            }
            in >> input;
        }
    }

    table.printBucketValues();
    in.close();
//		table.insert('A','K');
//		table.insert('K','K');
    table.printBucketValues();

    in.open("commandtest.txt");
   
    if(in.fail())
    {
	cout << "Failed to open the file.\n";
    }
    else
    {   
        std::string command;
//		table.insert('K','K');

        cout << "\nRunning the following commands...\n";
        in >> command;
        while(!in.eof())
        {
            if(command.compare(0,7,"addnode") == 0)
            {
                cout << "Adding Node " << command[8] << '\n';
	
               //table.insert(newNode, newNode);

                table.insert(command[8], command[8]);
            }
            else if(command.compare(0,7,"addedge") == 0)
            {
                table.insert(command[8], command[8]);
                for(int i = 7; i < command.size(); i++)
                {
                    if(isalpha(command[i]))
                    {
                        cout << "Adding Edge "<< command[i] << " to " << command[8] << '\n';
	                table.insert(command[8],command[i]); // insert the node
                    }
                }
            }
            else if(command.compare(0,10,"removenode") == 0)
            {
                cout << "Removing Node " << command[11] << '\n';
                if(table.remove(command[11]));
            }
            else if(command.compare(0,10,"removeedge") == 0)
            { 
                for(int i = 12; i < command.size(); i++)
                {
                    if(isalpha(command[i]))
                    {
                        cout << "Removing edge " << command[i] << " from " << command[11] << '\n';
                        table.remove(command[11], command[i]);
                    }  
                }
            }
            in >> command;
        }
    }
       
    table.printBucketValues();

    // close the file
    in.close(); 

    return 0;
}
void readgraph(HashTable& table)
{
    std::ifstream in;
    in.open("graphtest.txt");
 
    // check if the file opened correctly
    if(in.fail())
    {
	cout << "Failed to open the file.\n";
    }
    else
    {   
        char HeadLabel; // the characters label from the input file
        char NeighborLabel;
	int count = 0; // a counter used to determine if a new linked list head is needed
	std::string input;
	
        in >> input; // prime the loop

        // loop until the end of the file
	while(!in.eof())
        {
            HeadLabel = input[0];
            for(int i = 0; i < input.size(); i++)
	    {
                if(isalpha(input[i])) table.insert(HeadLabel,input[i]);
            }
            in >> input;
        }
    }

    in.close();
    table.printBucketValues();

    return;
}
void readcommands(HashTable& table)
{
    std::ifstream in;
    in.open("commandtest.txt");

    if(in.fail())
    {
	cout << "Failed to open the file.\n";
    }
    else
    {   
        std::string command;
        char HeadLabel;
        char NeighborLabel;

        cout << "\nRunning the following commands...\n";
        in >> command;
        while(!in.eof())
        {
            if(command.compare(0,7,"addnode") == 0)
            {
                HeadLabel = command[8];
                cout << "Adding Node " << command[8] << '\n';
                table.insert(HeadLabel, HeadLabel);
            }
            else if(command.compare(0,7,"addedge") == 0)
            {
                table.insert(command[8], command[8]);
                for(int i = 7; i < command.size(); i++)
                {
                    if(isalpha(command[i]))
                    {
                        cout << "Adding Edge "<< command[i] << " to " << command[8] << '\n';
	                table.insert(command[8],command[i]); // insert the node
                    }
                }
            }
            else if(command.compare(0,10,"removenode") == 0)
            {
                cout << "Removing Node " << command[11] << '\n';
                if(table.remove(command[11]));
            }
            else if(command.compare(0,10,"removeedge") == 0)
            { 
                for(int i = 12; i < command.size(); i++)
                {
                    if(isalpha(command[i]))
                    {
                        cout << "Removing edge " << command[i] << " from " << command[11] << '\n';
                        table.remove(command[11], command[i]);
                    }  
                }
            }
            in >> command;
        }
    }

    in.close();
    table.printBucketValues();

    return;
}

