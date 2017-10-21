
#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

const int MAX_PARTS = 100;

struct Part
{
    std::string pname;
    std::string pnumber;
    double weight;
    std::string supplier1;
    std::string supplier2;
    int in_stock;
};

class Partlist
{
public:
	Partlist();
	int first();
	int end();
	int next(int current_pos);
	bool is_full();
	Part retrieve(int position);
	void remove(int position);
	void add(Part newpart);

private:
	Part m_elements[MAX_PARTS];
	int m_last;

};

Partlist::Partlist()
{
	m_last = -1;

}

int Partlist::first()
{
	return 0;

}

int Partlist::end()
{
	return m_last + 1;
}

int Partlist::next(int current_pos)
{
	return current_pos + 1;
}

Part Partlist::retrieve(int position)
{
	return m_elements[position];
}

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

void purge(Partlist &l)
{
	int current, compare;
	
	current = l.first();
	while(compare != l.end())
	{
		compare = l.next(current);
		while(compare != l.end())
		{
		if(l.retrieve(current).number == l.retrieve(compare).number)
			l.remove(compare); 
		else 
			compare = l.next(compare);
		}	

	}
	current = l.next(current);
}

void Partlist::add(Part newpart)
{


}

#endif
