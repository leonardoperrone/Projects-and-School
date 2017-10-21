//
//  gradstudent.cpp
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
#include "gradstudent.hpp"

GradStudent::GradStudent(const std::string& name, const std::string& research_area) : Student(name), m_research_area(research_area)
{
    std::cout << "The research area at the beginning is: " << m_research_area << std::endl;

}

std::string GradStudent::get_research_area(void)
{
    return m_research_area;
}

void GradStudent::set_research_area(std::string research_area)
{
    m_research_area = research_area;

    std::cout << "The research area after changing it is: " << m_research_area << std::endl;
}

