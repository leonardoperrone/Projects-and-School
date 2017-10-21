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
#include "parts3.hpp" //including header file for parts1
#include "array_list.hpp"
using namespace std;


void rtrim(string &s);   //Declaring void rtrim function
Part read_parts_records(string line); //declaring read_parts_records function

bool add_part(Partlist &);
void delete_part(Partlist &parts);

void save_part_list(Partlist &parts, char outfile_name[]);

//bool add_part(Partlist &parts);

//void delete_part(Partlist &parts);

int main() //main function
{
    int choice, i;
    Partlist part_list;
    string line;
    double weight_input;
    bool valid = false;
    char name_input[16];
    string sup1_input, sup2_input, stock_input;

    ifstream in_file("part_data.txt"); //opening file
    
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
            part_list.add(read_parts_records(line));        
        };
    };
    
    
    in_file.close(); //closing file

    
    
    
    
   // cout << "Enter weight to use for comparing with the parts' weights: "; //user prompt
   // cin >> weight_input; //storing user input value        
    
    //weight_input = get_double("\nEnter weight to use for comparing with the parts' weights: ");

    do //loop in case choice differs from 3 options 
    {    
        cout << "Available choices:" << endl;
        cout << "   1. Add part" << endl; //user options
        cout << "   2. Delete part" << endl;
        cout << "   3. Save part list" << endl;
        cout << "   4. Quit" << endl;

        //cout << "Enter the comparison type to use: "; //use choice
        //cin >> choice; //storing user input value
    
        choice = get_int("\nEnter the number of your choice: "); //calling get_int function 
    
        bool success = false;
        switch (choice) //choice cases
        {
            case 1: 
                success = add_part(part_list);
                valid = false; 
                break;
            case 2: 
                delete_part(part_list);
                valid = false;
                break;
            case 3:
                save_part_list(part_list, "part_list.txt");
                valid = false;
                break;
        
            case 4: 
                valid = true;
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

void rtrim(string &s)    //creating a void function called rtrim to get rid of newline \n, \t, \r
{
    s.erase(s.find_last_not_of(" \n\r\t") + 1);
}

bool add_part(Partlist &parts)
{
    if (parts.size() >= MAX_PARTS)
    {
        return false;
    }

    Part temp;

    cout << "Adding a new part..." << endl;
    
    cout << "\tEnter part name: ";
    cin >> temp.pname;

    cout << "\tEnter part number: ";
    cin >> temp.pnumber;

    //cout << "\tEnter part weight: " << endl;
    temp.weight = get_double("\nEnter part weight: ");

    cout << "\tEnter supplier code of primary supplier: ";
    cin >> temp.supplier1;

    cout << "\tEnter supplier code fo secondary supplier: ";
    cin >> temp.supplier2;

    cout << "\tEnter number in stock: ";
    cin >> temp.in_stock;

    parts.add(temp);

    return true;
}

void delete_part(Partlist &parts)
{
    cout << "Enter the part number of the part to delete: ";

    string number_input;
    cin >> number_input;

    for(int i=0; i<parts.end(); i++)
    {
        if (parts.retrieve(i).pnumber == number_input)
        {
            cout << "Deleted the part: " << parts.retrieve(i).pname  << " " << parts.retrieve(i).pnumber << ", " << parts.retrieve(i).weight << " N," << parts.retrieve(i).in_stock << " in stock" << endl;
            parts.remove(i);
        }
    
    }
}

void save_part_list(Partlist &parts, char outfile_name[])
{
    ofstream matching_parts; //output file

    cout << "the current list of parts was saved in the file " << outfile_name << "." << endl;

    matching_parts.open(outfile_name); //greater than
    for(int i=0; i<parts.end() ; i++)
    {
        matching_parts << parts.retrieve(i).pname << " " << parts.retrieve(i).pnumber << ", " << parts.retrieve(i).weight << " N, " << parts.retrieve(i).in_stock << " in stock" << endl;
    };
    cout<< "\nA list of parts matching your selection has been saved in the file " << outfile_name << "." << endl;
    matching_parts.close();
}