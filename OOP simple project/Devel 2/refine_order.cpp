#include "refine_order.hpp"

//constructor
RefineOrder::RefineOrder(int time, int quantity, RawMaterial *material) : Order(time, quantity), m_material(material)
{
	set_timer((quantity < 5) ? 1 : quantity/5);
}

//destructor
RefineOrder::~RefineOrder()
{}

//accessors
RawMaterial* RefineOrder::material(void) const
{
	return m_material;
}

//mutators
int RefineOrder::pass_time(int num_of_weeks)
{
	if (timer() > num_of_weeks)	//subtracts from timer
	{
		set_timer(timer() - num_of_weeks);
		return 1;
	}
	else      //adds the proper ratio of quantity to the commodities in the material's yield vector
	{
		set_timer(0);
		m_material->get_yield(0)->add_quantity(quantity() * m_material->get_ratio(0));
		if (m_material->get_component(1)>0)
			m_material->get_yield(1)->add_quantity(quantity() * m_material->get_ratio(1));
		if (m_material->get_component(2)>0)
			m_material->get_yield(2)->add_quantity(quantity() * m_material->get_ratio(2));
		return 0;
	}
}



