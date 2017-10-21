//
//  undergrastudent.cpp
//  Assignment 2 cs411
//
//  Created by Leonardo Perrone on 2/25/16.
//  Copyright (c) 2016 Leonardo Perrone. All rights reserved.
//

#include <stdio.h> //including libraries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>

#include "undergradstudent.hpp"

#include "student.hpp"

UndergradStudent::UndergradStudent(const std::string& name) : Student(name)
{

}

UndergradStudent::~UndergradStudent()
{

}




void UndergradStudent::print_class_list(void)
{

    int i;

    for (i = 0; i < m_class_list.size(); i++)
    {
        std::cout << "Class " << i+1 << ":" << m_class_list.at(i)  << std::endl;
    };

}

void UndergradStudent::add_class(std::string enrolled)
{
    m_class_list.push_back(enrolled);


};

