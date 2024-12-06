#include "hamming.h"
#include <fstream>
#include <string>
#include <vector>
#include <bitset>

Hamming::Hamming(std::string filename){
  std::ifstream currentfile(filename);
  std::string line;
  while(std::getline (currentfile, line)){
    codes.push_back(stoi(line));
  }
  currentfile.close();
}

void Hamming::encode(){
  for(int i = 0; i < codes.size(); i++){
    std::bitset<7> current(std::to_string(codes[i]));
    int firstbit = current[3];
    int secondbit = current[2]; 
    int thirdbit = current[1]; 
    int fourthbit = current[0];
    int parityone = current[3] ^ current[2] ^ current[0];
    int paritytwo = current[3] ^ current[1] ^ current[0];
    int paritythree = current[2] ^ current[1] ^ current[0];
    int hammingcode = (firstbit * 1000000) + (secondbit * 100000) + (thirdbit * 10000) + (fourthbit * 1000) + (parityone * 100) + (paritytwo * 10) + paritythree;
    encoded.push_back(hammingcode);
  }
}

void Hamming::decode(){
  for(int i = 0; i < codes.size(); i++){
    std::bitset<7> current(std::to_string(codes[i]));
    int checkone = current[6] ^ current[5] ^ current[3];
    int checktwo = current[6] ^ current[4] ^ current[3];
    int checkthree = current[5] ^ current[4] ^ current[3];
    if(checkone != current[2] && checktwo != current[1] && checkthree != current[0]){current.flip(3);}
    else if(checkone!= current[2] && checktwo!= current[1]){current.flip(6);}
    else if(checkone!= current[2] && checkthree!= current[0]){current.flip(5);}
    else if(checktwo!= current[1] && checkthree!= current[0]){current.flip(4);}
    else if(checkone!= current[2]){current.flip(2);}
    else if(checktwo!= current[1]){current.flip(1);}
    else if(checkthree!= current[0]){current.flip(0);}
    std::string currentstr;
    currentstr = current.to_string();
    decoded.push_back(stoi(currentstr));
  }
}

std::string Hamming::showEncoded(){
  std::string encodedfull;
  for(int i = 0; i < encoded.size(); i ++){
    std::bitset<7> stringbits(std::to_string(encoded[i]));
    encodedfull += stringbits.to_string();
    encodedfull += " ";
  }
  return encodedfull;
}

std::string Hamming::showDecoded(){
  std::string decodedfull;
  for(int i = 0; i < decoded.size(); i ++){
    std::bitset<7> stringbits(std::to_string(decoded[i]));
    decodedfull += stringbits.to_string();
    decodedfull += " ";
  }
  return decodedfull;
}

std::string Hamming::showOriginal(){
  std::string codesfull;
  for(int i = 0; i < codes.size(); i ++){
    std::bitset<7> stringbits(std::to_string(codes[i]));
    codesfull += stringbits.to_string();
    codesfull += " ";
  }
  return codesfull;
}

void Hamming::clear(){
  encoded.clear();
  decoded.clear();
}
