//
// Created by Ben Cradick on 2019-02-19.
//

#include "Tree.h"
#include <iostream>


Tree::Tree(std::fstream &ptr)
{
    root = new Node();
    buildTree(ptr);
}

void Tree::buildTree(std::fstream &ptr)
{
    std::string line;


    char delimiters[] = {'\t', ' '}; //the \n character is caught by the std::getline function.
    size_t delimLength = sizeof(delimiters);

    while(std::getline(ptr,line))
    {
        std::size_t previousPosition = 0; //where to start search
        std::size_t currentPosition; // where the loop is.

        std::string word; //holds the last/most recent word pulled from the file
        while((currentPosition = line.find_first_of(delimiters, previousPosition, delimLength)) != std::string::npos)//npos = end position
        {
            if(currentPosition > previousPosition)
            {
                // all done recursively.
                word = line.substr(previousPosition, currentPosition - previousPosition);
                insert(root, word, word.length());
            }

            previousPosition = currentPosition + 1;
        }

        if(previousPosition < line.length())
        {
            word = line.substr(previousPosition, std::string::npos);
            insert(root, word, word.length());
        }
    }
}

void Tree::insert(Node*& root, std::string word, unsigned long dataLength)
{


    if(root->dataLength == 0)
    {
        *root = Node(word);
        return;
    }
    else if(root->dataLength > dataLength)
    {
        if(root->leftChild == nullptr)
        { //check prevents BAD_EXEC errors that were occurring without suboptimal but necessary.
            root->leftChild = new Node();
        }
        insert(root->leftChild, word, dataLength);

    }
    else if(root->dataLength < dataLength)
    {
        if(root->rightChild == nullptr)
        {
            root->rightChild = new Node();
        }
        insert(root->rightChild, word, dataLength);
    }
    else
    {
        root->addWord(word);
        return;
    }
}
// These three functions are the meet and potatoes of the print_X_Order functions
// the actual functions to be called are really just to fit definition requirements
void preOrderHelper(int height, Node* node)
{
    if(node == nullptr)
    {
        return;
    }
    for(int i = 0; i < height; i++)
    {
        std::cout << "  ";
    }
    std::cout << "string length:" << node->dataLength << " ";
    node->printNode();
    std::cout << std::endl;

    preOrderHelper(height+1, node->leftChild);
    preOrderHelper(height+1, node->rightChild);
}

//Recursive implementations of different types of traversals.
void postOrderHelper(int height, Node* node)
{
    if(node == nullptr)
    {
        return;
    }

    postOrderHelper(height+1, node->leftChild);
    postOrderHelper(height+1, node->rightChild);

    //lazy implementation of the printing requirements of 2X height indentation followed by string lengths then names.
    for(int i = 0; i < height; i++)
    {
        std::cout << "  ";
    }

    std::cout << "string length:" << node->dataLength << " ";
    node->printNode();
    std::cout << std::endl;
}
void inOrderHelper(int height, Node* node)
{
    if(node == nullptr)
    {
        return;
    }
    inOrderHelper(height+1, node->leftChild);

    for(int i = 0; i < height; i++)
    {
        std::cout << "  ";
    }
    std::cout << "string length:" << node->dataLength << " ";
    node->printNode();
    std::cout << std::endl;

    inOrderHelper(height+1, node->rightChild);
}

void Tree::printPostOrder()
{
    postOrderHelper(0, root);
}
void Tree::printPreOrder()
{
    preOrderHelper(0, root);
}
void Tree::printInOrder()
{
    inOrderHelper(0, root);
}

