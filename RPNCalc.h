#include "GenStack.h"


class RPNCalc{
  public:
    RPNCalc();
    ~RPNCalc();
    int calculateRPN(string input);
  private:
      GenStack<int> *rpnBank;

};
