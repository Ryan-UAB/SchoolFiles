#include "hamming.h"
#include <iostream>

int main(){
  Hamming h("HammingCodes.txt");
  h.encode();
  std::cout << h.showEncoded() << "\n";
  Hamming e("EncodedCodes.txt");
  e.decode();
  std::cout << e.showOriginal() << "\n" << e.showDecoded() << "\n";
  
  return 0;
}
