//
// Created by Ben Cradick on 2019-02-19.
//

#include "Node.h"

//TODO: Build nodes and trees!!






    Node::Node(std::string token){
            data = token;
            rightChild = nullptr;
            leftChild = nullptr;
            dataLength =  data.length();
        }
