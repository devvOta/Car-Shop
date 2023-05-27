#ifndef OTHER_H
#define OTHER_H
#define MAX_NAME_LENGTH 50
#include "car.h"
#include "user.h"


void buyCar(Car car[], int numCar, User user[], int numUser, User log);

void managementMode(Car car[], int numCar, User user[], int numUser, int id) ;
void clientMode(Car car[], int numCar, User user[], int numUser,User log);
void UserMode(Car car[],int numCar,User user[], int numUser);
void menu(Car car[],int numCar,User user[], int numUser);
#endif
