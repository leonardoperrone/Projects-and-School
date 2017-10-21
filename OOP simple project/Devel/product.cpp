#include <vector>
#include <string>
#include <iostream>
#include "product.hpp"

//constructor and destructor
Product::Product(std::string name, int base_val, int ingredient1,
		int ingredient2, int ingredient3, int ratio1, int ratio2,
		int ratio3, int production_time) : Commodity(name, base_val),
		m_prod_time(production_time)
{
	m_ingredients.push_back(ingredient1);
	m_ingredients.push_back(ingredient2);
	m_ingredients.push_back(ingredient3);
	m_ratio.push_back(ratio1);
	m_ratio.push_back(ratio2);
	m_ratio.push_back(ratio3);
}
Product::~Product()
{ }

//accessors
int Product::prod_time(void) const
{
	return m_prod_time;
}

std::vector<Commodity*> Product::recipe(void) const
{
	return m_recipe;
}

std::vector<int> Product::ingredients(void) const
{
	return m_ingredients;
}

std::vector<int> Product::ratio(void) const
{
	return m_ratio;
}

void Product::print_all(void) const
{
	std::cout << m_name << ", " << m_base_val << ", " << m_ingredients[0] << ", " <<
			m_ingredients[1] << ", " << m_ingredients[2] << ", " << m_ratio[0] << ", " <<
			m_ratio[1] << ", " << m_ratio[2] << ", " << m_prod_time << std::endl;
}

void Product::build_print(void) const
{
	std::cout << m_name;
	std::cout.width(30-m_name.size());
	std::cout << "Requires: " << m_ratio[0] << " units of " << m_recipe[0]->name() << ", ";
	if (m_ingredients[1] > 0)
		{
			std::cout << m_ratio[1] << " units of " << m_recipe[1]->name() << ", ";
			if (m_ingredients[2] > 0)
				std::cout << m_ratio[2] << " units of " << m_recipe[2]->name() << ", ";
		}
	std::cout << "and " << m_prod_time << " weeks." << std::endl;
}

//mutator
void Product::fill_components(std::vector<Commodity*> components_list)
{
	m_recipe.push_back(components_list[m_ingredients[0]-1]);
	if (m_ingredients[1] >= 0)
	{
		m_recipe.push_back(components_list[m_ingredients[1]-1]);
		if (m_ingredients[2] >= 0)
			m_recipe.push_back(components_list[m_ingredients[2]-1]);
	}
}
