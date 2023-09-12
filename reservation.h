/*
Lizbeth Durbin 
HW2
10/10/2019
This file defines class Reservation, all its attributes, as well as member functions
This file is reservation.h
*/

#ifndef reservation_h
#define reservation_h

using namespace std;

#include <iostream>
#include <string>
#include <vector>


class Reservation
{
  static long nextReservationNum; // initialize it to 100 and increment it by 10

 private:

  string contactName; 
  string contactPhone; 
  int groupSize; 
  int reservationTime; // reservation time which could be 5, 6, 7 or 8
  const long ReservationNum; // reservation number which is set to the value of nextReservationNum

 
 public:
  Reservation(); // default constructor
  Reservation(string contactName, string contactPhone,int groupSize,int reservationTime); // overloaded constructor
  void printRes() const; // print function for information of specific reservation 

};

#endif
