
#include "array_list.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>


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

/*void purge(Partlist &l)
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
*/
void Partlist::add(Part newpart)
{
    if (m_last < MAX_PARTS)
    {
        m_elements[m_last + 1] = newpart;
        m_last++;
    }
    else
    {
        std::cout << "Not enough space for new parts" << std::endl;
    }
}

int Partlist::size()
{
    return m_last;
}


