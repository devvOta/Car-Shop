#ifndef CAR_H
#define CAR_H
#define MAX_NAME_LENGTH 50
#define place_shoop 5000

typedef struct {
  char name[MAX_NAME_LENGTH];
  int ref;
  int quantity;
  float price;
  char size[10];
} Car;


void browseProducts(Car car[], int numcar); 
void saveCar(Car car[], int numProducts);
void loadCar(Car car[], int *numProducts);
int place(Car car[], int nbrstock) ;
int isReferenceUnique(Car car[], int numCar, int reference);
void addCar(Car car[], int *numCar) ;
void resupply(Car car[], int numCar);
void searchInformation(Car car[], int numCar);


#endif
