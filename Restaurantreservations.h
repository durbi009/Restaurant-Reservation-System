/*
Lizbeth Durbin
HW2
10/10/2019
This file declares class RetaurantReservations, a vector of restaurants, and all class member functions
This file is RestaurantReservations.h
*/
#ifndef restaurantreservations_h
#define restaurantreservations_h

#include <iostream>
#include <vector>
#include <string>
#include "restaurant.h" 
#include "reservation.h"
// this file has access to all other .h files used in this assignment
class RestaurantReservations
{

 private:
  vector <Restaurant> restaurants; // vector of all restaurants

 public:
  RestaurantReservations(); // default
  void ProcessTransactionFile(string fileName); // this function will open txt file used which holds all commands
  void CreateNewRestaurant(string rName, string rAddress, string rCity, string rType, int rCapacity);  // this creates new element in restaurant vector
  void FindTable(string rCity, string rType, int rGroup, int rTime)const; // this looks for all restaurants which fit certain criteria
  void PrintAllRestaurants()const; // this prints entire restaurants vector
  void PrintRestaurantReservations(string rName)const;// this prints all reservations associated with each restaurant
  void MakeReservation(string rName, string cName, string cPhone, int rGroup, int rTime); // this will create new reservation in restuarant
  void FindTableAtRestaurant(string rName, int rGroup)const; 
};

#endif
