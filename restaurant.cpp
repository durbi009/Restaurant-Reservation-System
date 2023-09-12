/*
- Lizbeth Durbin
- HW2
- 10/10/2019
- The purpose of this file is to implement all member functions of class Restaurant
- This is restaurant.cpp
*/
#include "restaurant.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


Restaurant::Restaurant() // default constructor definition
{

}
////////////////////////////////////////////////////////////////////////////////////////////////////
Restaurant::Restaurant(string rName,string rAddress,string rCity, string rType, int rCapacity) // overload constructor definition
{

  restaurantName = rName; // sets class attribute to passed variable
  restaurantAddress = rAddress;// sets class attribute to passed variable
  restaurantCity = rCity;// sets class attribute to passed variable
  restaurantType = rType;// sets class attribute to passed variable
  for (int i = 0; i <= 3; i++)
      {
	availableSeats[i] = rCapacity; // sets class attribute(at each individual element) to passed variable
      }
}
//////////////////////////////////////////////////////////////////////////////////////////////////

string Restaurant::getCity()const // get function for private class attribute
{
  return restaurantCity;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

string Restaurant::getType() const // get function for private class attribute

{
  return restaurantType;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int Restaurant::getSeats(int rTime) const // get function for private class attribute

{
  int i = rTime - 5;
  return availableSeats[i];
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int Restaurant::getavailableSeats(int t) const // get function for private class attribute

{
  return availableSeats[t];
}

////////////////////////////////////////////////////////////////////////////////////////////////////

string Restaurant::getName() const // get function for private class attribute

{
  return restaurantName;
} 

////////////////////////////////////////////////////////////////////////////////////////////////////


void Restaurant::print() const // print function for all attributes of specific class instance
{
  cout << left << setw(20) << restaurantName;
  cout << setw(20) << restaurantAddress;
  cout << setw(15) << restaurantCity;
  cout << setw(15) << restaurantType;
  cout << setw(15) << availableSeats[0];
  cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////


void Restaurant::printReservations() const // print function for all reservation element for specific class instance
{
  for (int i = 0; i < reservations.size(); i++)
    {
      reservations[i].printRes();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void Restaurant::getNewSeats(const int& rTime, int& newSeats) // mutator function for element in availableSeats array
{
  availableSeats[rTime-5]=newSeats; // will take value of element, which stands in for time slots at restaurant, and sets new value of element to newSeats
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void Restaurant::MakeReservation(const Reservation& tmp)
{
  reservations.push_back(tmp); // pushes back reservation vector with pass tmp reservation object
}
