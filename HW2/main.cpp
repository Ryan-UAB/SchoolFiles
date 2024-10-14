#include "event.h"
#include <iostream>
#include <vector>

int main(){
  //Factories
  EventFactory* concertFactory = new ConcertFactory();
  EventFactory* conferenceFactory = new ConferenceFactory();

  //Contexts
  SearchContext context;
  TypeSearching typesearch;
  DateSearching datesearch;
  LocationSearching locationsearch;
  
  //Input variables
  std::vector<Event*> events;
  std::vector<Event*> searched;
  std::string iname;
  int idate;
  std::string ilocation;
  std::string ibandname;
  std::string igenre;
  std::string ispeaker;
  std::string itopic;
  std::string itype;
  int input;

  while(input != 5){
    std::cout << "Welcome to the Event Management System.\n" << "Please press the number that corresponds with the action you want.\n" << "1. Create new event\n" << "2. Search for an event.\n" << "3. Display details of events\n" << "4. List all upcoming events\n" << "5. Exit the menu\n";
    std::cin >> input;
    std::cin.ignore();
    switch(input){
    case 1:
      std::cout << "Please press the number of the event you are trying to add.\n" << "1. Concert\n" << "2. Conference\n";
      std::cin >> input;
      std::cin.ignore();
      switch(input){
      case 1:
      std::cout << "Please input the name of the event you would like to add.\n";
      std::getline(std::cin, iname);
      std::cout << "Please input the date of the event. Format: January 1st = 0101, October 29 = 1029, etc.\n";
      std::cin >> idate;
      std::cin.ignore();
      std::cout << "Please input the location of the event.\n";
      std::getline(std::cin, ilocation);
      std::cout << "Please input the band name for this event.\n";
      std::getline(std::cin, ibandname);
      std::cout << "Please input the genre of the band.\n";
      std::getline(std::cin, igenre);
      events.push_back(concertFactory->createEvent(iname, idate, ilocation, ibandname, igenre));
      break;
      case 2:
      std::cout << "Please input the name of the event you would like to add.\n";
      std::getline(std::cin, iname);
      std::cout << "Please input the date of the event. Format: January 1st = 0101, October 29 = 1029, etc.\n";
      std::cin >> idate;
      std::cin.ignore();
      std::cout << "Please input the location of the event.\n";
      std::getline(std::cin, ilocation);
      std::cout << "Please input the speaker for this event.\n";
      std::getline(std::cin, ispeaker);
      std::cout << "Please input the topic of the conference.\n";
      std::getline(std::cin, itopic);
      events.push_back(conferenceFactory->createEvent(iname, idate, ilocation, ispeaker, itopic));
      break;
      default:
	std::cout << "Please input a valid option.\n";
	break;
      }
      break;
    case 2:
      std::cout << "Please choose a number of what type of search you would like.\n" << "1. Search by Type\n" << "2. Search by Date\n" << "3. Search by Location\n";
      std::cin >> input;
      std::cin.ignore();
      switch(input){
      case 1:
	context.setStrategy(typesearch);
	std::cout << "What type of event are you searching for?\n" << "1. Concerts\n" << "2. Conferences\n";
	std::cin >> input;
	itype = std::to_string(input);
	searched = context.executeStrategy(events, itype);
	for(int i = 0; i < searched.size(); i++){
	  std::cout << searched[i]->getDetails() << std::endl;
	}
	searched.clear();
	break;
      case 2:
	context.setStrategy(datesearch);
	std::cout << "Please input the date you are searching for. Format: January 1 = 0101, October 29 = 1029\n";
	std::cin >> idate;
	itype = std::to_string(idate);
	searched = context.executeStrategy(events, itype);
	for(int i = 0; i < searched.size(); i++){
	  std::cout << searched[i]->getDetails() << std::endl;
	}
	searched.clear();
	break;	  
      case 3:
	context.setStrategy(locationsearch);
	std::cout << "Please input the location of an event.";
	std::getline(std::cin, ilocation);
	searched = context.executeStrategy(events, ilocation);
	for(int i = 0; i < searched.size(); i++){
	  std::cout << searched[i]->getDetails() << std::endl;
	}
	searched.clear();
	break;
      default:
	std::cout << "Please input a valid option.\n";
	break;
      }
      break;
    case 3:
      for(int i = 0; i < events.size(); i++){
	std::cout << events[i]->getDetails() << std::endl;
      }
      while(input != 0){
	std::cout << "Please input 0 to return.\n";
	std::cin >> input;
	std::cin.ignore();
      }
      break;
    case 4:
      std::cout << "N/A\n";
      break;
    case 5:
      std::cout << "Exiting\n";
      break;
    default:
      std::cout << "Please input a valid option.\n";
      break;
    }
  }

  for(int i = 0; i < events.size(); i++){
    delete events[i];
  }
  delete concertFactory;
  delete conferenceFactory;
  return 0;
}
