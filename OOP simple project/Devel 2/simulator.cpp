// Description: Factory simulator game that allows players to manage a "factory"
// by buying and upgrading mines and factories as well as buying and selling 
// commodities on the market to make a profit with a goal of reaching the 
// highest amount of money in the shortest amount of time.

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "simulator.hpp"
using namespace std;

#define MAXCOMS 8	//number of commodities
#define MAXMATS 7	//number of raw materials
#define MAXPROD 12	//number of products

string confirmation = "";
vector<Commodity*> goods;	//List of all commodities, raw materials, and products
vector<BuildOrder*> product_orders;	//List of product orders. Maximum of 3 orders
vector<RefineOrder*> refine_orders;	//List of refine orders. Maximum of 3 orders
int week_num = 1;		//The number of weeks that have passed in game
int money = 10000;		//The amount of money that the player has, starts at $10k


void clearscreen() 	//method for clearing the terminal screen
{
	cout << string( 100, '\n' );
	cout << "Money: $" << money << "\t\tWeek " << week_num << endl;
}

void main_menu(string &gamestate)	//Start screen
{
	string main_command = "";
	bool valid = false;

	while (!valid)
	{
		cout << "Enter a command (Options: start, quit):";
		cin >> main_command;
		cin.ignore();
		if (main_command == "start")
		{
			gamestate = "start";
			valid = true;
		}
		else if (main_command == "quit")
		{
			valid = true;
			gamestate = "quit";
		}
		else cout << "Invalid Command" << endl;
	}
}

void game_start(string &gamestate)	//First game menu, gives access to market, mines, factory, and allows the user to pass game time
{
	string command = "";
	int time = 0;

	while (command != "quit" && gamestate != "quit")   //loop to display prompt and transfer to the proper menu when a choice is entered
	{
		clearscreen();
		cout << "Where would you like to go? (Options: market, mines, factory, wait, quit): ";
		cin >> command;
		cin.ignore();
		if (command == "market")
		{
			market_menu(gamestate);
		}
		else if (command == "mines")
		{
			mines_menu(gamestate);
		}
		else if (command == "factory")
		{
			factory_menu(gamestate);
		}
		else if (command == "wait")
		{
			cout << "How long would you like to wait?: ";
			while(!(cin >> time))
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "How long would you like to wait?: ";
			}
			cin.ignore();
			game_wait(time);

		}
		else if (command == "quit")
		{
			cout << "Are you sure you want to exit? (y/n): ";
			cin >> confirmation;
			cin.ignore();
			while (confirmation != "y" && confirmation != "n")
			{
				cout << "Invalid input. Please enter y or n: ";
				cin >> confirmation;
				cin.ignore();
			}
			if (confirmation == "y")
			{
				gamestate = "quit";
			}
			else
			{
				command = "";
			}
		}
		else cout << "Invalid Command" << endl;
	}
}

void market_menu(string &gamestate)	//Market menu. Allows player to buy and sell goods.
{
	string command = "";

	while (command != "quit" && command != "back")	//loop to prompt and transfer to proper menu when choice is inputted
	{
		clearscreen();
		cout << "At the market you can buy materials for use in the factory or "
				"sell products that your mines and factory produce." << endl;
		cout << "What would you like to do? (Options: buy, sell, back, quit): ";
		cin >> command;
		cin.ignore();
		if (command == "buy") buy_menu();

		else if (command == "sell") sell_menu();

	//	else if (command == "back") {}

		else if (command == "quit")
		{
			cout << "Are you sure you want to exit the game? (y/n): ";
			cin >> confirmation;
			cin.ignore();
			while (confirmation != "y" && confirmation != "n")
			{
				cout << "Invalid input. Please enter y or n: ";
				cin >> confirmation;
				cin.ignore();
			}
			if (confirmation == "y")
			{
				gamestate = "quit";
			}
			else
			{
				command = "";
			}
		}
		else cout << "Invalid Command" << endl;
	}
}

