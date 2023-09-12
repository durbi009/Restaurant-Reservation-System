/*
Lizbeth Durbin
HW2
10/10/2019
This file is to implement all class Reservation member functions
This file is reservation.cpp
*/

#include "reservation.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

long Reservation :: nextReservationNum = 100; // static variable which keeps track of all reservation by assigning each one a number, this line indicates the originalvalue is 100

Reservation::Reservation():ReservationNum(nextReservationNum) // default
{
}

Reservation::Reservation(string theName, string thePhone,int gSize,int rTime):ReservationNum(nextReservationNum) // overloaded
{
  nextReservationNum = nextReservationNum + 10 ; // increments static by 10 each time a new instance in created
  contactName = theName; // sets class attribute equal to passed value
  contactPhone = thePhone; // sets class attribute equal to passed value
  groupSize = gSize; // sets class attribute equal to passed value
  reservationTime = rTime; // sets class attribute equal to passed value
}

void Reservation::printRes() const // assesor function which will print class attributes
{
  cout << left << setw(15) << contactName << setw(15) << contactPhone << setw(15) << groupSize << setw(15) << reservationTime << setw(15) << ReservationNum << endl;	       
}

