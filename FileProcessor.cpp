#include "FileProcessor.h"

using namespace std;
FileProcessor::FileProcessor(){

}
FileProcessor::~FileProcessor(){

}
string FileProcessor::loadLineFromFile(string inputFile,int lineNumber){//takes in line at line number and returns it as a string
  ifstream inFile;
  inFile.open (inputFile);
  if (!inFile.is_open()) {
    cout<<"Something went wrong, check the name of the file"<<endl;
  }
  string toRet = "";
  for (int i = 0; i < lineNumber;++i){
    getline(inFile, toRet);
    int pos = 0;
    while ((pos = toRet.find ("\n",pos)) != string::npos) //https://texthandler.com/info/remove-line-breaks-c/
    {
      pos = pos+1;
      toRet.erase ( pos, 2 );
    }

  }
  inFile.close();
  return toRet;
}

void FileProcessor::makeOutFile(){//creates a new empyy file for dnaoutput
  ofstream outFile;
  outFile.open ("dnaoutput.txt");
  outFile.close();
}
void FileProcessor::printToFileDNA(string line){//prints to the made file
    ofstream outFile;
    outFile.open ("dnaoutput.txt",std::ios_base::app);
    outFile<<line;
    outFile.close();
}
int FileProcessor::numberOfLines(string inputFile){//returns number of lines from the given file name
  int lineCount = 0;
  ifstream inFile;
  string line;
  inFile.open (inputFile);
  if(inFile.is_open()){
    while (getline(inFile, line)){
      lineCount++;
    }
    inFile.close();
  }
  return lineCount;
}
