#ifndef _hamming_h
#define _hamming_h

#include <string>
#include <vector>
#include <iostream>

class Hamming{
 private:
  std::vector<unsigned int> codes;
  std::vector<unsigned int> encoded;
  std::vector<unsigned int> decoded;
 public:
  Hamming(std::string filename);
  void encode();
  void decode();
  std::string showEncoded();
  std::string showDecoded();
  std::string showOriginal();
  void clear();

  ~Hamming(){};
};

#endif
