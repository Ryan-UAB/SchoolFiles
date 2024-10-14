#ifndef event_h
#define event_h

#include <string>
#include <vector>

class Event{
 public:
  std::string eventName;
  int eventDate;
  std::string eventLocation;
  Event();
  Event(std::string cEventName, int cEventDate, std::string cEventLocation);
  virtual std::string getDetails() = 0;
  virtual ~Event() {}
};

class Concert : public Event{
 public:
  int eventtype = 1;
  std::string bandName;
  std::string genre;
  Concert();
  Concert(std::string cEventName, int cEventDate, std::string cEventLocation, std::string cBandName, std::string cGenre);
  std::string getDetails() override;
};

class Conference : public Event{
 public:
  int eventtype = 2;
  std::string speaker;
  std::string topic;
  Conference();
  Conference(std::string cEventName, int cEventDate, std::string cEventLocation, std::string cSpeaker, std::string cTopic);
  std::string getDetails() override;
};

class EventFactory{
 public:
  virtual Event* createEvent(std::string cEventName, int cEventDate, std::string cEventLocation, std::string cSpecificName, std::string cSpecificContext) = 0;
  virtual ~EventFactory() {}
};

class ConcertFactory : public EventFactory{
 public:
  Event* createEvent(std::string cEventName, int cEventDate, std::string cEventLocation, std::string cBandName, std::string cGenre) override;
};

class ConferenceFactory : public EventFactory{
 public:
  Event* createEvent(std::string cEventName, int cEventDate, std::string cEventLocation, std::string cSpeaker, std::string cTopic) override;
};

std::string findDate(int date);

class SearchingStrategy{
 public:
  virtual std::vector<Event*> searchEvent(std::vector<Event*> vec, std::string searchThing) = 0;
};

class TypeSearching : public SearchingStrategy{
 public:
  std::vector<Event*> searchEvent(std::vector<Event*> vec, std::string type) override;
};

class DateSearching : public SearchingStrategy{
 public:
  std::vector<Event*> searchEvent(std::vector<Event*> vec, std::string date) override;
};

class LocationSearching : public SearchingStrategy{
 public:
  std::vector<Event*> searchEvent(std::vector<Event*> vec, std::string location) override;
};

class SearchContext{
 public:
  SearchingStrategy* strategy;
  void setStrategy(SearchingStrategy* strategy);
  void executeStrategy(std::vector<Event*> vec, std::string searchstrategy);
};


#endif
