//
// Created by Ben Cradick on 2019-02-19.
//

#ifndef P0_NODE_H
#define P0_NODE_H

#include <string>


class Node {
public:
    Node* rightChild;
    Node* leftChild;

    std::string data;
    unsigned long dataLength;

    explicit Node(std::string token);
};


#endif //P0_NODE_H
