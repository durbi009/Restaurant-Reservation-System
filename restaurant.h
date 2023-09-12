/*
- Lizbeth Durbin
- HW2
- 10/10/2019
- The purpose of this file to declare the class Restaurant, its variables, and its member functions
- This is restaurant.h
*/
#ifndef restaurant_h
#define restaurant_h

#include <iostream>
#include <vector>
#include <string>
#include "reservation.h"

using namespace std;

class Restaurant
{
 private:

  string restaurantName; // restaurant name
  string restaurantAddress; // restaurant address
  string restaurantCity; // restaurant city
  string restaurantType; // type of food served at restaurant
  int availableSeats [4]; // array holding number of available seats at specific time
  vector <Reservation> reservations; // list of reservations at this restaurant


 public:
  Restaurant(); // default constructor
  Restaurant(string rName,string rAddress,string rCity, string rType, int rCapacity); // overload constructor 
  string getCity() const; // get function for class attribute restaurantCity 
  string getType() const; // get function for class attribute restaurantType
  int getSeats(int rTime)const; // get function for class attribute availableSeats at element derived from passed attribute rTime
  string getName() const; // get function for class attribute restaurantName
  void print()const; // print function for Restaurant object
  void printReservations()const; // print function for reservation associated with class object
  void MakeReservation(const Reservation& tmp); // make reservation mutator function for creating new element in reservation vector
  void getNewSeats(const int& rTime, int& newSeats); // mutator function for number in specific availableSeats array, modified after a new reservation is created
  int getavailableSeats(int t)const; // get function for integer in specific element of availableSeats array

};
#endif
