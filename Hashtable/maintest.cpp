#include "HashTable.h"

int main()
{
	// Create new nodes
	//*****************START*****************
    Node *A;
	//*****************DONE*****************
    std::ifstream in;
    in.open("test.txt");

	//Create new (empty) hash table
    HashTable table;

    if(in.fail())
    {
	cout << "Failed to open the file.\n";
    }

    std::string r_line;
    std::string temp;
    size_t comma1;
    size_t comma2;

	// cite cplusplus.com
    getline(in, r_line);
    while(!EOF) {}
    cout << r_line << endl;

    comma1 = r_line.find(',');
    comma2 = r_line.find(',', comma1 +1);

    temp = r_line.substr(0, comma1);
    temp = r_line.substr(comma1+1, comma2-comma1-1);
    temp = r_line.substr(comma2+1);

    getline(in, r_line);
    cout << r_line << endl;
	//Insert some data
/*    for(int i = 1; i <= 3; i++)
    {
	A = new Node;
	A->id = 1000+i;
	A->Major = "Computer Science";
	A->GPA = 3 + (i%10)*.1;
	table.insert(A);
    }*/

	//NOTE: The given hash function is not a good hash function
	//		You are required to research and submit your own
	//		Don't forget to properly cite your resource(s)
	
	//Show Update
    table.printBucketValues();
//    table.printHistogram();
    
/*	//Remove a Node
    int id1 = 8745;
    int id2 = 1002;

    cout << "Removing ID: " << id1 << endl;
    if(table.remove(id1)) cout << "Removal successful\n\n"; // attempt to remove invalid ID
    else cout << "Student was not removed\n\n";
   
    cout << "Removing ID: " << id2 << endl;
    if(table.remove(id2)) cout << "Removal successful\n\n"; // remove valid ID
    else cout << "Student was not removed\n\n";

	//Show Update
    table.printBucketValues();
    table.printHistogram();
   
    // add the remaining nodes using a for loop
    for(int i = 4; i < 27; i++)
    {
	A = new Node;
	A->id = 1000+i;
	A->Major = "Computer Science";
	A->GPA = 3+ (i%10)*.1;
	table.insert(A);
     }

	//Show update
    table.printBucketValues();
    table.printHistogram();
	
	//Perform a LookUp and Print the node to the screen
    id1 = 1002;
    Node *n_id1;
    id2 = 1017;
    Node *n_id2;

    cout << "Looking up ID: " << id1 << endl;
    if(n_id1 = table.lookUp(id1)) // attempt to lookup  invalid ID
    {
	cout << "ID: " << n_id1->id << endl;
	cout << "GPA: " << n_id1->GPA << endl;
	cout << "Major: " << n_id1->Major << endl << endl; 
    }
    else cout << "The ID was not found.\n\n";
 
    cout << "Looking up ID: " << id2 << endl;
    if(n_id2 = table.lookUp(id2)) // lookup valid ID
    {
	cout << "ID: " << n_id2->id << endl;
	cout << "GPA: " << n_id2->GPA << endl;
	cout << "Major: " << n_id2->Major << endl << endl;
    }
    else cout << "The ID was not found.\n\n";
*/
    in.close();

    return 0;
}
