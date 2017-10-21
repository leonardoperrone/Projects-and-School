
/*
 mexica_menu.h
 03/29/2016
 CS411 Project prototype
 Leonardo Perrone
 F285y428
 
 Description: In this file is created a derived class for the mexican menu type with several parameters and overloaded functions.

 
 */

#ifndef __Project_CS411__mexica_menu__
#define __Project_CS411__mexica_menu__


#include <stdio.h> //including libraries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "default_menu.h" //including header files

class MexicanMenu: public Menu //derived class for mexican menu
{
public:
    MexicanMenu(const std::string& title = "Mexican Menu", const std::string& appetizer = "Chips & Queso", const std::string& entree = "Tacos al Fuego", const std::string& dessert = "Tres Leches Cake");
    
    ~MexicanMenu();
    
    std::string menu_salad();
    std::string menu_drink();
    double calculate_cost(double drink_cost, double salad_cost, int people);

};




#endif /* defined(__Project_CS411__mexica_menu__) */
