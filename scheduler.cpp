#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
using namespace std;
#include "dailySchedule.hpp"


timeSlot::timeSlot(){

  for(int i=0; i<9;i++){
    boolArray[i].event = " ";
    boolArray[i].occupied = false;
    boolArray[i].startHours = 0;
    boolArray[i].endHours=0;
    boolArray[i].ampm=" ";

    eventArray[i].event = " ";
    eventArray[i].startHours = 0;
    eventArray[i].endHours=0;
    eventArray[i].ampm=" ";
  }

}
void timeSlot::storeInfo(timeInfo slot)
{
cout << "Here is your schedule for today!" << endl;

for(int i=0; i<9; i++)
{
  if(boolArray[i].occupied == true)
  {
    cout<< "At "<< boolArray[i].startHours << ", you have: " << boolArray[i].event << endl;
  }
}

}

void timeSlot::setRecommendations()
{
    eventArray[0].event = "Physics Colloquium";
    eventArray[0].occupied = true;
    eventArray[0].startHours = 8;
    eventArray[0].endHours=9;
    eventArray[0].ampm= "am";

    eventArray[1].event = "Chemistry Colloquium";
    eventArray[1].occupied = true;
    eventArray[1].startHours = 9;
    eventArray[1].endHours=10;
    eventArray[1].ampm= "am";

    eventArray[2].event = "Data Structures Colloquium";
    eventArray[2].occupied = true;
    eventArray[2].startHours = 10;
    eventArray[2].endHours=11;
    eventArray[2].ampm= "am";

    eventArray[3].event = "Rock Climbing Club";
    eventArray[3].occupied = true;
    eventArray[3].startHours = 11;
    eventArray[3].endHours=12;
    eventArray[3].ampm= "am";


    eventArray[4].event = "Golf Club";
    eventArray[4].occupied = true;
    eventArray[4].startHours = 12;
    eventArray[4].endHours=1;
    eventArray[4].ampm= "am";


    eventArray[5].event = "Cooking Club";
    eventArray[5].occupied = true;
    eventArray[5].startHours = 1;
    eventArray[5].endHours= 2;
    eventArray[5].ampm= "am";

    eventArray[6].event = "Shayon Gupta's Office Hours (CSCI 2270)";
    eventArray[6].occupied = true;
    eventArray[6].startHours = 2;
    eventArray[6].endHours=3;
    eventArray[6].ampm= "am";

    eventArray[7].event = "CU Men's Basketball Game";
    eventArray[7].occupied = true;
    eventArray[7].startHours = 3 ;
    eventArray[7].endHours= 4;
    eventArray[7].ampm= "am";

    eventArray[8].event = "CU Women's Volleyball Game";
    eventArray[8].occupied = true;
    eventArray[8].startHours = 4;
    eventArray[8].endHours= 5;
    eventArray[8].ampm= "am";

    // eventArray[9].event = "Swimming Team Olympics";
    // eventArray[9].occupied = true;
    // eventArray[9].startHours = 5;
    // eventArray[9].endHours= 6;
    // eventArray[9].ampm= "am";
}

ofstream user_recommendations("user_recommendations.txt");

void timeSlot::getRecommendations(int i)
  {
    //ofstream user_recommendations("user_recommendations.txt");
    cout <<"Here is an event that you could go to during your free time!" <<endl;
    cout <<eventArray[i].event <<endl;
    user_recommendations <<"Here is an event that you could go to during your free time!" <<endl;
    user_recommendations <<eventArray[i].event <<endl;
  }



  void timeSlot::scheduleArray()
  {
    for(int i = 0; i<9; i++)
    {
      if(boolArray[i].occupied == false)
      {
        cout <<"You have a free hour at " <<eventArray[i].startHours <<"!" << endl;
        getRecommendations(i);
        user_recommendations <<endl;
      }
    }
  }



// int ampmCalculation(timeInfo slot){
//   //need to continue::
//   //pm calculation:
//   pm = (slot.startHours+11)-12;
//
//   if(pm==0)
//   {
//     return pm;
//   }
//   return pm;
//
// }




