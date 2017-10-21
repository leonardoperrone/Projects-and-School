/*
 main.cpp
 03/29/2016
 CS411 Project prototype
 Leonardo Perrone
 F285y428

 Description: This program is a online dining service. The user will be prompt with several options to choose from and how many people he or she is ordering for so that the program can give them an accurate price. 
 
 */

#include <stdio.h> //including libraries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "default_menu.h" //including header files
#include "normal_menu.h"
#include "italian_menu.h"
#include "mexican_menu.h"
#include "global.h"
 


int main(void)
{
    int code;
    int option = 1;
  
    
    while (option == 1) {
    
    std::cout << "Welcome to QuikMenu. You will be asked to choose the type of menu you would like to enjoy tonight. Everything will be delivered to your door. Please select the type of menu:" << std::endl << std::endl << "1. Basic Menu (Your spouse won't be impressed...)" << std::endl << "2. Italian Menu (THIS is what you want, trust us)." << std::endl << "3. Mexican Menu (Delicious...but good luck tomorrow)" << std::endl << std::endl;
    std::cout << "Menu code: ";
    std::cin >> code;
    std::cout << std::endl;
    
    switch (code) {
        {case 1:
            NormalMenu *menu1;
            menu1 = new NormalMenu();
            menu1->print_menu();
            menu1->print_price();
            delete menu1;
            break;}
        {case 2:
          
            ItalianMenu *menu2;
            menu2 = new ItalianMenu();
            menu2->print_menu();
            menu2->print_price();
            delete menu2;
            break;}
        {case 3:
            MexicanMenu *menu3;
            menu3 = new MexicanMenu();
            menu3->print_menu();
            menu3->print_price();
            delete menu3;
            break;}
        default:
            std::cout << "Wrong Selection." << std::endl;
            break;
    }
    
    std::cout << std::endl << "If you would like to start over in case you changed your mind enter '1' or enter '2' or any other number to send in the order." << std::endl << std::endl << "Enter option here: ";
    std::cin >> option;
    }
   
    std::cout << std::endl;
    std::cout << "Thanks for eating with us!" << std::endl;
    
    
}
