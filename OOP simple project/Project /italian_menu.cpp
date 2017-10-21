
/*
 italian_menu.cpp
 03/29/2016
 CS411 Project prototype
 Leonardo Perrone
 F285y428
  Description: in this file is implemented the derived class ItalianMenu which is a menu with some italian dishes and a spectacular option for a 2008 Barolo red wine. A few functions are overloaded on the ones of the base class.
 
 */

//including header files
#include "italian_menu.h"
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
ItalianMenu::ItalianMenu(const std::string& title, const std::string& appetizer, const std::string& entree, const std::string& dessert) : Menu(title, appetizer, entree, dessert)
{
    
}

//destructor
ItalianMenu::~ItalianMenu()
{
    
}

//salad menu that returns string
std::string ItalianMenu::menu_salad()
{
    int choice;
    std::string salad;
    std::cout << "Select salad type:" << std::endl << "1. Semplice Salad" << std::endl << "2. Ligure Salad" << std::endl << "3. Parma Salad" << std::endl << std::endl << "Enter selection: " ;
    std::cin >> choice;
    std::cout << std::endl;
    
    switch (choice)
    {
        case 1:
            salad = "Semplice Salad";
            set_salad_cost(semplice);

            break;
        case 2:
            salad = "Ligure Salad";
            set_salad_cost(ligure);

            break;
        case 3:
            salad = "Parma Salad";
            set_salad_cost(parma);

            break;
        default:
            break;
    }
    
    return salad;
}

//drink menu that returns drink
std::string ItalianMenu::menu_drink()
{
    int choice;
    std::string drink;
    std::cout << "Select drink type:" << std::endl << "1. San Pellegrino Water" << std::endl << "2. Coca Cola" << std::endl << "3. 2008 Barolo Wine" << std::endl << std::endl << "Enter selection: ";
    std::cin >> choice;
    std::cout << std::endl;
    
    switch (choice)
    {
        case 1:
            drink = "San  Pellegring Water";
            set_drink_cost(sanpel);

            break;
        case 2:
            drink = "Coca Cola";
            set_drink_cost(cocacola);

            break;
        case 3:
            drink = "2008 Barolo Wine";
            set_drink_cost(barolo);

            break;
        default:
            break;
    }
    
    return drink;
    
    
}


//calculates the cost with static and dynamic dishes
double ItalianMenu::calculate_cost(double drink_cost, double salad_cost, int people)
{
    double cost = 0;
    
    cost = (drink_cost + bruschetta + carbonara + salad_cost + tiramisu) * people;
    
    return cost;
}

