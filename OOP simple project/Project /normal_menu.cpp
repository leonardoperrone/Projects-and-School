
/*
 normal_menu.cpp
 03/29/2016
 CS411 Project prototype
 Leonardo Perrone
 F285y428
 
 Description: in this file is implemented the derived class NormalMenu which is a basic menu with common dishes. A few functions are overloaded on the ones of the base class.
 */

//including header files
#include "normal_menu.h"
#include "default_menu.h"
#include "global.h"

//including libraries
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>

//constructor
NormalMenu::NormalMenu(const std::string& title, const std::string& appetizer, const std::string& entree, const std::string& dessert) : Menu(title, appetizer, entree, dessert)
{
    
}

//desructor
NormalMenu::~NormalMenu()
{

}

//salad menu return a string
std::string NormalMenu::menu_salad()
{
    int choice;
    std::string salad;
    std::cout << "Select salad type:" << std::endl << "1. Caesar Salad" << std::endl << "2. Spinach Salad" << std::endl << "3. Grilled Veggie Salad" << std::endl << std::endl << "Enter selection: " ;
    std::cin >> choice;
    std::cout << std::endl;
    
    switch (choice)
    {
        case 1:
            salad = "Caesar Salad";
            set_salad_cost(caesar);
            break;
        case 2:
            salad = "Spinach Salad";
            set_salad_cost(spinach);
            break;
        case 3:
            salad = "Grilled Veggie Salad";
            set_salad_cost(grilled);
            break;
        default:
            break;
    }
    
    return salad;
}

//drink menu returns string
std::string NormalMenu::menu_drink()
{
    int choice;
    std::string drink;
    std::cout << "Select drink type:" << std::endl << "1. Water" << std::endl << "2. Coke" << std::endl << "3. Beer" << std::endl << std::endl << "Enter selection: ";
    std::cin >> choice;
    std::cout << std::endl;
    
    
    switch (choice)
    {
        case 1:
            drink = "Water";
            set_drink_cost(water);
            break;
        case 2:
            drink = "Coke";
            set_drink_cost(coke);
            break;
        case 3:
            drink = "Beer";
            set_drink_cost(beer);
            break;
        default:
            break;
    }
    
    return drink;
    
}

//calculates the cost with static and dynamic dishes
double NormalMenu::calculate_cost(double drink_cost, double salad_cost, int people)
{
    double c = 0;
    
    c = (drink_cost + rings + casserole + salad_cost + iceCream) * people;
    
    return c;
}


