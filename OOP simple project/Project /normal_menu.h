
/*
 normal_menu.h
 03/29/2016
 CS411 Project prototype
 Leonardo Perrone
 F285y428
 
 Description: In this file is created a derived class for the basic menu type with several parameters and overloaded functions.
 */
#ifndef __Project_CS411__normal_menu__
#define __Project_CS411__normal_menu__

#include <stdio.h> //including libraries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "default_menu.h" //including header files


class NormalMenu: public Menu //derived class for basic menu
{
public:
    NormalMenu(const std::string& title = "Basic Menu", const std::string& appetizer = "Onion Rings", const std::string& entree = "Chicken Casserole", const std::string& dessert = "Ice Cream");
    
    ~NormalMenu();
    
    std::string menu_salad();
    std::string menu_drink();
    double calculate_cost(double drink_cost, double salad_cost, int people);

};




#endif /* defined(__Project_CS411__normal_menu__) */
