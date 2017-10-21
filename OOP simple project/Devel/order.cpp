#include "order.hpp"

//constructor
Order::Order(int time, int quantity, Product *product) : m_timer(time), m_quantity(quantity), m_product(product)
{}

//destructor
Order::~Order()
{}

//accessors
int Order::timer(void) const
{
	return m_timer;
}

int Order::quantity(void) const
{
	return m_quantity;
}

Product* Order::product(void) const
{
	return m_product;
}

//mutators

int Order::pass_time(int num_of_weeks)
{
	if (m_timer > num_of_weeks)
	{
		m_timer-=num_of_weeks;
		return 1;
	}
	else
	{
		m_timer = 0;
		m_product->add_quantity(m_quantity);
		return 0;
	}
}
