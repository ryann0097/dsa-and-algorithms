#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "node.h"
#include <iostream>

class BinaryTree {
    private:
    Node *root = nullptr;
    
    public:
    // Binary Tree manipulating functions
    Node* addNode(int key, Node *node);
    void removeNode(int key);
    Node *removeNodeRec(Node *node, int key);

    // Binary Tree traversal functions
    void preOrder(Node *node);
    void postOrder(Node *node);
    void symmetricalOrder(Node *node);

    // Binary Tree search function
    Node *search(int key);
};

#endif 