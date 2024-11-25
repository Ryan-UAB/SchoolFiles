#include "vigenere.h"
#include <iostream>

int main(){
  Vigenere cipher("WAR");
  std::cout << cipher.encrypt("CS IS COOL") << "\n";
  std::cout << cipher.decrypt("YS ZO CFKL") << "\n";
  std::cout << cipher.isEncrypted("YSZOCFKL", "CS IS COOL") << "\n";
  cipher.setKey("PEANUTBUTTER");
  std::cout << cipher.encrypt("CS IS COOL") << "\n";
  std::cout << cipher.isEncrypted("YSZOCFKL", "CS IS COOL") << "\n";
  
  
  return 0;
}
