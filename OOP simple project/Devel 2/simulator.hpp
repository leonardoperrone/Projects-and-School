#ifndef SIMULATOR_HPP_
#define SIMULATOR_HPP_

#include <string>
#include <vector>
#include "commodity.hpp"
#include "raw_material.hpp"
#include "product.hpp"
#include "refine_order.hpp"
#include "build_order.hpp"

void clearscreen();

void main_menu(std::string &gamestate);

void game_start(std::string &gamestate);

void market_menu(std::string &gamestate);

void buy_menu();

void sell_menu();

void mines_menu(std::string &gamestate);

void upgrade_menu();

void factory_menu(std::string &gamestate);

std::string make_order(int num_of_prod, unsigned prod_num, Product* prod);

void build_menu();

void show_orders();

void refine_menu();

void game_wait(int num_of_weeks);

void load_goods();

int main(void);

#endif /* SIMULATOR_HPP_ */
