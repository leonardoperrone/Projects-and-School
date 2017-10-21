
/*
 default_menu.cpp
 03/29/2016
 CS411 Project prototype
 Leonardo Perrone
 F285y428
 
 Description: this file includes the implementation of the base class of a menu
 */

#include <stdio.h> //including libraries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "default_menu.h" //including header files
#include "global.h"

//constractor
Menu::Menu(const std::string& title, const std::string& appetizer, const std::string& entree, const std::string& dessert) : m_title(title), m_appetizer(appetizer), m_entree(entree), m_dessert(dessert)
{
    m_drink_cost = 0;
    m_people = 1;
    m_total_cost = 0;
    m_salad_cost = 0;
    m_tax_cost = 0;
    m_cost = 0;

    
};
//destructor
Menu::~Menu()
{

}

//accessors
std::string Menu::get_title()
{
    return m_title;
}

std::string Menu::get_appetizer(void)
{
    return m_appetizer;
}

std::string Menu::get_salad(void)
{
    return m_salad;
}

std::string Menu::get_entree(void)
{
    return m_entree;
}

std::string Menu::get_dessert(void)
{
    return m_dessert;
}

std::string Menu::get_drink(void)
{
    return m_drink;
}

double Menu::get_drink_cost(void)
{
    return m_drink_cost;
}

double Menu::get_salad_cost(void)
{
    return m_salad_cost;
}

int Menu::get_people(void)
{
    return m_people;
}

double Menu::get_cost(void)
{
    return m_cost;
}

double Menu::get_tax_cost(void)
{
    return m_tax_cost;
}

double Menu::get_total_cost(void)
{
    return m_total_cost;
}

//mutators
void Menu::set_title(std::string title)
{
    m_title = title;
}


void Menu::set_appetizer(std::string appetizer)
{
    m_appetizer = appetizer;
}

void Menu::set_salad(std::string salad)
{
    m_salad = salad;
}

void Menu::set_entree(std::string entree)
{
    m_entree = entree;
}

void Menu::set_dessert(std::string dessert)
{
    m_dessert = dessert;
}

void Menu::set_drink(std::string drink)
{
    m_drink = drink;
}

void Menu::set_drink_cost(double drink_cost)
{
    m_drink_cost = drink_cost;
}

void Menu::set_salad_cost(double salad_cost)
{
    m_salad_cost = salad_cost;
}

void Menu::set_people(int people)
{
    m_people = people;
}

void Menu::set_cost(double cost)
{
    m_cost = cost;
}

//calculates the tax to be paid out of the total
void Menu::set_tax_cost(double tax_cost)
{
    tax_cost = get_cost()*taxRate;
    m_tax_cost = tax_cost;
}

//calculates the total cost including taxes
void Menu::set_total_cost(double total_cost)
{
    total_cost = get_cost() + get_tax_cost();
    m_total_cost = total_cost;
}

//return the number of people ordering
int Menu::people_num()
{
    int p = 0;
    
    std::cout << std::endl << std::endl << "The above menu is your selection for tonight. I hope you will enjoy it!" << std::endl <<"How many people will enjoy this wonderful meal? Please enter number of orders: ";
    std::cin >> p;
    std::cout << std::endl << std::endl;
    
    return p;
    
}

//prints out the total price and tax price
void Menu::print_price()
{
    set_cost(calculate_cost(get_drink_cost(), get_salad_cost(), get_people()));
    set_tax_cost(get_tax_cost());
    set_total_cost(get_total_cost());
    std::cout.precision(2);
    std::cout << "Your total for this order will be: $" << std::fixed << get_cost() << " + $"<< std::fixed << get_tax_cost() << "tax = $" << get_total_cost() << std::endl << std::endl;
}

//prints out the menu
void Menu::print_menu()
{
    
 set_salad(menu_salad()); //sets the salad with the return string from menu_salad
 set_drink(menu_drink());
 
 std::cout << "This is the customized menu you selected:" << std::endl << std::endl << get_title() << ":" << std::endl << std::endl << "\t-" << "Drink: " << get_drink() << std::endl << "\t-"  << get_appetizer() << std::endl << "\t-"<< get_entree()<< std::endl << "\t-" << get_salad() << std::endl << "\t-" << get_dessert() << std::endl << std::endl; //error with get drink and get salad
 
 set_people(people_num()); //inputs the number of people
}






























