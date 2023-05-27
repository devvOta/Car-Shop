#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "other.h"




// Procédure pour acheter une voiture
void buyCar(Car car[], int numCar, User user[], int numUser, User log) {
    int id;
    int quantite;
    float price_total=1;
  
    printf("Entrez la référence du produit que vous souhaitez acheter : ");
      while (scanf("%d", &id) != 1 ) {
        printf("Saisie invalide. Veuillez entrer un entier : ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}

    int i,choice;
  
    for (i = 0; i < numCar; i++) {
        if (car[i].ref == id) {
            printf("Entrez la quantité que vous souhaitez acheter : ");
             while (scanf("%d", &quantite) != 1 ) {
        printf("Saisie invalide. Veuillez entrer un entier : ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}

            if (quantite <= car[i].quantity) {
                car[i].quantity -= quantite;
              price_total=car[i].price*quantite;
                printf("Achat effectué avec succès.\n");
            } else {
                printf("La quantité demandée est supérieure à la quantité disponible.\n");
  printf("1.supprimer votre compte\n");
  printf("2.Revenir dans le mode client\n");
      printf("Votre choix:\n");
    while (scanf("%d",&choice) != 1 ) {
        printf("Saisie invalide. Veuillez entrer un entier : ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}
              if(choice==1){
                char filename[100];
              sprintf(filename, "%d.txt",log.id);
              deleteUser(user,log.id, &numUser);
                remove(filename);
                printf("Votre compte a été supprimer avec succés");
                return ;
              }
                else if(choice==2){
                 clientMode(car,  numCar, user,  numUser,  log);
                }
             else{
               printf("choix invalide \n");
               clientMode(car,  numCar, user,  numUser,  log);
             }
            }
        
            // Ouvrir le fichier d'historique d'achat en mode append
            char fileName[100];
            sprintf(fileName, "%d.txt", log.id);
            FILE *file = fopen(fileName, "a");
            if (file == NULL) {
                printf("Erreur lors de l'ouverture du fichier d'historique d'achat.\n");
                return;
            }

            // Écrire les détails de l'achat à la fin du fichier d'historique d'achat
          float t;
          t=car[i].price*quantite;
            fprintf(file, "Nom: %s, Prix: %.2f, Quantité: %d\n", car[i].name,t, quantite);

            fclose(file);
            printf("Le prix total est de %.2f€",price_total);
            printf("Achat effectué avec succès. L'historique d'achat a été mis à jour.\n");
            return;
        }
    }

    printf("Le produit avec la référence %d n'a pas été trouvé.\n", id);
}



// Procédure le mode gestion
void managementMode(Car car[], int numCar, User user[], int numUser, int id) {
  printf("Vous êtes dans le mode Administrateur.\n");
  printf("\n------------------------------\n");
  printf("   Produits dont le restockage est impératif\n");
  printf("------------------------------\n");

  // Afficher les produits avec un stock de 0
  printf("Produits avec 0 stocks:\n");
  int hasZeroStock = 0;
  for (int i = 0; i < numCar; i++) {
    if (car[i].quantity == 0) {
      printf("- %s\n", car[i].name);
      hasZeroStock = 1;
    }
  }
  if (!hasZeroStock) {
    printf("Aucun produit à 0 stocks.\n");
  }
  // Tri des voitures en fonction du stock (ordre croissant)
  for (int i = 0; i < numCar - 1; i++) {
    for (int j = 0; j < numCar - i - 1; j++) {
      if (car[j].quantity > car[j + 1].quantity) {
        Car temp = car[j];
        car[j] = car[j + 1];
        car[j + 1] = temp;
      }
    }
  }

  // Afficher les 5 voitures avec le stock le plus bas
  printf("\n5 Voitures avec un stock faible :\n");
  int lowStockCount = 0;
  for (int i = 0; i < numCar && lowStockCount < 5; i++) {
    if (car[i].quantity > 0) {
      printf("- %s (Stock: %d)\n", car[i].name, car[i].quantity);
      lowStockCount++;
    }
  }
  if (lowStockCount == 0) {
    printf("Aucune voiture avec un stock faible.\n");
  }

  printf("Il reste %d place ", place(car, numCar));
  printf("\n--------------------------------\n");
  printf("1. Ajouter des produits\n");
  printf("2. Réapprovisionnement\n");
  printf("3. Savoir le stock de produit par son nom\n");
  printf("4.Retour\n");
  int choice;
  printf("Entrez votre choix:\n ");
  if (scanf("%d", &choice) != 1) {
    printf("Choix invalide. Veuillez entrer un entier.\n");

    // Vider le flux d'entrée pour les caractères supplémentaires
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    managementMode(car, numCar, user, numUser, id);
  } else {
    switch (choice) {
    case 1:
      addCar(car, &numCar);
      saveCar(car, numCar);
      managementMode(car, numCar, user, numUser, id);
      break;
    case 2:
      resupply(car, numCar);
      saveCar(car, numCar);
      managementMode(car, numCar, user, numUser, id);
      break;
    case 3:
      searchInformation(car, numCar);
      managementMode(car, numCar, user, numUser, id);
      break;
      case 4:
      return;
      break;    
  
    default:
      printf("Invalid choice.\n");
      managementMode(car, numCar, user, numUser, id);

      break;
    }
  }
}
// Procéduree pour le mode client
void clientMode(Car car[], int numCar, User user[], int numUser,User log) {
  // Code for client mode
  printf("Vous êtes dans le mode Client.\n");
  printf("Bievenue au Car Shop!\n");
  printf("=========================================\n");
  printf("              Car Shop              \n");
  printf("=========================================\n");
  printf("Available options:\n");
  printf("1. Voir nos produits !\n");
  printf("2. Achetez un (ou des) produit(s)\n");
  printf("3. Voir votre historique d'achats !\n");
  printf("4. Se déconnecter\n");

  int choice;
  printf("Entrez votre choix: ");
  if (scanf("%d", &choice) != 1) {
    printf("Choix invalide. Veuillez entrer un entier.\n");

    // Vider le flux d'entrée pour les caractères supplémentaires
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
clientMode(car, numCar, user, numUser,log);
  }
  switch (choice) {
  case 1:
    printf("Voir nos produits !...\n");
    browseProducts(car,  numCar);
    clientMode(car, numCar, user, numUser,log);

    break;
  case 2:
    printf("Achetez...\n");
    buyCar(car, numCar, user, numUser,log);
    saveCar(car,numCar);

    break;
  case 3:
    printf("Voir votre historique d'achats...\n");
    purchase_history(log);
    break;
  case 4:
     return;
    break;
    default:
    printf("Choix invalide. Veuillez reesayez\n");
        clientMode(car, numCar, user, numUser,log);

    break;
  }  
}

//Procédure pour le mode utilisateur
void UserMode(Car car[],int numCar,User user[], int numUser) {

  printf("1.S'inscrire\n");
  printf("2.Se connecter\n");
  printf("3.Retour\n");

  int choice; // Fonction pour le choix
  printf("Entrez votre choix: ");
  if (scanf("%d", &choice) != 1) {
    printf("Choix invalide. Veuillez entrer un entier.\n");

    // Vider le flux d'entrée pour les caractères supplémentaires
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    UserMode(car,numCar,user, numUser);
}
   User log;

  switch (choice) {
  case 1:
    Register(user, &numUser);
    saveUser(user, numUser);
    UserMode(car,numCar,user, numUser);
    break;
  case 2:
   log =Login(user, &numUser);
  clientMode(car,numCar,user, numUser, log);
    break;
    case 3:
    return;
    break;
  default:
    printf("Choix invalide.\n");
        UserMode(car,numCar,user, numUser);

    break;
  }
}

// Procédure pour le mode d'intéraction (menu)
void menu(Car car[],int numCar,User user[], int numUser){
   int id;
   int choice;
while(1){
  printf("\n------------------------------\n");
  printf("     Welcome to Car Shop");
  printf("\n------------------------------\n");
  printf("1.MANAGEMENT MODE\n");
  printf("2.BUY MODE\n");
  printf("3.exit\n");
  printf("You choice:");
  do {
    if (scanf("%d", &choice) != 1) {      
    printf("Choix invalide. Veuillez entrer un entier.\n");

    // Vider le flux d'entrée pour les caractères supplémentaires
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    }
    if (choice < 1 || choice > 3) {
      printf(" Please enter a number between 1 and 3: ");
    }
  } while (choice < 1 || choice > 3);

  switch (choice) {
  case 1:
    managementMode(car, numCar, user, numUser, id);
    break;
  case 2:
    UserMode(car,numCar,user, numUser);
    break;
  case 3:
    printf("Au revoir, à bientôt!\n");
    exit(1);
  
  }
}
}