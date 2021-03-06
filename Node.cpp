//
// Created by Ben Cradick on 2019-02-19.
//


#include "Node.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>


    Node::Node(std::string token)
    {
            data.insert(token);
            rightChild = nullptr;
            leftChild = nullptr;
            dataLength =  token.length();
    }
    Node::Node()
    {
        this->dataLength = 0;
        rightChild = nullptr;
        leftChild = nullptr;
    }
    void Node::addWord(std::string token)
    {
    data.insert(token);
    }

    void Node::printNode()
    {
        // Bellow function arguments are split up as to maintain readability, arguments were too long without.
        std::copy(
                this->data.begin(),
                this->data.end(),
                std::ostream_iterator<std::string>(std::cout, " ")
                );
    }