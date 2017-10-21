#include <string>
#include <iostream>
#include <cmath>
#include "commodity.hpp"

//constructor
Commodity::Commodity(std::string name, int base_val) :
m_name(name), m_base_val(base_val)
{
	m_quantity = 0;
}

//destructor
Commodity::~Commodity()
{ }

//accessors
std::string Commodity::name(void) const
{
	return m_name;
}
int Commodity::base_val(void) const
{
	return m_base_val;
}

int Commodity::quantity(void) const
{
	return m_quantity;
}

//print functions
void Commodity::print_all(void) const
{
	std::cout << "Commodity name: " << m_name << ", val:" << m_base_val 
                  << ", quantity: " << m_quantity << std::endl;
}

void Commodity::buy_print(void) const
{
	std::cout << m_name << " ";
	std::cout.width(25 - m_name.length());
	std::cout << "Price: $" << m_base_val << std::endl;
}

void Commodity::sell_print(void) const
{
	std::cout << m_name << " ";
	std::cout.width(25 - m_name.length());
	std::cout << "Price: $" << m_base_val;
	std::cout.width(17 - log10(m_base_val));
	std::cout << "Quantity: " << m_quantity << std::endl;
}

void Commodity::build_print(void) const
{}


//mutators
void Commodity::add_quantity(int num_add)
{
	m_quantity+=num_add;
}

void Commodity::sub_quantity(int num_sub)
{
	if (m_quantity > num_sub)
		m_quantity-=num_sub;
	else m_quantity = 0;
}

void Commodity::fill_components(std::vector<Commodity*> components_list)
{}

// constructor for the struct CommodityDependency
CommodityDependency::CommodityDependency(Commodity* c, int n, int r) :
                                             commodity(c), number(n), ratio(r)
{ }