void buy_menu()		//Buy menu. Shows the available goods and prices and allows player to buy quantities.
{
	unsigned choice = 1;
	int choice2 = 0;
	string message = "";
	while (choice != 0)
	{
		clearscreen();
		for (unsigned i = 0; i < goods.size(); i++) //loop to display goods and prices
		{
			cout << i+1 << ". ";
			goods[i]->buy_print();
		}

		cout << "Choose an item to buy or type 0 to go back." << endl;	//prompt
		cout << message;

		cout << "Item Number: ";
		while(!(cin >> choice))
		{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Item Number: ";
		}
		cin.ignore();

		if (choice != 0)
		{
			for (unsigned i = 0; i < goods.size(); i++) //loop to find the chosen good and prompts for quantity
			{
				if (choice == i+1)
				{
					cout << "How many units of " << goods[i]->name() << " would you like to buy?: ";
					cin >> choice2;
					cin.ignore();
					if (choice2 > 0)
					{
						cout << "That will cost $" << choice2 * goods[i]->base_val() << ". Are you sure?(y/n): ";
						cin >> confirmation;
						cin.ignore();
						while (confirmation != "y" && confirmation != "n") {
							cout << "Invalid input. Please enter y or n: ";
							cin >> confirmation;
							cin.ignore();
						}
						if (confirmation == "y")
						{
							if (money >= choice2 * goods[i]->base_val())
							{
								money-= choice2 * goods[i]->base_val();
								goods[i]->add_quantity(choice2);
								message= goods[i]->name() + " has been bought.\n";
							} else
								message =  "Not enough money.\n";
						}

					}
				}

			}
		}
	}
}

void sell_menu()	//Sell menu. Shows the available goods and prices and allows player to sell quantities.
{
	unsigned choice = 1;
	int choice2 = 0;
	string message = "";
	while (choice != 0)
	{
		clearscreen();
		for (unsigned i = 0; i < goods.size(); i++)	//prints the goods the player has with their market prices
		{
			if (goods[i]->quantity() > 0)
			{
				cout << i+1 << ". ";
				goods[i]->sell_print();
			}
		}

		cout << "Choose an item to sell or type 0 to go back." << endl; //prompt
		cout << message;
		cout << "Item Number: ";
		while(!(cin >> choice))
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Item Number: ";
		}
		cin.ignore();

		if (choice != 0)
		{
			for (unsigned i = 0; i < goods.size(); i++)		//loop to find the chosen good with prompts for quantity
			{
				if (choice == i+1 && goods[i]->quantity() > 0)
				{
					cout << "How many units of " << goods[i]->name() << " would you like to sell?: ";
					cin >> choice2;
					cin.ignore();
					while (choice2 > goods[i]->quantity())
					{
						cout << "Not enough goods. How many units of " << goods[i]->name() << " would you like to sell?: ";
						cin >> choice2;
						cin.ignore();
					}
					if (choice2 > 0)
					{
						cout << "You will get $" << choice2 * goods[i]->base_val() << ". Are you sure?(y/n): ";
						cin >> confirmation;
						cin.ignore();
						while (confirmation != "y" && confirmation != "n") {
							cout << "Invalid input. Please enter y or n: ";
							cin >> confirmation;
							cin.ignore();
						}
						if (confirmation == "y")
						{
							money+= choice2 * goods[i]->base_val();
							goods[i]->sub_quantity(choice2);
							message = choice2 + " units of " + goods[i]->name() + " have been sold.\n";
						}
					}
				}
			}
		}
	}
}

