
/*
 mexica_menu.cpp
 03/29/2016
 CS411 Project prototype
 Leonardo Perrone
 F285y428
  Description: in this file is implemented the derived class MexicanMenu which is menu with common Mexican dishes. A few functions are overloaded on the ones of the base class.
 */
//including header files
#include "default_menu.h"
#include "mexican_menu.h"
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
MexicanMenu::MexicanMenu(const std::string& title, const std::string& appetizer, const std::string& entree, const std::string& dessert) : Menu(title, appetizer, entree, dessert)
{
    
}

//destructor
MexicanMenu::~MexicanMenu()
{
    
}


//salad menu that returns a string
std::string MexicanMenu::menu_salad()
{
    int choice;
    std::string salad;
    std::cout << "Select Salad type:" << std::endl << "1. Guadalajara Salad" << std::endl << "2. Agave Salad " << std::endl << std::endl << "Enter selection: " ;
    std::cin >> choice;
    std::cout << std::endl;
    
    switch (choice)
    {
        case 1:
            salad = "Guadalajara Salad";
            set_salad_cost(guada);
            break;
        case 2:
            salad = "Agave Salad";
            set_salad_cost(agave);
            break;
        default:
            break;
    }
    
    return salad;
}

//drink menu that returns drink
std::string MexicanMenu::menu_drink()
{
    int choice;
    std::string drink;
    std::cout << "Select drink type:" << std::endl << "1. Horchata" << std::endl << "2. Bonafont Water" << std::endl << "3. Tequila Drink" << std::endl << std::endl << "Enter selection: ";
    std::cin >> choice;
    std::cout << std::endl;
    
    switch (choice)
    {
        case 1:
            drink = "Horchata";
            set_drink_cost(horchata);

            break;
        case 2:
            drink = "Bonafont Water";
            set_drink_cost(bonafont);

            break;
        case 3:
            drink = "Tequila Drink";
            set_drink_cost(tequila);

            break;
        default:
            break;
    }
    
    return drink;
    
    
}


//calculates the cost with static and dynamic dishes
double MexicanMenu::calculate_cost(double drink_cost, double salad_cost, int people)
{
    double cost = 0;
    
    cost = (drink_cost + chips + tacos + salad_cost + tresLeches) * people;
    
    return cost;
}

