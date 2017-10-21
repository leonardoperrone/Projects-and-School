//
//  gradstudent.h
//  Assignment 2 cs411
//
//  Created by Leonardo Perrone on 2/25/16.
//  Copyright (c) 2016 Leonardo Perrone. All rights reserved.
//
#ifndef GRADSTUDENT_HPP_
#define GRADSTUDENT_HPP_

#include <stdio.h> //including libraries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "student.hpp"

class GradStudent : public Student
{
public:
    GradStudent(const std::string& name = "", const std::string& research_area = "");
    //accessor
    std::string get_research_area(void);

    //mutator
    void set_research_area(std::string research_area);

private:

    std::string m_research_area;

};




#endif /* GRADSTUDENT_HPP_ */
