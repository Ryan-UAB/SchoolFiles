#include "deque.h"
#include <iostream>

Deque::Element::Element(int cVal, Element *cElementT, Element *cElementB){
  val = cVal;
  nextElement = cElementT;
  lastElement = cElementB;
}

Deque::Deque(){
  topOfStack = nullptr;
  bottomOfStack = nullptr;
}

Deque::Element *Deque::getTopOfStack() {return topOfStack;}

void Deque::setTopOfStack(Element *e) {topOfStack = e;}

Deque::Element *Deque::getBottomOfStack() {return bottomOfStack;}

void Deque::setBottomOfStack(Element *e) {bottomOfStack = e;}

void Deque::push_front(int i) {
  //if(topOfStack != nullptr){std::cout << topOfStack -> val << std::endl;}
  Element *newElement = new Element(i, topOfStack, nullptr);
  setTopOfStack(newElement);
  if(bottomOfStack == nullptr){
  setBottomOfStack(newElement);
  return;}
  std::cout << bottomOfStack << topOfStack << std::endl;
  //std::cout << topOfStack << " " <<  " " << topOfStack->val <<  std::endl;
  topOfStack -> nextElement -> lastElement = getTopOfStack();
  //std::cout << topOfStack -> nextElement -> lastElement << std::endl;
}

void Deque::push_back(int i) {
  Element *newElement = new Element(i, nullptr, bottomOfStack);
  setBottomOfStack(newElement);
  if(topOfStack == nullptr){
    setTopOfStack(getBottomOfStack());
      return;}
  bottomOfStack -> lastElement -> nextElement = getBottomOfStack();
}

int Deque::pop_front(){
  if(topOfStack != nullptr){
    /*
    if(topOfStack == bottomOfStack){
      int val = topOfStack -> val;
      delete topOfStack;
      delete bottomOfStack;
      //topOfStack = nullptr;
      //bottomOfStack = nullptr;
      return val;
      }*/
    int val = topOfStack -> val;
    Element *ptrNewTop = topOfStack -> nextElement;
    std::cout << topOfStack -> nextElement << " ";
    delete topOfStack;
    setTopOfStack(ptrNewTop);
    if(topOfStack -> lastElement != nullptr){
    topOfStack -> lastElement = nullptr;
    }
    return val;
  }
  std::cout << "Error: Popping empty queue ";
  return 0;
}

int Deque::pop_back(){
  if(bottomOfStack != nullptr){
    int val = bottomOfStack -> val;
    Element *ptrNewBottom = bottomOfStack -> lastElement;
    std::cout << bottomOfStack -> lastElement << " ";
    delete bottomOfStack;
    setBottomOfStack(ptrNewBottom);
    bottomOfStack -> nextElement = nullptr;
    //std::cout << bottomOfStack -> val << std::endl;
    return val;
  }
  std::cout << "Error: Popping empty queue ";
  return 0;
}

int Deque::peak_front(){
  if(topOfStack != nullptr){
    return topOfStack -> val;
  }
  std::cout << "Error: Peaking empty queue ";
  return 0;
}

int Deque::peak_back(){
  if(bottomOfStack != nullptr){
    return bottomOfStack -> val;
  }
  std::cout << "Error: Peaking empty queue ";
  return 0;
}

void Deque::remove_all(){
  int a;
  /*
  while(getTopOfStack() != nullptr){
    int temp = pop_front();
    int temp2 = pop_back();
  }
  */
}


Deque::~Deque() {remove_all();}
