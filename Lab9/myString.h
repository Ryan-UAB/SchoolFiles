#ifndef myString_h
#define myString_h

#include <string>
#include <cstring>
#include <iostream>

class myString{
 public:
  char* mystr;

  friend std::ostream& operator<<(std::ostream& os, const myString& obj);

  myString(std::string input);

  std::string toString();

  int length();

  char* substr(int start, int n);

  ~myString() {delete mystr;}
};

#endif
