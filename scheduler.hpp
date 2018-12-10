#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
using namespace std;


struct timeInfo{
  int startHours;
  int endHours;
  string event;
  string ampm;
  bool occupied;
  // string startam;
  // string startam;
  // string endam;
  // string endpm;
};

class timeSlot
{
private:

public:
  timeSlot();
  // ~timeSlot();

  //instance
  timeInfo slot;
  timeInfo boolArray[9];
  timeInfo eventArray[9];

  //functions
  void storeInfo(timeInfo slot);
  void scheduleArray();
  void setRecommendations();
  void getRecommendations(int);

};

struct User{
  string username;
  list <timeSlot> allEvents;
};
