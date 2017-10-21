//
//  student.h
//  Assignment 2 cs411
//
//  Created by Leonardo Perrone on 2/25/16.
//  Copyright (c) 2016 Leonardo Perrone. All rights reserved.
//

#ifndef STUDENT_HPP_
#define STUDENT_HPP_
#include <stdio.h> //including libraries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>

class Student
{
public:
    //constructor
    Student(const std::string& name = "");

    //accessor
    std::string get_name(void);
        //mutator
    void set_name(std::string name);


private:

    std::string m_name;
};





#endif /* STUDENT_HPP_ */
