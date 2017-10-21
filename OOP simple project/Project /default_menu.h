
/* 
 default_menu.h
 03/29/2016
 CS411 Project prototype
 Leonardo Perrone
 F285y428
 
 Description: In this file is created a base class for the menus several parameters, functions, and private members.

 */
#ifndef __Project_CS411__menu__
#define __Project_CS411__menu__

#include <stdio.h> //including libraries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>



class Menu // base class menu with virtual and non-virtual fucntions
{
public:
    
    Menu(const std::string& title = "No menu selected", const std::string& appetizer = "No appetizer", const std::string& entree = "No entree", const std::string& dessert = "No dessert");
    
    virtual ~Menu();
    
    //accessors
    std::string get_title(void);
    std::string get_appetizer(void);
    std::string get_salad(void);
    std::string get_entree(void);
    std::string get_dessert(void);
    std::string get_drink(void);
    double get_drink_cost(void);
    double get_salad_cost(void);
    int get_people(void);
    double get_cost(void);
    double get_tax_cost(void);
    double get_total_cost(void);
    
    //mutators
    void set_title(std::string title);
    void set_appetizer(std::string appetizer);
    void set_salad(std::string salad);
    void set_entree(std::string entree);
    void set_dessert(std::string dessert);
    void set_drink(std::string drink);
    void set_drink_cost(double drink_cost);
    void set_salad_cost(double salad_cost);
    void set_people(int people);
    void set_cost(double cost);
    void set_tax_cost(double tax_cost);
    void set_total_cost(double total_cost);
    
    virtual std::string menu_salad() = 0;
    virtual std::string menu_drink() = 0;
    void print_menu();
    virtual double calculate_cost(double drink_cost, double salad_cost, int people) = 0;
    void print_price();
    int people_num();
    

private:
    
    std::string m_title;
    std::string m_appetizer;
    std::string m_entree;
    std::string m_dessert;
    std::string m_salad;
    std::string m_drink;
    double m_drink_cost;
    double m_salad_cost;
    int m_people;
    double m_cost;
    double m_tax_cost;
    double m_total_cost;
    
};


#endif /* defined(__Project_CS411__menu__) */
