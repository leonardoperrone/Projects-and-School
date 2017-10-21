
/*
 italian_menu.h
 03/29/2016
 CS411 Project prototype
 Leonardo Perrone
 F285y428
 
 Description: In this file is created a derived class for the italian menu type with several parameters and overloaded functions.

 */
#ifndef __Project_CS411__italian_menu__
#define __Project_CS411__italian_menu__

#include <stdio.h> //including libraries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "default_menu.h" //including header files


class ItalianMenu: public Menu //derived class for italian menu
{
public:
    ItalianMenu(const std::string& title = "Italian Menu", const std::string& appetizer = "Bruschetta", const std::string& entree = "Pasta alla Carbonara", const std::string& dessert = "Tiramisú");
    
    ~ItalianMenu();
    
    std::string menu_salad();
    std::string menu_drink();
    double calculate_cost(double drink_cost, double salad_cost, int people);

};




#endif /* defined(__Project_CS411__italian_menu__) */
