//  bin_search_tree.cpp
//  Leonardo Perrone
//  F285y428
//  Assignment: 6
//  Last Changed: 4/29/15.

// Description: This program uses a combination of Trees, Keys and Nodes to read a file with a list of students enrolled in a class,
// then read a file with a list of studentds that dropped the class,
// and finally it will write to a file the final list of students enrolled in the class while removing the duplicates.


#include "bin_search_tree.hpp" //including libraries and header files
#include "classlist.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;


// Functions to implement Key operations
// returns true if the two keys are equal, or false otherwise
bool key_isequal(Key a, Key b)
{
    if (a==b)
    {
        return true;
    }else{
        return false;
    }
}
// returns true if a < b, or false otherwise
bool key_lessthan(Key a, Key b)
{
        if (a < b)
        {
            return true;
        }else{
            return false;
        }
}
// Functions to implement Node methods
// Accessors
Key Node::key()
{
    return this-> m_key;
}

Node *Node::parent()
{
    return this-> m_parent;
}

Node *Node::leftchild()
{
    return m_leftchild;
}

Node *Node::rightchild()
{
    return m_rightchild;
}

int Node::num_children()
{
    int sum=0;
    
    if(m_leftchild != NULL){sum++;}
    if (m_rightchild != NULL) {sum++;}

        return sum;
}

// Mutators
void Node::set_key(Key k)
{
    m_key= k;
}

void Node::set_parent(Node *p)
{
    m_parent = p;
}

void Node::set_leftchild(Node *l)
{
    m_leftchild = l;
}

void Node::set_rightchild(Node *r)
{
    m_rightchild = r;
}


// Functions to implement binary search tree operations

// tree initialization - contains what is typically in a constructor
void tree_init(Tree *t)
{
    *t = NULL;
}
// Delete all nodes of a tree - traverse in postorder to delete each child before its parent
void tree_makenull(Tree t)
{
    if (t->leftchild())
        tree_makenull(t->leftchild());
    if (t->rightchild())
        tree_makenull(t->rightchild());
    delete t;
}


// create a new node for a tree
Node *tree_makenode(Key k, Node *parent)
{
    Node* newNode = new Node();
    newNode->set_key(k);
    newNode->set_parent(parent);
    newNode->set_leftchild(NULL);
    newNode->set_rightchild(NULL);
    
    return newNode;
}
// return pointer to node with key k if found in tree, otherwise NULL
Node *tree_search(Key k, Tree t)
{
    Node *output = NULL;
    
    if (t == NULL)
    {
        return NULL;
    }
    else
    {
        if (key_isequal(t->key(), k))
        {
            return t;
        }
        else if (key_lessthan(k, t->key()))
        {
            output = tree_search(k, t->leftchild());
        }
        else
        {
            output = tree_search(k, t->rightchild());
            
        }
    }
    return output;
}

// add a node whose key is k to the tree
void tree_insert(Tree *t, Key k)
{
    Node* currentNode = *t;
    Key currentK = currentNode->key();
    
    if(key_isequal(k, currentK)) // if key is equal to the current key
    {
        //do nothing
    }
    else if (key_lessthan(k, currentK)) //if key is less than the current key
    {
        if(currentNode->leftchild() == NULL) //if no left child
        {
            Node* newNode = tree_makenode(k, *t); //make node and set it as left child
            currentNode->set_leftchild(newNode);
            
        }
        else
        {   Tree tempTree = currentNode->leftchild(); //if left child present, create temp tree and call tree_insert function to insert in main tree
            tree_insert(&tempTree, k); 
            
        }
    }
    else
    {
        if(currentNode->rightchild() == NULL) // if no right child
        {
            Node* newNode = tree_makenode(k, *t); //make node and set it as right child
            currentNode->set_rightchild(newNode);
            
        }
        else
        {
            Tree tempTree = currentNode->rightchild(); //if right child present already, create temp tree and call tree_insert fucntion to insert in main tree
            tree_insert(&tempTree, k);
        }
        
        
    }
    
}

