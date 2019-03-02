#include <iostream>
#include <string>
#include <cerrno>
#include <fstream>

#include "Tree.h"

using namespace std;

void errorCheckHelper();
void printOutputFiles(string fileName, Tree* binarySearchTree);

int main(int argc, char* argv[])
{
    fstream inputFile;

    string fileName;
    string inputFileName;

    string keyBuffer;

    Tree* binarySearchTree;

    bool tempFile = false; //tracks if we need to delete a temporary file later mkstemp doesn't work on Non-POSIX machines.

    if(argc < 2)
    {
        fileName = "out";
        inputFileName = "./tempFileXXXXXX";
        inputFile.open(inputFileName, fstream::ate); // ate = At The End, meaning write to end of the file.

        getline(cin, keyBuffer);
        inputFile << keyBuffer;
        errorCheckHelper();
        tempFile = true;
    }
    else
     {
        fileName = argv[1];

        inputFileName = fileName + ".sp19";
        inputFile.open(inputFileName);
        errorCheckHelper();
     }

    binarySearchTree = new Tree(inputFile);

    inputFile.close();

    printOutputFiles(fileName, binarySearchTree);

    if(tempFile)
    {
        remove(inputFileName.c_str());
    }
    return EXIT_SUCCESS;
}

void errorCheckHelper()
{
    if(errno != 0)
    {
        perror("Failed to read input: ");
        exit(EXIT_FAILURE);
    }
}
void printOutputFiles(string fileName, Tree* binarySearchTree)
{
    ofstream postOrder;
    ofstream preOrder;
    ofstream inOrder;

    postOrder.open(fileName + ".postOrder", ofstream::ate);
    streambuf *coutBuf = cout.rdbuf(); // saving original cout target
    cout.rdbuf(postOrder.rdbuf()); // aiming cout at file.postOrder
    binarySearchTree->printPostOrder(); // printing
    cout.rdbuf(coutBuf);
    postOrder.close(); // close file
    // repeating process for other files X 2

    preOrder.open(fileName + ".preOrder", ofstream::ate);
    cout.rdbuf(preOrder.rdbuf());
    binarySearchTree->printPreOrder();
    cout.rdbuf(coutBuf);
    preOrder.close();

    inOrder.open(fileName + ".inOrder", ofstream::ate);
    cout.rdbuf(inOrder.rdbuf());
    binarySearchTree->printInOrder();
    cout.rdbuf(coutBuf);
    inOrder.close();
}
