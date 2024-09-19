#include <iostream>
#include <string>

struct Book{
  std::string title;
  std::string author[5];
  int catalognumber;
  std::string subject[5];
  std::string publisher;
  int yearofpub;
  bool circulating;
};

struct Library{
  Book list[1000];
};

int numberofbooks = 0;

void addBook(Library* library){
  if(numberofbooks > 1000){
    std::cout << "Too many books.";
    return;
  }
  Book book;
  std::string title;
  std::cout << "Please input the book title.\n";
  std::cin.ignore();
  std::getline(std::cin, title);
  book.title = title;
  int authornumber;
  std::string author;
  std::string authors[5];
  std::cout << "Please input the number of authors for this book (up to five). \n";
  std::cin >> authornumber;
  std::cin.ignore();
  std::cout << "Please input the author(s) name(s) one at a time.\n";
  for(int i = 0; i < authornumber; i++){
    std::getline(std::cin, author);
    book.author[i] = author;
  }
  std::cout << "Please input the book's catalog number. \n";
  int catalognumber;
  std::cin >> catalognumber;
  std::cin.ignore();
  book.catalognumber = catalognumber;
  std::cout << "Please input the number of subjects for this book (up to five). \n";
  int subjectnumber;
  std::string subject;
  std::cin >> subjectnumber;
  std::cin.ignore();
  std::cout << "Please input the subject(s) one at a time.\n";
  for(int i = 0; i < subjectnumber; i++){
    std::getline(std::cin, subject);
    book.subject[i] = subject;
  }
  std::string publisher;
  std::cout << "Please input the name of the publisher.\n";
  std::getline(std::cin, publisher);
  book.publisher = publisher;
  int yearofpublisher;
  std::cout << "Please input the year of publication. \n";
  std::cin >> yearofpublisher;
  std::cin.ignore();
  book.yearofpub = yearofpublisher;
  int circulating;
  std::cout << "Is this book still circulating. Input 1 if yes, 0 if no. \n";
  std::cin >> circulating;
  std::cin.ignore();
  switch(circulating){
  case 0:{
      book.circulating = false;
      break;
  }
  case 1:{
      book.circulating = true;
      break;
  }
  default:{
      book.circulating = true;
      break;
  }
  }
  library->list[numberofbooks] = book;
  numberofbooks += 1;
}

void displayBooks(Library library){
  for(int i = 0; i < numberofbooks; i++){
    std::cout << "Title: " << library.list[i].title << " Author: " << library.list[i].author[0] << " " << library.list[i].author[1] << " " << library.list[i].author[2] << " " << library.list[i].author[3] << " " << library.list[i].author[4] << "\n";
  }
  std::cout << "\n";
}

void searchBySubject(Library library, std::string subject){
  for(int i = 0; i < numberofbooks; i++){
    for(int x = 0; x < 5; x++){
      if(library.list[i].subject[x] == subject){
	 std::cout << "Title: " << library.list[i].title << "\n";
         std::cout << "Author: " << library.list[i].author[0] << "\n";
         std::cout << "Catalog Number: " << library.list[i].catalognumber << "\n";
	 std::cout << "--------------------------------------------------------\n";
      }
    }
  }
}

int main() {
  Library library;
  //These books were from an A.I. generated list of c++ books
  Book testbooks[] = {
        {"C++ Programming", {"Bjarne Stroustrup"}, 1, {"Programming", "C++"}, "Addison-Wesley", 1998, true},
        {"Effective C++", {"Scott Meyers"}, 2, {"Programming", "C++"}, "Addison-Wesley", 2005, true},
        {"The C++ Programming Language", {"Bjarne Stroustrup"}, 3, {"Programming", "C++"}, "Addison-Wesley", 2013, true},
        {"Design Patterns", {"Erich Gamma", "Richard Helm"}, 4, {"Software Engineering", "Design Patterns"}, "Addison-Wesley", 1994, false},
        {"Clean Code", {"Robert C. Martin"}, 5, {"Software Engineering", "Code Quality"}, "Prentice Hall", 2008, true}
  };
  for(int i = 0; i < 5; i++){
    library.list[numberofbooks] = testbooks[i];
    numberofbooks += 1;
  }
  std::cout << "Welcome to the library.\n";
  int menu;
  do {
    std::cout << "Press 1 to add a new book\n" << "Press 2 to display all books\n" << "Press 3 to search by a subject\n" << "Press 4 to exit the menu\n" << "Please input your choice: ";
    std::cin >> menu;
    switch (menu){
    case 1:{
        addBook(&library);
	break;
    }
    case 2:{
        displayBooks(library);
        break;
    }
    case 3:{
        std::string subject;
        std::cout << "Please enter the subject you are looking for.\n";
	std::cin.ignore();
        std::getline(std::cin, subject);
        searchBySubject(library, subject);
        break;
    }
    case 4:{
      std::cout << "Exiting\n";
      break;
    }
    default:{
	std::cout << "Please input a valid choice.";
    }
    }
  } while(menu != 4);
  
  return 0;
}
