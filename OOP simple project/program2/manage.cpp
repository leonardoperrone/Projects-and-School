//  main.cpp
//  Assignment: 2
//  Created by Leonardo Perrone on 2/25/16.
//  ID: F285Y428
//
/*Desription: This program has a base class Student and two derived classes UndergradStudent and GradStudent.
  Both derived class have one constructor parameter that links to the base class.
  Using fucntions, accessors and mutators it is possible to change some of the information of the objects created of each type.
*/
#include <stdio.h> //including libraries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "student.hpp" //including header files
#include "undergradstudent.hpp"
#include "gradstudent.hpp"

int main() //main function
{

    UndergradStudent s("Test"); //new object of type undergradstudent
    std::cout << std::endl << "List when created:" << std::endl;
    s.print_class_list();
    s.add_class("Data Structures"); //adding 1st class
    std::cout << std::endl << "List after adding first class:" << std::endl;
    s.print_class_list();
    s.add_class("OOP");//adding 2nd class
    std::cout << std::endl << "List after adding second class:" << std::endl;
    s.print_class_list(); //printing list
    std::cout << std::endl;

    GradStudent p("Test2", "Engineering"); //new object of type gradstudent

    p.set_research_area("Aereospace"); //changing research area
    p.set_research_area("Economy");
    p.set_name("Test2");

    UndergradStudent *q; //creating pointer of type undergradstudent
    q = new UndergradStudent("Test3"); //create new dyanamically allocated object

    std::cout << std::endl << "List when created:" << std::endl; //repeating procedure
    q->print_class_list();
    q->add_class("Data Structures");
    std::cout << std::endl << "List after adding first class:" << std::endl;
    q->print_class_list();
    q->add_class("OOP");
    std::cout << std::endl << "List after adding second class:" << std::endl;
    q->print_class_list();
    std::cout << std::endl;

    GradStudent *t; //creating pointer of type gradstudent
    t = new GradStudent("Test4", "Philosophy"); //create new dyanamically allocated object

    t->set_research_area("Aereospace"); //repeating procedure
    t->set_research_area("Economy");
    t->set_name("Test2");

};

