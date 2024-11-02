#include "myString.h"
#include <cstring>

myString::myString(std::string input){
  int length = 0;
  while(input[length] != '\0'){length++;}
  mystr = new char[length];
  length = 0;
  while(input[length] != '\0'){
    mystr[length] = input[length];
    length++;
  }
}

std::string myString::toString(){
  std::string str;
  int len = 0;
  while(mystr[len] != '\0'){
    str+= mystr[len];
    len++;
  }
  return str;
}

int myString::length(){
  int len = 0;
  while(mystr[len] != '\0'){len++;}
  return len;
}

std::ostream& operator<<(std::ostream& os, const myString& obj){
  os << obj.mystr;
  return os;
}




