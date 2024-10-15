#include "event.h"

Event::Event(){
  eventName = "To be updated";
  eventDate = 0;
  eventLocation = "To be updated";
}

Concert::Concert(){};
Conference::Conference(){};

Event::Event(std::string cEventName, int cEventDate, std::string cEventLocation){
  eventName = cEventName;
  eventDate = cEventDate;
  eventLocation = cEventLocation;
}

Concert::Concert(std::string cEventName, int cEventDate, std::string cEventLocation, std::string cBandName, std::string cGenre){
  eventName = cEventName;
  eventDate = cEventDate;
  eventLocation = cEventLocation;
  bandName = cBandName;
  genre = cGenre;
  eventtype = 1;
}

Conference::Conference(std::string cEventName, int cEventDate, std::string cEventLocation, std::string cSpeaker, std::string cTopic){
  eventName = cEventName;
  eventDate = cEventDate;
  eventLocation = cEventLocation;
  speaker = cSpeaker;
  topic = cTopic;
  eventtype = 2;
}

Event* ConcertFactory::createEvent(std::string cEventName, int cEventDate, std::string cEventLocation, std::string cBandName, std::string cGenre) {return new Concert(cEventName, cEventDate, cEventLocation, cBandName, cGenre);}

Event* ConferenceFactory::createEvent(std::string cEventName, int cEventDate, std::string cEventLocation, std::string cSpeaker, std::string cTopic) {return new Conference(cEventName, cEventDate, cEventLocation, cSpeaker, cTopic);}

std::string findDate(int date){
  int day = date % 100;
  int month = date / 100;
  std::string fulldate = std::to_string(month)+ "/" + std::to_string(day);
  return fulldate;
}

std::string Event::getDetails(){
  std::string details;
  details += eventName + " will be at " + eventLocation + " on " + findDate(eventDate);
  return details;
}

std::string Concert::getDetails(){
   std::string details;
   details += "Come see the " + genre + " band " + bandName + " at " + eventName + " on " + findDate(eventDate) + " at " + eventLocation;
  return details;
}

std::string Conference::getDetails(){
   std::string details;
   details += "Come listen to " + speaker + " talk about " + topic + " at " + eventName + " on " + findDate(eventDate) + " at " + eventLocation;
  return details;
}

std::vector<Event*> TypeSearching::searchEvent(std::vector<Event*> vec, std::string type){
  std::vector<Event*> typelist;
  for(int i = 0; i < vec.size(); i++){
    if(std::to_string(vec[i]->eventtype) == type){
      typelist.push_back(vec[i]);
    }
  }
  return typelist;
}

std::vector<Event*> DateSearching::searchEvent(std::vector<Event*> vec, std::string date){
  std::vector<Event*> datelist;
  for(int i = 0; i < vec.size(); i++){
    if(std::to_string(vec[i]->eventDate) == date){
      datelist.push_back(vec[i]);
    }
  }
  return datelist;
}

std::vector<Event*> LocationSearching::searchEvent(std::vector<Event*> vec, std::string location){
  std::vector<Event*> locationlist;
  for(int i = 0; i < vec.size(); i++){
    if(vec[i]->eventLocation == location){
      locationlist.push_back(vec[i]);
    }
  }
  return locationlist;
}

void SearchContext::setStrategy(SearchingStrategy* strategy){
  this->strategy = strategy;
}

std::vector<Event*> SearchContext::executeStrategy(std::vector<Event*> vec, std::string searchstrategy){
  std::vector<Event*> searched;
  searched = strategy->searchEvent(vec, searchstrategy);
  return searched;
}
