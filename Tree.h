//
// Created by Ben Cradick on 2019-02-19.
//

#ifndef P0_TREE_H
#define P0_TREE_H


#include "Node.h"
#include <vector>
#include <fstream>


class Tree {
public:
    Node* root;


    explicit Tree(std::fstream& ptr);


};


#endif //P0_TREE_H