void mines_menu(string &gamestate)	//Mines menu. Shows all the mines and the level of the mine, allows player to upgrade mines
{
	string command = "";
	RawMaterial *temp_raw;

	while (command != "quit" && command != "back") //displays prompt and transfers to proper menu when a choice is inputted
	{
		clearscreen();
		for (unsigned i = MAXCOMS; i < MAXCOMS+MAXMATS; i++)
		{
			temp_raw = dynamic_cast<RawMaterial*>(goods[i]);
			cout << temp_raw->name();
			cout.width(20-temp_raw->name().size());
			cout << "Level: " << temp_raw->mine_level();
			cout.width(20);
			cout << "Production Rate: " << temp_raw->mine_production() * temp_raw->mine_level()<< endl;
		}
		cout << "The mines extract raw materials that can be sold or refined for use at the factory."
				" \nYou can upgrade the mines to extract ore at an accelerated rate." << endl;
		cout << "What would you like to do? (Options: upgrade, back, quit): ";
		cin >> command;
		cin.ignore();
		if (command == "upgrade") upgrade_menu();
	//	else if (command == "back") {}
		else if (command == "quit")
		{
			cout << "Are you sure you want to exit the game? (y/n): ";
			cin >> confirmation;
			cin.ignore();
			while (confirmation != "y" && confirmation != "n")
			{
				cout << "Invalid input. Please enter y or n: ";
				cin >> confirmation;
				cin.ignore();
			}
			if (confirmation == "y")
				gamestate = "quit";
			else command = "";
		}
		else cout << "Invalid Command" << endl;
	}
}

void upgrade_menu()	//Upgrade menu. Allows the player to upgrade their mines
{
	unsigned choice = 1;
	string message = "";
	RawMaterial *temp_raw;
	while (choice != 0)
	{
		clearscreen();
		for (unsigned i = MAXCOMS; i < MAXCOMS+MAXMATS; i++)
		{
			temp_raw = dynamic_cast<RawMaterial*>(goods[i]);
			cout << i+1-MAXCOMS << ". " << temp_raw->name();
			cout.width(20-temp_raw->name().size());
			cout << "Level: " << temp_raw->mine_level();
			cout. width(15);
			cout << "Price: " << temp_raw->mine_price() * (temp_raw->mine_level()+1) << endl;
		}

		cout << "Choose a mine to upgrade or type 0 to go back." << endl;
		cout << message;
		message = "";
		cout << "Mine Number: ";
		while(!(cin >> choice))
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Mine Number: ";
		}
		cin.ignore();
		if (choice != 0)
		{
			for (unsigned i = MAXCOMS; i < goods.size()-MAXPROD; i++)
			{
				if (choice == i+1-MAXCOMS)
				{
					temp_raw = dynamic_cast<RawMaterial*>(goods[i]);
					cout << "Upgrading the " << temp_raw->name() << " mine will cost $" << temp_raw->mine_price() * (temp_raw->mine_level()+1) << endl;
					cout << "Are you sure?(y/n): ";
					cin >> confirmation;
					cin.ignore();
					while (confirmation != "y" && confirmation != "n") {
						cout << "Invalid input. Please enter y or n: ";
						cin >> confirmation;
						cin.ignore();
					}
					if (confirmation == "y")
					{
						if (money >= temp_raw->mine_price() * (temp_raw->mine_level()+1))
						{
							money-= temp_raw->mine_price() * (temp_raw->mine_level()+1);
							temp_raw->upgrade_mine();
							message = "Successfully upgraded " + temp_raw->name() + " mine.\n";
						} else
							message = "Not enough money.\n";
					}
				}
			}
		}
	}
}

void factory_menu(string &gamestate)//Factory menu. Allows the player to build products, refine raw materials, and look at what build and refine orders they have.
{
	string command = "";
	bool clear = true;
	while (command != "quit" && command != "back")
	{
		if (clear)
			clearscreen();
		else clear = true;

		cout << "At the factory you can build products, refine raw materials, and view your current build orders." << endl;
		cout << "What would you like to do? (Options: build, view(orders), refine, back, quit): ";
		cin >> command;
		cin.ignore();

		if (command == "build") build_menu();
		else if (command == "view")
		{
			clearscreen();
			show_orders();
			clear = false;
		}
		else if (command == "refine") refine_menu();
	//	else if (command == "back") {}
		else if (command == "quit")
		{
			cout << "Are you sure you want to exit the game? (y/n): ";
			cin >> confirmation;
			cin.ignore();
			while (confirmation != "y" && confirmation != "n")
			{
				cout << "Invalid input. Please enter y or n: ";
				cin >> confirmation;
				cin.ignore();
			}
			if (confirmation == "y")
				gamestate = "quit";
			else command = "";
		}
		else cout << "Invalid Command" << endl;
	}
}

