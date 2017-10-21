
#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "parts3.hpp"

const int MAX_PARTS = 100;

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

    int size();
    
private:
    Part m_elements[MAX_PARTS];
    int m_last;
    
};


#endif
