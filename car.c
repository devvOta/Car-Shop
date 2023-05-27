#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "car.h"
// Procédure pour la recherche d'item
void browseProducts(Car car[], int numcar) {
  for(int i=0;i<numcar;i++){
    printf("%s ; id:%d ; quantity:%d ; price:%.2f\n",car[i].name,car[i].ref,car[i].quantity,car[i].price);
  }
}
// Procédure pour la sauvegarde d'item
void saveCar(Car car[], int numProducts) {
  FILE *file = fopen("car.txt", "w");
  if (file == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    exit(1);
  }
  for (int i = 0; i < numProducts; i++) {
    fprintf(file, "%s;%d;%d;%.2f;%s\n", car[i].name, car[i].ref,
            car[i].quantity, car[i].price, car[i].size);
  }
  fclose(file);
}
//Procédure pour le chargement de la voiture
void loadCar(Car car[], int *numProducts) {
  FILE *file = fopen("car.txt", "r");
  if (file == NULL) {
    printf("Fichier de produits introuvable.\n");
    return;
  }
  char line[256];
  int i = 0;
  while (fgets(line, sizeof(line), file)) {
    sscanf(line, "%[^;];%d;%d;%f;%s\n", car[i].name, &car[i].ref,
           &car[i].quantity, &car[i].price, car[i].size);
    i++;
  }
  *numProducts = i;
  fclose(file);
}
// Fonction place, permettant d'attribuer un ordre de grandeur entre les voitures
int place(Car car[], int nbrstock) {
  int count = 0;
  for (int i = 0; i < nbrstock; i++) {
    if (strcmp(car[i].size, "petit") == 0) {
      count = count + car[i].quantity;
    } else if (strcmp(car[i].size, "moyen") == 0) {
      count = count + 2 * car[i].quantity;
    } else if (strcmp(car[i].size, "grand") == 0) {
      count = count + 4 * car[i].quantity;
    }
  }
  return place_shoop - count;
}
// Fonction permettant de savoir si la réf d'une voiture est unique
int isReferenceUnique(Car car[], int numCar, int reference) {
  for (int i = 0; i < numCar; i++) {
    if (car[i].ref == reference) {
      return 0; // La référence n'est pas unique
    }
  }
  return 1; // La référence est unique
}
// Procédure permettant d'ajouter une voiture
void addCar(Car car[], int *numCar) {
  Car newCar;

  printf("Entrez le nom de la voiture: ");
  while (scanf("%s", newCar.name) != 1 ) {
        printf("Saisie invalide.  ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}

  // Vérifier que la référence est unique
  int reference;
  do {
    printf("Entrez la référence de la voiture: ");
    while (scanf("%d", &reference) != 1 ) {
        printf("Saisie invalide. Veuillez entrer un entier : ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}
    if (!isReferenceUnique(car, *numCar, reference)) {
      printf("La référence de voiture n'est pas unique. Veuillez choisir une "
             "autre référence.\n");
    }
  } while (!isReferenceUnique(car, *numCar, reference));

  newCar.ref = reference;

  printf("Entrez la quantité: ");
  while (scanf("%d", &newCar.quantity) != 1 ) {
        printf("Saisie invalide. Veuillez entrer un entier : ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}
  printf("Entrez le prix: ");
    while (scanf("%f", &newCar.price) != 1 ) {
        printf("Saisie invalide. Veuillez entrer un réel : ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}
  do{
    printf("Entrez la taille (petit/moyen/grand):\n ");
        scanf("%s", newCar.size);
        while (getchar() != '\n'); // Clear input buffer

        if (strcmp(newCar.size, "petit") != 0 && strcmp(newCar.size, "moyen") != 0 && strcmp(newCar.size, "grand") != 0) {
            printf("Saisie invalide.\n  ");
        }
  }while (strcmp(newCar.size, "petit") != 0 && strcmp(newCar.size, "moyen") != 0 && strcmp(newCar.size, "grand") != 0);
  int placeOccupied = 0;
  if (strcmp(newCar.size, "petit") == 0) {
    placeOccupied = newCar.quantity * 1;
  } else if (strcmp(newCar.size, "moyen") == 0) {
    placeOccupied = newCar.quantity * 2;
  } else if (strcmp(newCar.size, "grand") == 0) {
    placeOccupied = newCar.quantity * 4;
  }

  if (place(car, *numCar) - placeOccupied < 0) {
    printf("Le stock dépasse la capacité maximale du magasin. Veuillez saisir "
           "une quantité inférieure.\n");
    return;
  }

  car[*numCar] = newCar;
  *numCar = *numCar + 1;
}
// Procédure pour le réapprovisionnement
void resupply(Car car[], int numCar) {
  char name[MAX_NAME_LENGTH];
  int reference;
  int quantityToAdd;

  for (int i = 0; i < numCar; i++) {
    printf("car: %s ; id: %d ; quantité: %d\n", car[i].name, car[i].ref,
           car[i].quantity);
  }

  printf("saisissez la référence du produit pour lequel vous voulez ajouter du "
         "stock: ");
  while (scanf("%d", &reference) != 1 ) {
        printf("Saisie invalide. Veuillez entrer un entier : ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}

  int found = 0;

  // Recherche du produit par nom ou référence
  for (int i = 0; i < numCar; i++) {
    if (car[i].ref == reference) {
      printf("Entrez la quantité à ajouter: ");
     while (scanf("%d", &quantityToAdd) != 1 ) {
        printf("Saisie invalide. Veuillez entrer un entier : ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}

      int placeOccupied = 0;
      if (strcmp(car[i].size, "petit") == 0) {
        placeOccupied = quantityToAdd * 1;
      } else if (strcmp(car[i].size, "moyen") == 0) {
        placeOccupied = quantityToAdd * 2;
      } else if (strcmp(car[i].size, "grand") == 0) {
        placeOccupied = quantityToAdd * 4;
      }

      if (place(car, numCar) - placeOccupied < 0) {
        printf("Le stock dépasse la capacité maximale du magasin. Veuillez "
               "entrer une quantité inférieure.\n");
        return;
      }

      car[i].quantity += quantityToAdd;
      found = 1;
      break;
    }
  }

  // Affichage du résultat
  if (found) {
    printf("Le produit a été réapprovisionné avec succès.\n");
  } else {
    printf("No matching product found.\n");
  }
}
// Procédure pour la recherche d'information concernant une voiture
void searchInformation(Car car[], int numCar) {
  char name[MAX_NAME_LENGTH];
  printf("Entrez le nom de la voiture dont vous voulez connaitre le stock: ");
  while (scanf("%s", name) != 1 ) {
        printf("Saisie invalide.  ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}

  for (int i = 0; i < numCar; i++) {
    if (strcmp(car[i].name, name) == 0) {
      printf("There are %d of %s left.\n", car[i].quantity, car[i].name);
      return;
    }
  }

  printf("Car not found.\n");
}

