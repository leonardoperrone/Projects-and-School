#include "refine.hpp"

//constructor
Refine::Refine(int time, int quantity, RawMaterial *material) :  m_quantity(quantity), m_material(material)
{
	(quantity < 5) ? m_timer = 1 : m_timer = quantity/5;
}

//destructor
Refine::~Refine()
{}

//accessors
int Refine::timer(void) const
{
	return m_timer;
}

int Refine::quantity(void) const
{
	return m_quantity;
}

RawMaterial* Refine::material(void) const
{
	return m_material;
}

//mutators

int Refine::pass_time(int num_of_weeks)
{
	if (m_timer > num_of_weeks)	//subtracts from timer
	{
		m_timer-=num_of_weeks;
		return 1;
	}
	else				//adds the proper ratio of quantity to the commodities in the material's yeild vector
	{
		m_timer = 0;
		m_material->yeilds()[0]->add_quantity(m_quantity * m_material->ratio()[0]);
		if (m_material->components()[1]>0)
			m_material->yeilds()[1]->add_quantity(m_quantity * m_material->ratio()[1]);
		if (m_material->components()[2]>0)
			m_material->yeilds()[2]->add_quantity(m_quantity * m_material->ratio()[2]);
		return 0;
	}
}



