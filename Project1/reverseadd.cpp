#include <iostream>

int numberreverser(int num){
  int reversednumber = 0;
  int lastnumber = 0;
  while(num){
    lastnumber = num % 10;
    reversednumber = reversednumber * 10 + lastnumber;
    num /= 10;
  }
  return reversednumber;
}

int reverseaddpalindrome(int num){
  int reversednumber = numberreverser(num);
  int reversesum = num;
  while(reversednumber != reversesum){
    reversesum = reversednumber + reversesum;
    reversednumber = numberreverser(reversesum);
  }
  return reversesum; 
}

int reverseadditerations(int num){
  int reversednumber = numberreverser(num);
  int reversesum = num;
  int iterations = 0;
  while(reversednumber != reversesum){
    reversesum = reversednumber + reversesum;
    reversednumber = numberreverser(reversesum);
    iterations += 1;
  }
  return iterations; 
}

int main() {
  int input;
  int test;
  std::cout << "Please input the number of test cases for reverse-add-palindrome." << "\n";
  std::cin >> input;
  int tests[input];
  for(int i = 0; i < input; i++){
    std::cin >> test;
    tests[i] = test;
  }
  std::cout << "\n";
  for(int i = 0; i < input; i++){
    std::cout << reverseadditerations(tests[i]) << " " << reverseaddpalindrome(tests[i]) << "\n";
  }
  return 0;
}
