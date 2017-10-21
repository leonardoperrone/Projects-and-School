//  classlist.cpp
//  Leonardo Perrone
//  F285y428
//  Assignment: 6
//  Last Changed: 4/29/15.

// Description: This program uses a combination of Trees, Keys and Nodes to read a file with a list of students enrolled in a class,
// then read a file with a list of studentds that dropped the class,
// and finally it will write to a file the final list of students enrolled in the class while removing the duplicates.


#include "classlist.hpp"
#include "bin_search_tree.hpp"
#include <iostream> //including libraries
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;


Tree f_tree= NULL;
Tree studTree;


int main()
{

    ifstream enrollment_file("enrollment_list.txt"); //opening file
    ifstream drop_file("drop_list.txt"); //opening file

    string studentName;
    string line;
      
    if (enrollment_file.fail())  //If opening file fails then give an error message
    {
        cout<<"Error: the file could not be opened."<<endl;     //if the file fails to open, give error message and terminate the program
        return -1;
    };
   
   while (!enrollment_file.eof()) //loop to read the file input
    {
        getline(enrollment_file, line); //get lines from file
        if (line.length() > 0) //if it's not the end of file
        {
            studentName = read_students(line); // read students from file
          
            if(studTree==NULL) //if tree is empty
            {
                studTree= tree_makenode(studentName, NULL); //create node with tree_makenode and insert into tree
            }
            else
            {
                tree_insert(&studTree, studentName); // if tree not empty then insert node into tree from string
            }
        };
    };

    enrollment_file.close(); //closing file
   
    if (drop_file.fail())  //If opening file fails then give an error message
    {
        cout<<"Error: the file could not be opened."<<endl;     //if the file fails to open, give error message and terminate the program
        return -1;
    }

    
    while (!drop_file.eof()) //loop to read the file input
    {
        getline(drop_file, line); //get lines from file
        if (line.length() > 0) //if it's not the end of file
        {
            studentName = read_students(line); // read students from file

            tree_remove(studTree, studentName); // remove student using remove function
        }
    };
    
    drop_file.close(); //closing file
    

    
    ofstream finalclasslist; //output file
    finalclasslist.open("classlist.txt"); //open output file
    tree_inorder(studTree, finalclasslist); //set oreder of names
    finalclasslist.close(); //close file
    cout << "The class list was saved in the file classlist.txt."
    << endl; //printed to display
    
    return 0;
}


string read_students (string line) //read_parts_record fucntion
{
    int i; //declaring variables
    string classCode, studentFirst, studentMiddle, studentLast, finalString;
    
    for(i=0; line[i] != ':'; i++ ) //forloops reading data from file while skipping the ':'
    {
        classCode+=line[i];
    }
    i++;
    
    for (; line[i] != ':' ; i++)
    {
        studentFirst+=line[i];

    }
    i++;
    
    for (; line[i] != ':'; i++)
    {
        studentMiddle+=line[i];
        
    }
    i++;
    
    for (; i != line.length(); i++) {
        studentLast+=line[i];
        
    }
    
    finalString+=studentLast; //storing all the names into finalString 
    finalString+= ", ";
    finalString+=studentFirst;
    finalString+= ", ";
    finalString+=studentMiddle;
    
    
    return finalString; //returning
}


