#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class FileProcessor{
  public:
    FileProcessor();
    ~FileProcessor();
    string loadLineFromFile(string inputFile, int lineNumber);
    void makeOutFile();
    void printToFileDNA(string line);
    int numberOfLines(string inputFile);
};
