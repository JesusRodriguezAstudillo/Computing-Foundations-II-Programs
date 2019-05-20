#include "HashTable.h"

int main()
{
	// Create new nodes
	//*****************START*****************
    Node *A = new Node;
	//*****************DONE*****************
 
    // create an istream object and open the file to be read
    std::ifstream in;
    in.open("input.txt");

	//Create new (empty) hash table
    HashTable table;

    // check if the file opened correctly
    if(in.fail())
    {
	cout << "Failed to open the file.\n";
    }
    else
    {
        char c; // a character variable to traverse through the file
        in.get(c); // prime the loop by getting a character from the file
  
        // Loop through the file and pick up the values for each node
        while(!in.eof()) // while not the end of file
        {
            // determine if a numerical value is an integer or a decimal number
            if(isdigit(c))
            {
    	        char p = in.peek(); // check the next value in the file
    	        if(p == '.') // if the next value is a period, read in a double value
    	        {
    	            double GPA;
	            in.putback(c);
   	            in >> GPA;
	            A->GPA = GPA;
	        }
	        else // read in an integer value for the ID
	        {
		    int ID;
	            in.putback(c);
	            in >> ID;
	            A->id = ID;
	        }
            }
            // check if the character is an alphabetical value to read in the major
            else if(isalpha(c))
            {
	        std::string Major;
	        in.putback(c);
	        in >> Major;
                A->Major = Major;
            }
	
             // once an endline is read, all values for a node are assigned
            if(c == '\n')
            {
	        table.insert(A); // add the node
	        A = new Node; // create a new address for the next node
	    }

            in.get(c); // continue traversing the file
        }

        	//Show Update
        table.printBucketValues();
        table.printHistogram();
    }

    in.close();

    return 0;
}
