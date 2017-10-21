
#include "array_list.hpp"
 

//constructor 

Partlist::Partlist()
{


}

//return first position of array list
int Partlist::first()
{


}

//return "one past the end" position of array list
int Partlist::end()
{


}

//returns position one after the current position of array list
int Partlist::next(int current_pos)
{


}

//returns true if the array list is full, and false if not full
bool Partlist::is_full()
{


}

//return element at position of array list
Part Partlist::retrieve(int position)
{


}

//delete element at position of array list
void Partlist::remove(int position)
{
	int i; 

	if (position > m_last || position < 0) return;
	for (i= position; i< m_last; i++)
	{
		m_elements[i] = m_elements[i+1];
	}
	m_last--;

}

//add element to array list
void Partlist::ass(Part newpart)
{


}





