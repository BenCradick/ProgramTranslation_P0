//
// Created by Ben Cradick on 2019-02-19.
//

#include "Tree.h"
#include <iostream>

Tree::Tree(std::fstream &ptr) {
    // Holds
    std::vector<std::string> words;
    std::string line;

    char delimiters[] = {'\t', ' '}; //the \n character is caught by the std::getline function.
    size_t delimLength = sizeof(delimiters);

    while(std::getline(ptr,line)){
        std::size_t previousPosition = 0; //where to start search
        std::size_t currentPosition; // where the loop is.
        /*
         * TODO: This is an intermediary implementation and must be reworked streamline the vector out of the algorithm
         */
        while((currentPosition = line.find_first_of(delimiters, previousPosition, delimLength)) != std::string::npos){
            if(currentPosition > previousPosition){
                words.push_back(line.substr(previousPosition, currentPosition - previousPosition));
            }

            previousPosition = currentPosition + 1;
        }

        if(previousPosition < line.length()){
            words.push_back(line.substr(previousPosition, std::string::npos));
        }


    }
    //Will be nuked in favor of using the insert function.
    while(!words.empty()){
        std::cout << words.at(0) << std::endl;
        words.erase(words.begin());
    }
}