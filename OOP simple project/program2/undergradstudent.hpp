/*
 * undergradstudent.hpp
 *
 *  Created on: Feb 17, 2016
 *      Author: leonardoperrone
 */
//
//  undergrastudent.h
//  Assignment 2 cs411
//
//  Created by Leonardo Perrone on 2/25/16.
//  Copyright (c) 2016 Leonardo Perrone. All rights reserved.
//
#ifndef UNDERGRADSTUDENT_HPP_
#define UNDERGRADSTUDENT_HPP_

#include <stdio.h> //including libraries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "student.hpp"


class UndergradStudent: public Student
{
public:
    UndergradStudent(const std::string& name = "");
    ~UndergradStudent();

    //accessor
    void print_class_list(void);
    //mutator
    void add_class(std::string enrolled);

private:
   std::vector<std::string> m_class_list;

};


#endif /* UNDERGRADSTUDENT_HPP_ */
