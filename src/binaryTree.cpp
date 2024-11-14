#include "../include/binaryTree.h"

Node* BinaryTree::addNode(int key, Node *node){
    if(this->root == nullptr){
        Node *node = new Node();
        node->key = key;
        node->left = node->right = nullptr;
    }
    if(key < root->key){
        root->left = addNode(key, root->left);
    } else if (key > root->key){
        root->right = addNode(key, root->right);
    }
    return root;
}

void BinaryTree::removeNode(int key){
    root = removeNodeRec(root, key);
}

Node* BinaryTree::removeNodeRec(Node *node, int key){
    if(node == nullptr){ return node; }
    if(key < node->key)
    {
        node->left = removeNodeRec(node->left, key);
    }
    else if(key > node->key)
    {
        node->right = removeNodeRec(node->right, key);
    }
    else
    {
        if(node->left == nullptr)
        {
            Node *temp = node->right;
            delete node;
            return temp;
        }
        else if(node->right == nullptr)
        {
            Node *temp = node->left;
            delete node;
            return temp;
        } 
        Node *temp = new Node();
        while(temp && temp->left != nullptr){
            temp = temp->left;
        }
        node->key = temp->key;
        node->right = removeNodeRec(node->right, temp->key);
    }
    return node;
}

void BinaryTree::preOrder(Node *node){
    if(node == nullptr){
        std::cout << " [ Árvore vazia ]";
    } else {
        std::cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void BinaryTree::postOrder(Node *node){
    if(node == nullptr){
        std::cout << " [ Árvore vazia ]";
    } else {
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->key << " ";
    }
}

void BinaryTree::symmetricalOrder(Node *node){
    if(node == nullptr){
        std::cout << " [ Árvore vazia ]";
    }
    else {
        symmetricalOrder(node->left);
        std::cout << node->key << " ";
        symmetricalOrder(node->right);
    }
}

Node* BinaryTree::search(int key) {
    while(root != nullptr && root->key != key){
        if(key < root->key){
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return root;
}