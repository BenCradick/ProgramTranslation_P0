#include <iostream>
#include <string>
#include <cerrno>
#include <fstream>

using namespace std;


int main(int argc, char* argv[]) {

    fstream inputFile;

    string fileName;
    string inputFileName;

    string keyBuffer;

    bool tempFile = false; //tracks if we need to delete a temporary file later mkstemp doesn't work on Non-POSIX machines.





    if(argc < 2) {
        fileName = "out";
        inputFileName = "./tempFileXXXXXX";
        inputFile.open(inputFileName, fstream::ate); // ate = aT The End, meaning write to end of the file.

        getline(cin, keyBuffer);
        inputFile << keyBuffer;

        tempFile = true;

    }
    else {
        fileName = argv[1];
        inputFileName = fileName + ".sp19";
        inputFile.open(inputFileName);
    }

    if(errno != 0){
        perror("Failed to read input: ");
        exit(EXIT_FAILURE);
    }

    
    inputFile.close();

    if(tempFile){
        remove(inputFileName.c_str());
    }
    return 0;
}