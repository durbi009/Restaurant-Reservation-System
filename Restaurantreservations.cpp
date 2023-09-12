/*
Lizbeth Durbin
HW2
10/10/2019
The file implements all class member functions
This file is Restaurantreservations.cpp
*/

#include "Restaurantreservations.h"
#include "reservation.h"
#include "restaurant.h"
// this file has access to everything
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

RestaurantReservations::RestaurantReservations() // default
{
}

void RestaurantReservations::ProcessTransactionFile(string filename) // opens transaction file
{

  fstream fin; // creates in file stream
  string command; // string for first value of input in line of transaction file
  string rName,rAddress,rCity,rType; // creates local variables to pass into appropriate functions
  string cName,cPhone; // creates local variables to pass into appropriate functions
  int rCapacity, rTime, rGroup;  // creates local variables to pass into appropriate functions

  fin.open(filename); // open file stream
  while(fin >> command) // while there is code to read
    {
      
      if (command == "CreateNewRestaurant") 
	{
	  fin >> rName >> rAddress >> rCity >> rType >> rCapacity; // read into local variables

	  CreateNewRestaurant(rName,rAddress,rCity,rType,rCapacity); //call function and pass necessary variables
	}

      else if ( command == "PrintAllRestaurants")
	{
	  PrintAllRestaurants();//call function 
	}
      else if (command == "FindTable")
	{
	  fin >> rCity >> rType >> rGroup >> rTime; // read into local variables

	  FindTable(rCity,rType,rGroup,rTime);//call function and pass necessary variables
      	}
       
    else if (command == "PrintRestaurantReservations")
        {	
	  fin >> rName; // read into local variable
	  PrintRestaurantReservations(rName);//call function and pass necessary variables
	}
      
      else if (command == "MakeReservation")
	{
	  fin >> rName >> cName >> cPhone >> rGroup >> rTime; // read into local variables
	  MakeReservation(rName, cName, cPhone, rGroup, rTime);//call function and pass necessary variables
	}
      else if (command == "FindTableAtRestaurant")
	{
	  fin >> rName >> rGroup; // read into local variables
	  FindTableAtRestaurant(rName,rGroup);//call function and pass necessary variables
	}
    }
  fin.close(); // close file stream
}
////////////////////////////////////////////////////////////////////////////////////
void RestaurantReservations::CreateNewRestaurant (string rName, string rAddress, string rCity, string rType, int rCapacity) 
{
  Restaurant tmp(rName,rAddress,rCity,rType,rCapacity); //creates temporary resturant object using passed variables
  restaurants.push_back(tmp); // pushes tmp object into restaurants vector
}
////////////////////////////////////////////////////////////////////////////////////

void RestaurantReservations::FindTable(string rCity,string rType,int rGroup, int rTime)const // this searches for all restaurants in specific city, of a specific type, which can accomodate a certain size group at given time
 {
   string City[restaurants.size()]; // creates array of strings,this will temporarily hold city names for all restaurants 
   string type[restaurants.size()]; // creates array of strings, this will hold the types of all restaurants
   vector <string> available; // vector of strings, this holds names of restaurants which fit all criteria
   string name; // tmp hold for restaurantName
   int seats[4]; // tmp hold for # of available seats at all restaurants
   bool found = false; // boolean flag 
   for (int i = 0 ; i < restaurants.size(); i++)
     {

       City[i] = restaurants[i].getCity(); // set City element[i] to value of restaurantCity at restaurant[i]
       int x = City[i].find(rCity,0); // find if rcity attribute is found in city element[i]
       type[i] = restaurants[i].getType(); // set Type element[i] to value of restaurantType at restaurant[i]
       int y = type[i].find(rType,0);
       if ( x != City[i].npos && y != type[i].npos) // if both attributes are found at element [i], then continue
	 {
	   for (int y = 0; y < 4; y++)
	     {
	       seats[y]= restaurants[i].getSeats(rTime); // set seats at element[y] to value of availableSeats at restaurant[i]
	     }

	   name = restaurants[i].getName(); // name of restaurant is set to restaurantName at restaurant[i]
	   if (rGroup <= seats[y]) // if group size is less than availableSeats
	     {
	       found = true; // flag is now true
	       available.push_back(name); // push name of restaurnt into vector available
	     }
    	 }
     }
   if (found) // if flag is true (aka there are restaurants who fit criteria), continue
	 {
	   for (int i = 0; i < available.size(); i++)
	     {
	       cout << "You may reserve a table for " << rGroup << " at " << rTime << "pm" << " at " << available[i] <<  endl; // display results of search
	     }
	 }	
   if (!found && (available.size() == 0)) // oops couldnt find any
	 {
               cout << "There are no restaurants which can accomodate a group of your size. Sorry!" << endl;
	 }
 }