string make_order(int num_of_prod, unsigned prod_num, Product* prod) //Function to make a build order based on player input. This was refactored out of the build menu so it got a bit compressed
{
	cout << "This will cost " << num_of_prod * prod->get_ratio(0) << " "		//confirmation prompt
			<< prod->get_recipe(0)->name() << ", ";
	if (prod->get_ingredient(1) != -1) {
		cout << num_of_prod * prod->get_ratio(1) << " "
				<< prod->get_recipe(1)->name() << ", ";
		if (prod->get_ingredient(2) != -1)
			cout << num_of_prod * prod->get_ratio(2) << " "
					<< prod->get_recipe(2)->name() << ", ";
	}
	cout << "and " << num_of_prod * prod->prod_time() << " weeks." << endl;
	cout << "Are you sure? (y/n): ";
	cin >> confirmation;
	cin.ignore();
	while (confirmation != "y" && confirmation != "n") {
		cout << "Invalid input. Please enter y or n: ";
		cin >> confirmation;
		cin.ignore();
	}
	if (confirmation == "y") {    //Checks if the player has enough ingredients to make the products and the makes the order
		if (prod->get_recipe(0)->quantity() >= num_of_prod * prod->get_ratio(0))
		{
			if ((prod->get_ingredient(1) > 0 && prod->get_recipe(1)->quantity()
							>= num_of_prod * prod->get_ratio(1)) || prod->get_ingredient(1) == -1)
			{
				if ((prod->get_ingredient(2) > 0 && prod->get_recipe(2)->quantity()
						>= num_of_prod * prod->get_ratio(2)) || prod->get_ingredient(2) == -1)
				{
					if (product_orders.size() < 3) {
						BuildOrder* temp_order = new BuildOrder(
								num_of_prod * prod->prod_time(), num_of_prod,
								prod);
						product_orders.push_back(temp_order);
						prod->get_recipe(0)->sub_quantity(
								num_of_prod * prod->get_ratio(0));

						if (prod->get_ingredient(1) > 0)
						{
							prod->get_recipe(1)->sub_quantity(
									num_of_prod * prod->get_ratio(1));
							if (prod->get_ingredient(2) > 0)
								prod->get_recipe(2)->sub_quantity(
										num_of_prod * prod->get_ratio(2));
						}
					} else
						return "Too many orders.\n";
				} else
					return "Not enough " + prod->get_recipe(2)->name() + ".\n";
			} else
				return "Not enough " + prod->get_recipe(1)->name() + ".\n";
		} else
			return "Not enough " + prod->get_recipe(0)->name() + ".\n";
	}
	return "";
}

void build_menu(void)	//Build menu. Shows the available products to make, and allows player to make an order of those products
{
	unsigned choice = 1;
	int choice2 = 0;
	string err_string = "";
	Product *temp_prod;

	while (choice != 0)
	{
		clearscreen();
		for (unsigned i = MAXCOMS+MAXMATS; i < MAXCOMS+MAXMATS+MAXPROD; i++)	//prints products
		{
			cout << i+1-MAXCOMS-MAXMATS << ". ";
			goods[i]->build_print();
		}

		cout << "\nChoose a product from the list above or type 0 to go back" << endl; //prompts for a product
		cout << err_string;
		cout << "Product Number: ";
		while(!(cin >> choice))
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Product Number: ";
		}
		cin.ignore();
		if (choice != 0)
		{
			for (unsigned i = 0; i < MAXPROD; i++) //finds the chosen product, and prompts for quantity and makes the order
			{
				if (choice == i+1)
				{
					temp_prod = dynamic_cast<Product*>(goods[i+MAXCOMS+MAXMATS]);
					temp_prod->fill_components(goods);
					cout << "How many " << goods[i+MAXCOMS+MAXMATS]->name() << " would you like to make?: ";
					cin >> choice2;
					if (choice2 > 0 && choice2 < 1000)
					{
						err_string = make_order(choice2, i+MAXCOMS+MAXMATS, temp_prod);
					}
				}
			}
		}
	}
}

