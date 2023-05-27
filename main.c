#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "car.h"
#include "other.h"
#define MAX_CAR 100
#define MAX_USER 100

int main() {
  
  Car car[MAX_CAR];
  User user[MAX_USER];
  int numCar = 0;
  int numUser = 0;
  
  loadCar(car, &numCar);
  loadUser(user, &numUser);
  menu(car, numCar, user,numUser);
  return 0;
}
