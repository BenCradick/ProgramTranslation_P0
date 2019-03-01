//
// Created by Ben Cradick on 2019-02-19.
//

#include "Tree.h"


Tree::Tree(std::fstream &ptr){
    root = new Node();
    buildTree(ptr);
}

void Tree::buildTree(std::fstream &ptr) {
    std::string line;


    char delimiters[] = {'\t', ' '}; //the \n character is caught by the std::getline function.
    size_t delimLength = sizeof(delimiters);

    while(std::getline(ptr,line)){
        std::size_t previousPosition = 0; //where to start search
        std::size_t currentPosition; // where the loop is.

        std::string word;
        while((currentPosition = line.find_first_of(delimiters, previousPosition, delimLength)) != std::string::npos){
            if(currentPosition > previousPosition){

                word = line.substr(previousPosition, currentPosition - previousPosition);
                insert(root, word, word.length());
            }

            previousPosition = currentPosition + 1;
        }

        if(previousPosition < line.length()){
            word = line.substr(previousPosition, std::string::npos);
            insert(root, word, word.length());
        }
    }
}

void Tree::insert(Node*& root, std::string word, unsigned long dataLength) {
    Node temp = *root;
    do{
        if(root->dataLength == 0){
            *root = Node(word);
            return;
        }
        else if(temp.dataLength > dataLength){
            if(temp.leftChild == nullptr){
                temp.leftChild = new Node(word);
                return;
            }
            else {
                temp = *temp.leftChild;
            }
        }
        else if(temp.dataLength < dataLength){
            if(temp.rightChild == nullptr){
                temp.rightChild = new Node(word);
                return;
            }
            else {
                temp = *temp.rightChild;
            }

        }
        else{
            temp.addWord(word);
            return;
        }
    }while(temp.dataLength != dataLength);

    temp.addWord(word);
}
// These three functions are the meet and potatoes of the print_X_Order functions
// the actual functions to be called are really just to fit definition requirements
void preOrderHelper(int height, Node* node){
    if(node == nullptr){
        return;
    }
    node->printNode();
    preOrderHelper(height+1, node->leftChild);
    preOrderHelper(height+1, node->rightChild);
}
void postOrderHelper(int height, Node* node){
    if(node == nullptr){
        return;
    }
    postOrderHelper(height+1, node->leftChild);
    postOrderHelper(height+1, node->rightChild);

    node->printNode();
}
void inOrderHelper(int height, Node* node){
    if(node == nullptr){
        return;
    }
    inOrderHelper(height+1, node->leftChild);

    node->printNode();

    inOrderHelper(height+1, node->rightChild);
}

void Tree::printPostOrder() {
    postOrderHelper(0, root);
}
void Tree::printPreOrder() {
    preOrderHelper(0, root);
}
void Tree::printInOrder() {
    inOrderHelper(0, root);
}