void show_orders()	//Function to prints all build and refine orders
{
	if (product_orders.size() > 0 || refine_orders.size() > 0)
	{
		cout << "Current orders:" << endl;
		for (unsigned i =0; i < product_orders.size(); i++)
		{
			cout << "Producing: " << product_orders[i]->product()->name() << ". Quantity: " <<
				product_orders[i]->quantity() << ". Time left: " << product_orders[i]->timer() << endl;
		}
		for (unsigned i = 0; i < refine_orders.size(); i++)
		{
			cout << "Refining: " << refine_orders[i]->material()->name() << ". Quantity: " <<
				refine_orders[i]->quantity() << ". Time left: " << refine_orders[i]->timer() << endl;
		}
	} else
		cout << "No current orders." << endl;
}

void refine_menu()	//RefineOrder menu. Shows the available materials to refine and allows the player to make refine orders
{
	unsigned choice = 1;
	int choice2 = 0;
	string message = "";
	RawMaterial *temp_mat;

	while (choice != 0)
	{
		clearscreen();
		for (unsigned i = MAXCOMS; i < MAXCOMS+MAXMATS; i++)
		{
			if (goods[i]->quantity() > 0)
			{
				cout << i+1-MAXCOMS << ". ";
				goods[i]->build_print();
			}
		}

		cout << "\nChoose a raw material from the list above or type 0 to go back" << endl; //prompts for a material
		cout << message;
		cout << "Material Number: ";
		while(!(cin >> choice))
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Material Number: ";
		}
		cin.ignore();

		if (choice != 0) //finds the chosen material, prompts for a quantity, then creates the refine order
		{
			for (unsigned i = 0; i < MAXMATS; i++)
			{
				if (choice == i+1)
				{
					temp_mat = dynamic_cast<RawMaterial*>(goods[i+MAXCOMS]); //casts the commodity pointer to a raw material pointer
					temp_mat->fill_components(goods);
					cout << "How many " << temp_mat->name() << " would you like to refine?: ";
					cin >> choice2;
					while (choice2 > temp_mat->quantity())
					{
						cout << "Not enough goods. How many units of " << goods[i]->name() << " would you like to refine?: ";
						cin >> choice2;
						cin.ignore();
					}
					if (choice2 > 0 && choice2 < 1000)
					{
						RefineOrder *temp_refine = new RefineOrder(choice2, choice2, temp_mat);
						refine_orders.push_back(temp_refine);
						temp_mat->sub_quantity(choice2);
						message = "RefineOrder order created.\n";
					}
				}
			}
		}
	}
}

void game_wait(int num_of_weeks)	//Passes time in game to allow build and refine order progression
{
	RawMaterial *temp_raw;
	week_num+= num_of_weeks;
	for (unsigned i = 0; i < product_orders.size(); i++)
	{
		if (product_orders[i]->pass_time(num_of_weeks))		//If the order is complete, the order is removed from the order list
		{
			delete product_orders[i];
			product_orders.erase(product_orders.begin() + i);
		}
	}
	for (unsigned i = 0; i < refine_orders.size(); i++)
		{
			if (refine_orders[i]->pass_time(num_of_weeks))	//If the order is complete, the order is removed from the order list
			{
				delete refine_orders[i];
				refine_orders.erase(refine_orders.begin() + i);
			}
		}
	for (unsigned i = MAXCOMS; i < MAXCOMS+MAXMATS; i++)
	{
		temp_raw = dynamic_cast<RawMaterial*>(goods[i]);
		temp_raw->add_quantity(temp_raw->mine_level() * temp_raw->mine_production() * num_of_weeks);
	}
}