int main()
{

  ofstream user_scheduler("user_scheduler.txt");

  timeSlot t;
  int i=0;
  // timeInfo slot;
  t.setRecommendations();

  string input;
  string name;
  string startTime1;
  string startTime2;
  string endTime1;
  string endTime2;
  string appointment;
  string ampm;

  cout << "Welcome to your daily scheduler! " <<endl; //put in line 1 name of person
  cout <<"Enter your name: " <<endl;
  getline(cin, name);
  user_scheduler <<"Name: " <<name <<endl;


  while (input != "4")
  {

    cout << " ------------- Main Menu ------------- " <<endl;
    cout << "1. Enter Info " <<endl;
    cout << "2. View Schedule " <<endl;
    cout << "3. Get Recommendations " <<endl;
    cout << "4. Quit" <<endl;

    getline(cin, input);
    if (input != "1" && input != "2" && input != "3" && input != "4")
    {
      cout <<"Invalid Input! Please enter 1, 2, 3, or 4 to quit. \n Thank you!" <<endl;
    }
    if (input == "1")
    {
      cout <<"Welcome, " <<name <<"." <<endl;
      cout <<"Please enter your schedule: " <<endl;

      cout <<"What time (hours) is your appointment? " <<endl;
      getline(cin,startTime1);
      while (stoi(startTime1) != 8 && stoi(startTime1) != 9 &&stoi(startTime1) != 10 &&stoi(startTime1) != 11 &&stoi(startTime1) != 12 &&stoi(startTime1) != 1 &&stoi(startTime1) != 2 &&stoi(startTime1) != 3 && stoi(startTime1) != 4)
      {
        cout <<"Invalid input! Please enter the hour as a whole number (8,9,10).\n";
        cout <<"What time (hours) is your appointment? " <<endl;
        getline(cin, startTime1);

      }

      user_scheduler <<"Start Time(hours): " <<startTime1 <<endl;

      cout <<"What time (hours) does your appointment end? " <<endl;
      getline(cin,endTime1);




      while (stoi(endTime1) != 8 && stoi(endTime1) != 9 &&stoi(endTime1) != 10 &&stoi(endTime1) != 11 &&stoi(endTime1) != 12 &&stoi(endTime1) != 1 &&stoi(endTime1) != 2 &&stoi(endTime1) != 3 &&stoi(endTime1) != 4 && stoi(endTime1)!=5)
      {
        cout <<"Invalid input! Please enter the hour as a whole number (8,9,10).\n";
        cout <<"What time (hours) does your appointment end? " <<endl;
        getline(cin, endTime1);
      }

      user_scheduler <<"End Time(hours): " <<endTime1 <<endl;

      user_scheduler <<"AM/PM " <<ampm <<endl;

      cout <<"What do you have scheduled at " <<startTime1 <<ampm <<" ?" <<endl;
      getline(cin, appointment);

      user_scheduler <<"Appointment: " <<appointment <<endl;

        if (stoi(startTime1) == 8 && stoi(endTime1)==9)
          {
            i = 0;
          }
          if (stoi(startTime1) == 9 && stoi(endTime1)==10)
          {
            i = 1;
          }
          if (stoi(startTime1) == 10 && stoi(endTime1)==11)
          {
            i = 2;
          }
          if (stoi(startTime1) == 11 && stoi(endTime1)==12)
          {
            i = 3;
          }
          if (stoi(startTime1) == 12 && stoi(endTime1)==1)
          {
            i = 4;
          }
          if (stoi(startTime1) == 1&& stoi(endTime1)==2)
          {
            i = 5;
          }
          if (stoi(startTime1) == 2&& stoi(endTime1)==3)
          {
            i = 6;
          }
          if (stoi(startTime1) == 3&& stoi(endTime1)==4)
          {
            cout <<"Its 7" <<endl;
            i = 7;
          }
          else if (stoi(startTime1) == 4&& stoi(endTime1)==5)
          {
            cout <<"Its 8" <<endl;
            i = 8;
          }


        t.boolArray[i].startHours = stoi(startTime1);
        t.boolArray[i].endHours = stoi(endTime1);
        t.boolArray[i].event = appointment;
        t.boolArray[i].ampm = ampm;
        t.boolArray[i].occupied = true;
        t.storeInfo(t.boolArray[i]);

    }

    if (input == "2")
    {
      cout <<"Welcome, " <<name <<"." <<endl;
      cout <<" ------------- Schedule ------------- " <<endl;
      t.storeInfo(t.boolArray[i]);

    }

    if(input == "3")
    {
      cout << "These are the events that you could attend" << endl;
      t.scheduleArray();
      user_recommendations <<"Have a great time " <<name <<"!" <<endl;
    }

}

}
