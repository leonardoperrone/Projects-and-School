//  sllist.hpp
//  Leonardo Perrone
//  F285Y428
//  Assignment Number: 4
//  Last Changed: 3/24/2015


#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "parts4.hpp"
#include "utils.hpp"
#define MAX_PARTS 100

struct PartNode
{
    Part value;
    PartNode *next;
};

class Partlist
{
public:
    // constructor and destructor
    Partlist();
    ~Partlist();
    // accessors
    PartNode *first();
    PartNode *end();
    PartNode *next(PartNode *current);
    Part retrieve(PartNode *current);
    int size();
    // mutators
    void remove(PartNode *current);
    void add(Part part);
private:
    // helper functions
    PartNode *make_copy(Part p); //(create_node)
    // data
    PartNode *m_first;
    PartNode *m_last;
};




#endif