////////////////////////////////////////////////////////////////////////////////////
void RestaurantReservations::PrintAllRestaurants()const // this will print all elements in restaurant vector
{
  cout << left << setw(20) << " Name" << setw(20) << "Address" << setw(15) << "City" << setw(15) << "Type" << setw(15) << "Capacity" << endl;
  cout << "----------------------------------------------------------------------------------" << endl;
  for (int i = 0; i < restaurants.size(); i++)
    {
      restaurants[i].print(); // call print function for a restaurant[i] attributes
    }
}
////////////////////////////////////////////////////////////////////////////////////
void RestaurantReservations::PrintRestaurantReservations(string rName)const // this will print all reservations for a specific restaurant
{
  for (int i = 0; i < restaurants.size(); i++) // this for loop will search for specific restaurant
    {
      if (restaurants[i].getName() == rName) // if the name of restaurant matches passed variable rName
	{
	  cout << left << setw(15) << "Name" << setw(15) << "Phone#" << setw(15) << "GroupSize" << setw(15) << "Time" << setw(15) << "ResNum" << endl;
	  cout << "-------------------------------------------------------------" << endl;
	  restaurants[i].printReservations(); // calls printReservation function for object [i]
	  cout << endl;
	}
    }
}
////////////////////////////////////////////////////////////////////////////////////

void RestaurantReservations::MakeReservation(string rName, string cName, string cPhone, int rGroup, int rTime) 
{
  for (int i = 0; i < restaurants.size(); i++)
    {
      if (rName==restaurants[i].getName()) // if name of restaurant matches passed variable rName
	{
	  if (rGroup <= restaurants[i].getSeats(rTime)) // if size of groups is less than availableSeats at element [rTime-5]
	    {
	      Reservation tmp(cName,cPhone,rGroup,rTime); // creates tmp reservation object using overloaded constructor
	      restaurants[i].MakeReservation(tmp); // pass tmp into make reservation function of class restaurant
	      int newSeats = restaurants[i].getSeats(rTime)- rGroup; // find how many new Seats will be available after reservation is made
	      restaurants[i].getNewSeats(rTime,newSeats); // set availableSeats to newSeats using function call
	    }
	}
    }
}
////////////////////////////////////////////////////////////////////////////////////
void RestaurantReservations::FindTableAtRestaurant(string rName, int rGroup)const // this will search for room at a specific restaurant
{

  vector <int> aTime; // vetcor to hold available time slots in restaurant
  bool found = false; // boolean flag

  for (int i = 0; i < restaurants.size(); i++)
    {
      if (rName == restaurants[i].getName()) // will search for name 
	{
	  for (int t = 0; t < 4; t++)
	    {
	      if (rGroup <= restaurants[i].getSeats(t)) // will calculate if there are adequate seats available at index t of availableseats array at restaurant[i]
		{
		  found = true; // sets bool to true
		  int x = t+5; // add 5 to array to signify time slot
		  aTime.push_back(x); // push x value back into array
		}
	    }
	}
    }
	      if (found) // if seats were found
		{

		  cout << "You may reserve a table at " << rName << " for " << rGroup << " at "; // display passed variable and results of found time slots
		  for (int i = 0; i < aTime.size(); i++)
		    {
		      cout  << aTime[i] << "pm";
		    }
		  cout << endl;
		}
	      else if (!found) // if not enoug seats are found
		{
		  cout << "There is no availability at " << rName << " for a group size of " << rGroup << " . Sorry! " << endl;

		}
}

////////////////////////////////////////////////////////////////////////////////////
// woo its done
