#include "DNAComplement.h"
#include <string>
#include <iostream>
using namespace std;

DNAComplement::DNAComplement(){
  dnaStack = new GenStack<char>();
}
DNAComplement::~DNAComplement(){
  delete dnaStack;
}

string DNAComplement::calculateComplement(string input, bool reverse){
  //takes in a string, bool true for reverse false for normal
  string orignalDNA = input;
  string toRet = "";
  if(reverse){ //reversal
    for(int i = 0; i < input.length(); i++){
      if(input[i] == 'A' ||input[i] == 'G' ||input[i] == 'T' ||input[i] == 'C'){//check for correct DNA
        dnaStack->push(input[i]);
      }
    }
  }else{ //non reverse order
    for(int i = 0; i < input.length(); i++){
      if(input[i] == 'A' ||input[i] == 'G' ||input[i] == 'T' ||input[i] == 'C'){//check for correct DNA
        dnaStack->push(input[input.length()-i-1]);
      }
    }
  }
  for(int i = 0 ; i < input.length(); i++){//swaps based off of what it is to other, A-T and G-C and vice versa
    char dnaSeq;
    if( dnaStack->peek() == 'A'){
      dnaStack->pop();
      dnaSeq = 'T';
    }
    else if( dnaStack->peek() == 'T'){
      dnaStack->pop();
      dnaSeq = 'A';
    }
    else if( dnaStack->peek() == 'G'){
      dnaStack->pop();
      dnaSeq = 'C';
    }
    else if( dnaStack->peek() == 'C'){
      dnaStack->pop();
      dnaSeq = 'G';
    }
    string dnaToAdd(1, dnaSeq);
    toRet = toRet + dnaToAdd;
  }
  return toRet;
}
