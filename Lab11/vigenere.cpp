#include "vigenere.h"
#include <iostream>

Vigenere::Vigenere(std::string key){
  vigkey = key;
}

std::string Vigenere::encrypt(std::string msg){
  std::string enmsg;
  //Comparisons weren't possible with just typing space
  std::string space = " ";
  //keeping a seperate count for the key
  int count = 0;
  int startlen = vigkey.length();
  int convert;
  for(int i = 0; i < msg.length(); i++){
    if(msg[i] == space[0]){continue;}
    if(count == startlen){count = 0;}
    //Converts the characters to ascii to do vigenere
    convert = ((msg[i] - 65 + vigkey[count] - 65) % 26) + 65;
    std::string encryptedletter(1, (char)convert);
    enmsg += encryptedletter;
    count++;
  }
  return enmsg;
}

std::string Vigenere::decrypt(std::string msg){
  std::string demsg;
  std::string space = " ";
  int count = 0;
  int startlen = vigkey.length();
  int convert;
  for(int i = 0; i < msg.length(); i++){
    if(msg[i] == space[0]){continue;}
    if(count == startlen){count = 0;}
    //Converts to ascii
    convert = ((msg[i] - 65 - vigkey[count] - 65) % 26) + 91;
    std::string decryptedletter(1, (char)convert);
    demsg += decryptedletter;
    count++;
  }
  return demsg;
}

bool Vigenere::isEncrypted(std::string encryptedMsg, std::string decryptedMessage){
  if(encryptedMsg == encrypt(decryptedMessage)){return true;}
  else{return false;}
}

void Vigenere::setKey(std::string key){
  vigkey = key;
}
