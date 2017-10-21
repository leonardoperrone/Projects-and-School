//  sllist.cpp
//  Leonardo Perrone
//  F285Y428
//  Assignment Number: 4
//  Last Changed: 3/24/2015

//Description: this module contains the implementation of the linked list data structure used to move through the lists of parts

#include "sllist.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>


Partlist::Partlist() //constructor 
{
    m_first = NULL;
    m_last = NULL;
}

Partlist::~Partlist() //deconstructor 
{
    if (m_first != NULL) 
    {
        while (m_first->next != NULL)
        {
            PartNode *node = m_first->next;
            delete m_first;
            m_first = node;
        }
    }
    m_first = NULL;
    m_last = NULL;
}

PartNode *Partlist::first() //points to first node
{
    PartNode *first = m_first;
    return first;
}

PartNode *Partlist::end() // points to last node 
{
    return m_last;
}

PartNode *Partlist::next(PartNode *current) //points to next node
{
    return current->next;
}

Part Partlist::retrieve(PartNode *current) // points to current
{
    
    return current->value;
    
}

void Partlist::remove(PartNode *current) //removes current node
{
    if(current == NULL) { // if we reached end of list or the list is empty
        std::cout << "Can't remove value: no match found.\n";
    } else {
        PartNode *iterator = m_first; 

        while (iterator != NULL && iterator->next != current) 
        {
            iterator = iterator->next; 
        };

        if (iterator != NULL && iterator->next == current)
        {
            iterator->next = current->next; // unlink the node you remove

            if (iterator->next == NULL)
            {
                m_last = iterator;
            }

            delete current; // delete the node
        }
    }
    
    /*
    if (current > m_last || current < 0) return;
    
    for (i= current; i< m_last; i++)
    {
        m_elements[i] = m_elements[i+1];
    }
    m_last--;
    */
}


void Partlist::add(Part newpart) //add new part
{
    PartNode *temp; //declare temporary variable
    temp = make_copy(newpart); //call make_copy function

    if (m_first == NULL) //if empty
    {
        m_first = temp;
        m_last = m_first;
    }
    else // if not empty
    {
        temp->next = NULL; //created a new node at the end
        m_last->next = temp;
        m_last = m_last->next;
    }

   
    /*
    if (m_last < MAX_PARTS)
    {
        m_elements[m_last + 1] = newpart;
        m_last++;
    }
    else
    {
        std::cout << "Not enough space for new parts" << std::endl;
    }
     */
}

PartNode *Partlist::make_copy(Part p) //helper function
{
    
    
    PartNode *temp = new PartNode();

    if (temp == NULL) //if memory is full
    {
        std::cout<< "Not enough memory" <<end();
        return 0;
    }
    else //otherwise return temp
    {
        temp->value = p ;
        temp->next = NULL;
        
        return temp;
    }
}

