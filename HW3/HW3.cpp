#include <string>
#include <iostream>

std::string HW3_01(std::string first, std::string second){
  std::string sub;
  for(int i = 0; i < first.size(); i++){
    for(int j = 0; j < second.size(); j++){
      if(first[i] == second[j]){
	second.erase(j, 1);
	sub += first[i];
	break;
      }
    }
  }
  std::sort(sub.begin(), sub.end());
  return sub;
}

std::string HW3_02(int num){
  std::string strnum = std::to_string(num);
  int strsize = strnum.length();
  int i = 1;
  int power = 2;
  while(power > 0){
    std::string strpow = std::to_string(power);
    if(strnum == strpow.substr(0, strsize) && strpow.length() != strsize){return std::to_string(i);}
    i++;
    power = power * 2;
  }
  return "no power of 2";
}

/*
int main(){
  std::cout << HW3_01("beetles", "eatery") << "\n";
  std::cout << HW3_02(16) << "\n";
  return 0;
}
*/
