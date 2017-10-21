//
//  student.cpp
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
#include "student.hpp"


Student::Student(const std::string& name) : m_name(name)
{
    
}

std::string Student::get_name(void)
{
    return m_name;
}

void Student::set_name(std::string name)
{
    m_name = name;
}

