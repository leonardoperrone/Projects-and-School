#include "order.hpp"

//constructor
Order::Order(int time, int quantity) : m_timer(time), m_quantity(quantity)
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

//mutator
void Order::set_timer(int time)
{
   m_timer = time;
}
