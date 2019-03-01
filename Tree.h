//
// Created by Ben Cradick on 2019-02-19.
//

#ifndef P0_TREE_H
#define P0_TREE_H


#include "Node.h"
#include <fstream>


class Tree {
public:
    Node* root;

    explicit Tree(std::fstream& ptr);
    void buildTree(std::fstream& ptr);

    void insert(Node*& root, std::string word, unsigned long wordLength);
    void printInOrder();
    void printPostOrder();
    void printPreOrder();

};


#endif //P0_TREE_H
