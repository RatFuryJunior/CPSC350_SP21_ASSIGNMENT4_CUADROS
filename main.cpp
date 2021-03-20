#include "RPNCalc.h"
#include "FileProcessor.h"
#include "DNAComplement.h"

using namespace std;

int main(int argc, char **argv) {
  string inputChoice;
  if(argc>1){//check for existing arg
    inputChoice = argv[1];
  }else{
    cout<<"Mising Paramater, type DNA or RPN for the mode"<<endl;
  }

  if(inputChoice == "RPN"){//For RPN
    cout<<"What is the input for the operands and operators?"<<endl;
    string userRPN;
    cin.clear();
    getline(cin, userRPN);
    userRPN = string(userRPN);
    //takes in user's input and runs it through calculateRPN
    RPNCalc r1 = RPNCalc();
    cout<< r1.calculateRPN(userRPN)<<endl;


  }else if(inputChoice == "DNA"){// for DNA
    cout<<"What is the input file name? ex: input.txt"<<endl;
    cout<<"Note; any incorreect letters for DNA will be treated as empty"<<endl;
    string userFile = "";
    cin.clear();
    cin>> userFile;
    //takes in file name and openss file
    FileProcessor f1 = FileProcessor();
    DNAComplement d1 = DNAComplement();
    f1.makeOutFile();

    int i = 0;
    string input = f1.loadLineFromFile(userFile, i+1);
    while(i < f1.numberOfLines(userFile)){// loops through each line of the in file
      if (i >10){
        break;
      }
      string line = "";
      for (int i = 0; i <input.length();i++){
        if(input[i] == 'A' ||input[i] == 'G' ||input[i] == 'T' ||input[i] == 'C'){
          string dnaToAdd(1, input[i]);
          line = line + dnaToAdd;
        }
      }
      i++;// for each line, it will then print the Sequence, Complement and reverse Complement to the outputfile
      f1.printToFileDNA("Sequence: " + line + "\n");
      string output = d1.calculateComplement(line,0);
      f1.printToFileDNA("Complement: " + output + "\n");
      string outputReverse = d1.calculateComplement(line,1);
      f1.printToFileDNA("Reverse Complement: " + outputReverse + "\n");
      input = f1.loadLineFromFile(userFile, i+1);
    }
    cout<<"Printed to the file dnaoutput.txt"<<endl;
  }else{
    cout<<"Please try again, input must be DNA or RPN"<<endl;
  }
  return 0;
}
