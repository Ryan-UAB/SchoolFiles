#include <iostream>
#include <string>
#include <fstream>
#include "randword.h"

void hangman(){
  int attempt = 0;
  std::string randomword = RandDictionary();
  int length = randomword.length();
  std::string hiddenword;
  char dash = char(45);
  for(int i = 0; i < length; i++){
    if(randomword[i] == dash){
      hiddenword.append("?");
    }
    else{
      hiddenword.append("-");
    }
  }
  std::cout << "Welcome to hangman. The dashes are letters and the question marks are symbols like -.\n";
  char input;
  while(attempt < 11){
    std::cout << "The word currently looks like this: " << hiddenword << ". Guess a lowercase letter. \n";
    std::cin >> input;
    int letters = 0;
    for(int i = 0; i < length; i++){
      if(randomword[i] == input){
	hiddenword[i] = input;
	letters += 1;
      }
    }
    if(hiddenword == randomword){
      std::cout << "Congratulations, you won! The word was " << randomword << ".\n";
      break;
    }
    if(letters == 1){
      std::cout << "Correct, there was " << letters << " " << input << " in the word. \n";
    }
    if(letters > 1){
      std::cout << "Correct, there were " << letters << " " << input << "'s in the word. \n";
    }
    if(letters == 0){
      attempt += 1;
      std::cout << "Unfortunately, there were no " << input << "'s in the word. \n" << 11 - attempt << "/11 attempts left. \n";
    } 
  }
    if(attempt == 11 && hiddenword != randomword){
      std::cout << "No luck this time. The word was " << randomword << ". Try again. \n";
    }
  
}

int main(){
  hangman();
  
  return 0;
}
