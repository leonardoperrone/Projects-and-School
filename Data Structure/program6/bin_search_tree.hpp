//
//  tree_search_bin.h
//  Assignment6
//
//  Created by Leonardo Perrone on 4/21/15.
//  Copyright (c) 2015 Leonardo Perrone. All rights reserved.
//

#ifndef __Assignment6__tree_search_bin__
#define __Assignment6__tree_search_bin__

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;
// Type definitions
typedef std::string Key;
// Prototypes for stand-alone Key functions
bool key_isequal(Key a, Key b);
bool key_lessthan(Key a, Key b);
// Type definitions for Node and Tree
class Node {
public:
    // Tree functions can access Node data through the accessors, but
    // tree_remove must access the private methods, so it is a friend.
    friend void tree_remove(Node *t, Key k);
    // tree_insert needs access to the private data
    friend void tree_insert(Node **t, Key k);
    // Accessors
    Key key();
    Node *parent();
    Node *leftchild();
    Node *rightchild();
    int num_children();
    // Mutators
    void set_key(Key k);
    void set_parent(Node *p);
    void set_leftchild(Node *l);
    void set_rightchild(Node *r);
private:
    // Private methods
    void replace_with_successor();
    void replace_with_predecessor();
    // Data members
    Key m_key;
    Node *m_parent;
    Node *m_leftchild;
    Node *m_rightchild;
};
typedef Node * Tree;
// Function prototypes
void tree_init(Tree *t);
void tree_makenull(Tree t);
Node *tree_makenode(Key k, Node *parent);
Node *tree_search(Key k, Tree t);
void tree_insert(Tree *t, Key k);
void tree_remove(Node *t, Key k);
void tree_preorder(Node *n, std::ofstream &file);
void tree_postorder(Node *n, std::ofstream &file);
void tree_inorder(Node *n, std::ofstream &file);
bool tree_empty(Tree t);
int tree_height(Tree t);
#endif /* defined(__Assignment6__tree_search_bin__) */
