#include "RPNCalc.h"
#include <string>
#include <iostream>
using namespace std;

RPNCalc::RPNCalc(){
  rpnBank = new GenStack<int>();
}
RPNCalc::~RPNCalc(){
  delete rpnBank;
}

int RPNCalc::calculateRPN(string input){//https://medium.com/@ainayat865/reverse-polish-notation-rpn-with-stack-4551a5f54ae0
  string userInput = input;
  while(0<userInput.length()){//loop of entire line
    int i = 0;
    string element = "";
    if(input.length() > 1){
      element = userInput.substr(0,1);
    }
    if (isdigit(element[i])){//if a number, store it
      i++;
      while(isdigit(userInput[i])){
        element = element + userInput[i];
        i++;
      }
      rpnBank->push(stoi(element)); 
    }else if(element == "+"){// if a operator check and see if ther are two the do it to the top last items in the stack
      if(rpnBank->size() < 2){
        cout<<"Something is off in the notation, an error occured with +" <<endl;
        break;
      }
      int b = rpnBank->pop();
      int a = rpnBank->pop();
      int c = a + b;
      rpnBank->push(c);
    }else if(element == "-"){
      if(rpnBank->size() < 2){
        cout<<"Something is off in the notation, an error occured with -" <<endl;
        break;
      }
      int b = rpnBank->pop();
      int a = rpnBank->pop();
      int c = a - b;
      rpnBank->push(c);
    }else if(element == "*"){
      if(rpnBank->size() < 2){
        cout<<"Something is off in the notation, an error occured with *" <<endl;
        break;
      }
      int b = rpnBank->pop();
      int a = rpnBank->pop();
      int c = a * b;
      rpnBank->push(c);
    }else if(element == "/"){
      if(rpnBank->size() < 2){
        cout<<"Something is off in the notation, an error occured with /" <<endl;
        break;
      }
      int b = rpnBank->pop();
      int a = rpnBank->pop();
      int c = a / b;
      rpnBank->push(c);
    }else if(element == "%"){
      if(rpnBank->size() < 2){
        cout<<"Something is off in the notation, an error occured with %" <<endl;
        break;
      }
      int b = rpnBank->pop();
      int a = rpnBank->pop();
      int c = a % b;
      rpnBank->push(c);
    }
    userInput = userInput.substr(i+1);
  }
  int output = rpnBank->pop();
  return output;
}
