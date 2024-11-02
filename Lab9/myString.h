#ifndef myString_h
#define myString_h

#include <string>
#include <cstring>
#include <iostream>

class myString{
 private:
  char* mystring;

 public:
  myString(std::string input);

  std::string toString();

  int length();

  int substr(start, n);

  ~myString() {delete mystring;}
};

#endif
