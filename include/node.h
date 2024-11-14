#ifndef NODE_H
#define NODE_H

#include <iostream>

struct Node{
    int key;
    Node *left;
    Node *right;
    Node *parent;
};

#endif