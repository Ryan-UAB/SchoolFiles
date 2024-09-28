#ifndef deque_h
#define deque_h

class Deque{
 private:
  struct Element{
    int val;
    Element *lastElement;
    Element *nextElement;
    Element(int cVal, Element *cElementT, Element *cElementB);
  };
  Element *topOfStack;
  Element *bottomOfStack;
  
 public:
  Deque();
  Element *getTopOfStack();
  void setTopOfStack(Element *e);
  Element *getBottomOfStack();
  void setBottomOfStack(Element *e);
  
  void push_front(int i);
  void push_back(int i);
  int pop_front();
  int pop_back();
  int peak_front();
  int peak_back();
  void remove_all();

  ~Deque();
};

#endif
