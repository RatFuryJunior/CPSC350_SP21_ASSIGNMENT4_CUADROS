#include "GenStack.h"

class DNAComplement{
  public:
    DNAComplement();
    ~DNAComplement();
    string calculateComplement(string input,bool reverse);
  private:
    GenStack<char> *dnaStack;
};
