//  parts3.cpp
//  Leonardo Perrone
//  F285Y428
//  Assignment Number: 3
//  Last Changed: 

#include <iostream> //including libraries
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "utils.hpp" //including header file for utils
#include "parts1.hpp" //including header file for parts1

using namespace std;


void rtrim(string &s);   //Declaring void rtrim function
Part read_parts_records(string line); //declaring read_parts_records function

void save_part_list(Partlist &parts, char outfile_name[]);

bool add_part(Partlist &parts);

void delete_part(Partlist &parts);

int main() //main function
{
    int num_records = 0; //declaring variables
    int choice;
    Part part_list[100];
    string line;
    double weight_input;
    bool valid;
    char name_input[];
    int number_input;
    int sup1_input, sup2_input, stock_input;

    ifstream in_file("part_data.txt"); //opening file
    ofstream matching_parts; //output file
    
    if (in_file.fail())  //If opening file fails then give an error message
    {
        cout<<"Error: the file could not be opened."<<endl;     //if the file fails to open, give error message and terminate the program
        return -1;
    };
    
    
    while (!in_file.eof()) //loop to read the file input
    {
        getline(in_file, line);
        if (line.length() > 0)
        {
            part_list[num_records] = read_parts_records(line);
            num_records++;
        };
    };
    
    
    in_file.close(); //closing file

    
    
    cout << "Available choices:" << endl;
    
   // cout << "Enter weight to use for comparing with the parts' weights: "; //user prompt
   // cin >> weight_input; //storing user input value		
    
	weight_input = get_double("\nEnter weight to use for comparing with the parts' weights: ");

	do //loop in case choice differs from 3 options 
	{	
    	cout << "   1. Add part" << endl; //user options
    	cout << "   2. Delete part" << endl;
    	cout << "   3. Save part list" << endl;
    	cout << "   4. Quit" << endl;

    	//cout << "Enter the comparison type to use: "; //use choice
    	//cin >> choice; //storing user input value
    
    	choice = get_int("\nEnter the number of your choice: "); //calling get_int function 
    
    
    	switch (choice) //choice cases
    	{
        	case 1: 
			

			cout << "Adding a new part..." << endl;
			
			cout << "\tEnter part name: " << endl;
			cin >> name_input;

			cout << "\tEnter part number: " << endl;
			cin >> number_input;

			//cout << "\tEnter part weight: " << endl;
			weight_input = get_double("\nEnter part weight: ");

			cout << "\tEnter supplier code of primary supplier: " << endl;
			cin >> sup1_input;

			cout << "\tEnter supplier code fo secondary supplier: " << endl;
			cin >> sup2_input;

			cout << "\tEnter number in stock: " << endl;
			cin >> stock_input;

			
				
			
			
				
			
			matching_parts.open("part_matches.txt"); //less than
        	        for(int i=0; i<num_records ; i++)
        	        {
        	           // if(part_list[i].pname == name_input || part_list[i].pnumber == number_input || part_list[i].weight == weight_input || part_list[i].supplier1 == sup1_input || part_list[i].supplier2 == sup2_input || part_list[i].in_stock == stock_input)
        	            {
        	           // matching_parts << part_list[i].pname << " " << part_list[i].pnumber << ", " << part_list[i].weight << " N, " << part_list[i].in_stock << " in stock" << endl;
                
        	            };
                    
        	        };
			//cout<< "\nA list of parts matching your selection has been saved in the file part_list.txt."<<endl;
        	           // matching_parts.close();
			valid = false; 
			       
			break;
            
        	case 2: 
			cout << "Enter the part number of the part to delete: " << endl;
			//part number to delete
			cout << "Deleted the part: " << /*part name part number, part weight N, part number in stock*/ << endl;			
			


			matching_parts.open("part_list.txt"); //equal to
			for(int i=0; i<num_records ; i++)
        	        {
        	            if(part_list[i].pnumber == number_input)
        	            {
				//use the remove function here	            
			
				//matching_parts << part_list[i].pname << " " << part_list[i].pnumber << ", " << part_list[i].weight << " N, " << part_list[i].in_stock << " in stock" << endl;
                        
        	            };            
        	        };
            		cout<< "\nA list of parts matching your selection has been saved in the file part_list.txt."<<endl;
               		matching_parts.close();
        		valid = false;
			      		
			break;
            
	        case 3:	

			cout << "the current list of parts was saved in the file part_list.txt." << endl;

			/*matching_parts.open("part_matches.txt"); //greater than
			 for(int i=0; i<num_records ; i++)
        	        {
        	            if(part_list[i].weight > weight_input)
        	            {
        	            matching_parts << part_list[i].pname << " " << part_list[i].pnumber << ", " << part_list[i].weight << " N, " << part_list[i].in_stock << " in stock" << endl;
                
        	            };            
                	};
          		cout<< "\nA list of parts matching your selection has been saved in the file part_list.txt."<<endl;
                    	matching_parts.close();
            		valid = false;
			*/            		
			break;
		
		case 4: valid = true;

        	default: cout << "\nError. Invalid choice. Try again." << endl; //in case of invalid choice user is prompted again
            		 valid = false;
			 break;
    };
}
while(!valid);

 
    return 0;
}


Part read_parts_records(string line) //read_parts_record fucntion
{
    Part part1;
    
    string a = line.substr (0,17); //reading pname off the file
    rtrim(a);
    
    part1.pname = a; //storing name
    
    line = line.substr (17); //setting line equal to the rest of the line

    stringstream ss(line); //using stringstream

    ss >> part1.pnumber; //storing data from filo into structure
    ss >> part1.weight;
    ss >> part1.supplier1;
    ss >> part1.supplier2;
    ss >> part1.in_stock;

/*
    string b = line.substr (18,8);
    
    
    part1.pnumber = b;
    
    string c = line.substr (26,7);
    
    part1.weight = get_double(c);
    
    string d = line.substr (34,5);
    
    part1.supplier1 = d;
    
    string e = line.substr (39,5);
    
    part1.supplier2 = e;
    
    string f = line.substr (45,3);
    
    part1.in_stock = get_int(f);
*/
    return part1; //returning part1
}

void rtrim(string &s)	//creating a void function called rtrim to get rid of newline \n, \t, \r
{
    s.erase(s.find_last_not_of(" \n\r\t") + 1);
}