void load_goods() 	//Loads the data for all the commodities, raw materials, and products from the files "goods.txt"
{
	ifstream goods_file;
	std::string temp_name = "", buffer = "";
	int temp_base_val = 0;
	int temp_component_1 = 0, temp_component_2 = 0, temp_component_3 = 0;
	int temp_ratio_1 = 0, temp_ratio_2 = 0, temp_ratio_3 = 0;
	int temp_mine_price, temp_mine_production;
	int temp_prod_time = 0;

	goods_file.open("goods.txt");

	if (goods_file.is_open())
	{
		for (unsigned i = 0; i < MAXCOMS; i++) {		//Read Commodities into goods vector
			getline(goods_file, temp_name);
			goods_file >> temp_base_val;
			getline(goods_file, buffer);
			Commodity* temp_commodity = new Commodity(temp_name, temp_base_val);
//cout << "DEBUG";
//temp_commodity->print_all();
			goods.push_back(temp_commodity);
		}
		for (unsigned i = 0; i < MAXMATS; i++) {		//Read raw materials into goods vector
			getline(goods_file, temp_name);
			goods_file >> temp_base_val;
			getline(goods_file, buffer);
			goods_file >> temp_component_1;
			getline(goods_file, buffer);
			goods_file >> temp_component_2;
			getline(goods_file, buffer);
			goods_file >> temp_component_3;
			getline(goods_file, buffer);
			goods_file >> temp_ratio_1;
			getline(goods_file, buffer);
			goods_file >> temp_ratio_2;
			getline(goods_file, buffer);
			goods_file >> temp_ratio_3;
			getline(goods_file, buffer);
			goods_file >> temp_mine_price;
			getline(goods_file, buffer);
			goods_file >> temp_mine_production;
			getline(goods_file, buffer);
			RawMaterial* temp_raw_material = new RawMaterial(temp_name,
					temp_base_val, temp_component_1, temp_component_2,
					temp_component_3, temp_ratio_1, temp_ratio_2, temp_ratio_3,
					temp_mine_price, temp_mine_production);
//cout << "DEBUG";
//temp_raw_material->print_all();
			goods.push_back(temp_raw_material);
		}
		for (unsigned i = 0; i < MAXPROD; i++) {		//Read products into goods vector
			getline(goods_file, temp_name);
			goods_file >> temp_base_val;
			getline(goods_file, buffer);
			goods_file >> temp_component_1;
			getline(goods_file, buffer);
			goods_file >> temp_component_2;
			getline(goods_file, buffer);
			goods_file >> temp_component_3;
			getline(goods_file, buffer);
			goods_file >> temp_ratio_1;
			getline(goods_file, buffer);
			goods_file >> temp_ratio_2;
			getline(goods_file, buffer);
			goods_file >> temp_ratio_3;
			getline(goods_file, buffer);
			goods_file >> temp_prod_time;
			getline(goods_file, buffer);

			Product* temp_product = new Product(temp_name, temp_base_val,
					temp_component_1, temp_component_2, temp_component_3,
					temp_ratio_1, temp_ratio_2, temp_ratio_3, temp_prod_time);
//cout << "DEBUG";
//temp_product->print_all();
			goods.push_back(temp_product);
		}
		goods_file.close();
	}
	for (unsigned i = MAXCOMS; i < MAXCOMS+MAXMATS+MAXPROD; i++)
	{
		goods[i]->fill_components(goods);
	}
}

int main(void)
{
	string state = "main";
	string temp_string = "";

	load_goods();

	cout << "Welcome to Factory Simulator!\n"
             << "Try to make the biggest profit in as little time as possible.\n" 
             << "\nTo select a menu option, enter the option (with words in parentheses left out).\n" << endl;
	while (state != "quit")
	{
		if (state == "main") main_menu(state);
		if (state == "start") game_start(state);
	}

	//dynamic memory deallocation
	for (unsigned i = 0; i < goods.size(); i++) delete goods[i];
	for (unsigned i = 0; i < product_orders.size(); i++) delete product_orders[i];
	for (unsigned i = 0; i < refine_orders.size(); i++) delete refine_orders[i];

	return 0;
}