// remove the node with key k from the tree if it is found
void tree_remove(Node *t, Key k)
{
    Tree predecessor; //delcaring variables
    Node* currentNode = t;
    
    if(t == NULL) //if current node is empty
    {
        return;
    }    
    else if(key_lessthan(k, t->key())) //if key is less than current key 
    {
        tree_remove(t->leftchild(), k); //call remove function to remove current node's leftchild
    }
    else if(key_lessthan(t->key(), k)) //if current key is less than key
    {
        tree_remove(t->rightchild(), k); //call remove function to remove current node's rightchild
    }
    else 
    {
        
        switch(currentNode->num_children()) //check number of children
        {
            case 0: //zero children
                
                if(t == t->parent()->leftchild()) //if current node is a leftchild
                {
                    t->m_parent->m_leftchild = NULL; //set it to null
                    
                }
                else
                {
                    t->m_parent->m_rightchild = NULL; //set it to null
                    
                }
                delete t; //delete node
                break;
                
            case 1: //one child
                
                if(t->parent() != NULL) //if current node has a parent
                {
                    if(t == t->parent()->leftchild()) //if current node is leftchild
                    {
                        if(t->leftchild() != NULL) // if current node left child is not null
                        {
                            t->m_parent->m_leftchild = t->leftchild(); //set node to leftchild
                            t->m_leftchild->m_parent = t->parent(); //set node to parent of leftchild
                        }
                        else
                        {
                            t->m_parent->m_leftchild = t->rightchild(); //set node to rightchild
                            t->m_rightchild->m_parent = t->parent();//set node to parent of rightchild
                            
                            
                        }
                    }
                    else
                    {
                        if(t->leftchild() != NULL) // if current node left child is not null
                        {
                            t->m_leftchild->m_parent = t->parent(); // set node to parent of leftchild
                            t->m_parent->m_rightchild = t->leftchild(); //set node to leftchild
                            
                        }
                        else
                        {
                            t->m_rightchild->m_parent = t->parent();//set node to parent of rightchild
                            t->m_parent->m_rightchild = t->rightchild(); //set node to rightchild
                            
                        }
                    }
                }
                
                else
                    delete t; // delete node
                break;
            case 2: //two children
                
                predecessor = t->leftchild(); //set predecessor to node's leftchild
                
                while(predecessor->rightchild() != NULL) //while rightchild is not null
                    predecessor = predecessor->rightchild(); //predecesor becomes its right child
                key_isequal(t->key(), predecessor->key()); //key of current node is equal to predecesor key
                tree_remove(t->leftchild(), predecessor->key()); //remove curr node leftchild and predecessor key
                break;
        }
    }
}
// traverse tree in preorder and write keys to file
void tree_preorder(Node *n, ofstream &finalclasslist) 
{
    if(n)
    {
        finalclasslist << n->key() << endl;
        tree_preorder(n->leftchild(), finalclasslist);
        tree_preorder(n->rightchild(), finalclasslist);
        
    }
}
// traverse tree in postorder and write keys to file
void tree_postorder(Node *n, ofstream &finalclasslist)
{
    if(n)
    {
        tree_postorder(n->leftchild(), finalclasslist);
        tree_postorder(n->rightchild(), finalclasslist);
        finalclasslist << n->key() << endl;
    }
}
// traverse tree in inorder and write keys to file
void tree_inorder(Node *n, ofstream &finalclasslist)
{
    if(n)
    {
        tree_inorder(n->leftchild(), finalclasslist);
        finalclasslist << n->key() << endl;
        tree_inorder(n->rightchild(), finalclasslist);
    }
}
// returns true if t is empty and false otherwise
bool tree_empty(Tree t)
{
    if(t== NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// returns the height of the tree
int tree_height(Tree t)
{
    if(t == NULL)
        return 0;
    else
    {
        int leftheight = tree_height(t->leftchild());
        int rightheight = tree_height(t->rightchild());
        
        if(leftheight > rightheight)
            return (leftheight + 1);
        else
            return (rightheight + 1);
    }
}

