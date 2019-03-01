//
// Created by Ben Cradick on 2019-02-19.
//

#ifndef P0_NODE_H
#define P0_NODE_H

#include <set>


class Node {
public:
    Node* rightChild;
    Node* leftChild;

    std::set <std::string> data;

    unsigned long dataLength;

    explicit Node(std::string token);
    Node();

    void addWord(std::string token);
    void printNode();
};


#endif //P0_NODE_H
