#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string RandDictionary(){
  std::srand (time(0));
  std::string dictionary[41238];
  std::ifstream file("dictionary.txt");
  std::string line;
  int i = 0;
  while(getline(file,line)){
    dictionary[i] = line;
    i += 1;
  }
  file.close();
  int upperbound = 41238;
  int randomnum = std::rand() % upperbound;
  std::string randomword = dictionary[randomnum];
  return randomword;
}
