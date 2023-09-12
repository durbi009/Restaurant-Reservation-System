#include <iostream>
#include "Restaurantreservations.h"
#include "reservation.h"
#include "restaurant.h"
using namespace std;

int main()
{
  RestaurantReservations R1;

  R1.ProcessTransactionFile("restaurantFile.txt");


  return 0;

}
