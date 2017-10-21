#include <string>
#include <vector>
#include <iostream>
#include "raw_material.hpp"

//constructor
RawMaterial::RawMaterial(std::string name, int base_val, int component1,
		int component2, int component3, int ratio1, int ratio2, int ratio3,
		int mine_price, int mine_production) :
		Commodity(name, base_val), m_mine_price(mine_price), m_mine_production(mine_production)
{
	m_components.push_back(component1);
	m_components.push_back(component2);
	m_components.push_back(component3);
	m_ratio.push_back(ratio1);
	m_ratio.push_back(ratio2);
	m_ratio.push_back(ratio3);
	m_mine_level = 0;
}

//destructor
RawMaterial::~RawMaterial(void)
{ }

//accessors
std::vector<Commodity*> RawMaterial::yeilds(void) const
{
	return m_yeilds;
}

std::vector<int> RawMaterial::components(void) const
{
	return m_components;
}

std::vector<int> RawMaterial::ratio(void) const
{
	return m_ratio;
}

int RawMaterial::mine_level(void) const
{
	return m_mine_level;
}

int RawMaterial::mine_price(void) const
{
	return m_mine_price;
}

int RawMaterial::mine_production(void) const
{
	return m_mine_production;
}

void RawMaterial::print_all(void) const
{
	std::cout << m_name << ", " << m_base_val << ", " << m_components[1] << ", " <<
			m_components[1] << ", " << m_components[2] << ", " << m_ratio[0] <<
			", " << m_ratio[1] << ", " << m_ratio[2] << std::endl;
}

void RawMaterial::build_print(void) const
{
	std::cout << m_name;
	std::cout.width(30-m_name.size());
	std::cout << "Yeilds: " << m_ratio[0] << " units of " << m_yeilds[0]->name();
	if (m_components[1] > 0)
		{
			std::cout << ", " << m_ratio[1] << " units of " << m_yeilds[1]->name();
			if (m_components[2] > 0)
				std::cout << ", " << m_ratio[2] << " units of " << m_yeilds[2]->name();
		}
	std::cout << ", and will take 1 week per 5 units of " << m_name << " refined." << std::endl;
}

//mutators
void RawMaterial::fill_components(std::vector<Commodity*> components_list)
{
	m_yeilds.push_back(components_list[m_components[0]-1]);
	if (m_components[1] >= 0)
	{
		m_yeilds.push_back(components_list[m_components[1]-1]);
		if (m_components[2] >= 0)
			m_yeilds.push_back(components_list[m_components[2]-1]);
	}
}

void RawMaterial::upgrade_mine(void)
{
	m_mine_level++;
}



