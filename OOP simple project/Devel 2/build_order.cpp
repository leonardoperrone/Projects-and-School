#include "build_order.hpp"

//constructor
BuildOrder::BuildOrder(int time, int quantity, Product *product) : Order(time, quantity), m_product(product)
{}

//destructor
BuildOrder::~BuildOrder()
{}

//accessors

Product* BuildOrder::product(void) const
{
	return m_product;
}

//mutators

int BuildOrder::pass_time(int num_of_weeks)
{
	if (timer() > num_of_weeks)
	{
		set_timer(timer() - num_of_weeks);
		return 1;
	}
	else
	{
		set_timer(0);
		m_product->add_quantity(quantity());
		return 0;
	}
}
