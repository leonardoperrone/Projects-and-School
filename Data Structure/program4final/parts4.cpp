//  parts4.cpp
//  Leonardo Perrone
//  F285Y428
//  Assignment Number: 4
//  Last Changed: 3/24/2015

// Description: This program uses a combination of File I/O, Data Structures and Linked lists to 
//     access part data from a file, add parts to the list of parts, delete parts form the list of
//     part, and save it to an output file. 
  
#include <iostream> //including libraries
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "utils.hpp" //including header file for utils
#include "parts4.hpp" //including header file for parts3
#include "sllist.hpp" //including header file for array_list
using namespace std; //using namespace


void rtrim(string &s);   //Declaring void rtrim function
Part read_parts_records(string line); //declaring read_parts_records function

bool add_part(Partlist &); //declaring add_part function
void delete_part(Partlist &parts); // delcaring delete_part fucntion
void save_part_list(Partlist &parts, const char outfile_name[]); //declaring save_part_list function


int main() //main function
{
    int choice; //declaring variables
    Partlist part_list; 
    string line,sup1_input, sup2_input, stock_input;
    
    
    bool valid = false;

    ifstream in_file("part_data.txt"); //opening file
    
    if (in_file.fail())  //If opening file fails then give an error message
    {
        cout<<"Error: the file could not be opened."<<endl; //if the file fails to open, give error message and terminate the program
        return -1;
    };
    
    
    while (!in_file.eof()) //loop to read the file input
    {
        getline(in_file, line);

        if (line.length() > 0)
        {
            
            part_list.add(read_parts_records(line)); //calling read_parts_records to read parts list
                
        };
    };
    
    
    in_file.close(); //closing file

    
    
    
    
   
    do //loop in case choice differs from 3 options 
    {    
        cout << "\nAvailable choices:" << endl;  //user options
        cout << "   1. Add part" << endl; 
        cout << "   2. Delete part" << endl;
        cout << "   3. Save part list" << endl;
        cout << "   4. Quit" << endl;

      
    
        choice = get_int("\nEnter the number of your choice: "); //calling get_int function 
    
        bool success = false; // bool to check if there's enough space on list to add new part
        switch (choice) //choice cases
        {
            case 1:
                success = add_part(part_list); //call add_part function while checking if there's enough space to add 
                valid = false; 
                break;
            case 2: 
                delete_part(part_list); // calling delete_part function
                valid = false;
                break;
            case 3:
                save_part_list(part_list, "part_list.txt"); // calling save-part_list function
                valid = false;
                break;
        
            case 4: 
                valid = true; //quit the program
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

    ss >> part1.pnumber; //storing data from file into structure
    ss >> part1.weight;
    ss >> part1.supplier1;
    ss >> part1.supplier2;
    ss >> part1.in_stock;

    


    return part1; //returning part1
}

void rtrim(string &s)    //creating a void function called rtrim to get rid of newline \n, \t, \r
{
    s.erase(s.find_last_not_of(" \n\r\t") + 1);
}

bool add_part(Partlist &parts) //function that allows user to add a new part
{
    Part temp; //declaring variable temp

    cout << "Adding a new part..." << endl; //user promted to enter several info to add part and storing part data into variable
    
    cout << "\tEnter part name: ";
    cin >> temp.pname;

    cout << "\tEnter part number: ";
    cin >> temp.pnumber;

    temp.weight = get_double("\tEnter part weight: "); // calling get-double function

    cout << "\tEnter supplier code of primary supplier: ";
    cin >> temp.supplier1;

    cout << "\tEnter supplier code of secondary supplier: ";
    cin >> temp.supplier2;

    cout << "\tEnter number in stock: ";
    cin >> temp.in_stock;

    parts.add(temp); //adding the part created

    return true;
}

void delete_part(Partlist &parts) //delete part function
{
    cout << "\nEnter the part number of the part to delete: "; //user input of part number to be deleted

    string number_input; 
    cin >> number_input; //input from user stored into variable

    PartNode *current = parts.first(); //setting current at the beginning of list

    while (current != NULL)
    {
        Part part = parts.retrieve(current); //using retrieve function set the pointer

        if (part.pnumber == number_input) //if part number matches, delete part
        {
            cout << "\nDeleted the part: " << part.pname  << " " << part.pnumber << ", " << part.weight << " N," << part.in_stock << " in stock" << endl;
            parts.remove(current); //remove part form list
        }

        current = parts.next(current);
    }

    // for(int i=0; i<parts.end(); i++) //for loop to delete the part 
    // {
    //     if (parts.retrieve(i).pnumber == number_input) //if part number matches, delete part
    //     {
    //         cout << "Deleted the part: " << parts.retrieve(i).pname  << " " << parts.retrieve(i).pnumber << ", " << parts.retrieve(i).weight << " N," << parts.retrieve(i).in_stock << " in stock" << endl;
    //         parts.remove(i);
    //     }
    
    // }
}

void save_part_list(Partlist &parts, const char outfile_name[]) //save the new list fucntion 
{
    ofstream matching_parts; //output file

    

    matching_parts.open(outfile_name); //opening new file 

    PartNode *current = parts.first(); //setting current at the beginning of list

    while (current != NULL)
    {
        Part part = parts.retrieve(current); //using retrieve function set the pointer

        matching_parts << part.pname << " " << part.pnumber << ", " << part.weight << " N, " << part.in_stock << " in stock" << endl;

        current = parts.next(current); //using next function to go  to next part
    }


    // for(int i=0; i<parts.end() ; i++) //printing to the file the new list
    // {
    //     matching_parts << parts.retrieve(i).pname << " " << parts.retrieve(i).pnumber << ", " << parts.retrieve(i).weight << " N, " << parts.retrieve(i).in_stock << " in stock" << endl;
    // };
    cout << "\nThe current list of parts was saved in the file " << outfile_name << "." << endl; // print on new file the new list

    matching_parts.close();
}