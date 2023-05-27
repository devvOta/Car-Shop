#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "user.h"


// Procédure pour sauvegarder les informations de l'utilisateur
void saveUser(User user[], int numCustomers) {
  FILE *file = fopen("user.txt", "w");
  if (file == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    exit(1);
  }
  for (int i = 0; i < numCustomers; i++) {
    fprintf(file, "%s;%s;%s;%d\n", user[i].first_name, user[i].last_name,
            user[i].password, user[i].id);
  }
  fclose(file);
}
// Procédure pour charger les informations de l'utilisateur
void loadUser(User user[], int *numCustomers) {
  FILE *file = fopen("user.txt", "r");
  if (file == NULL) {
    printf("Fichier de clients introuvable.\n");
    return;
  }
  char line[256];
  int i = 0;
  while (fgets(line, sizeof(line), file)) {
    sscanf(line, "%[^;];%[^;];%[^;];%d\n", user[i].first_name,
           user[i].last_name, user[i].password, &user[i].id);
    i++;
  }
  *numCustomers = i;
  fclose(file);
}
// Procédure pour supprimer un utilisateur
void deleteUser(User user[], int id, int *numUser) { 
  int s=id;
  
  FILE *file = fopen("user.txt", "r");
  FILE *tempFile = fopen("temp.txt", "w");
  
  if (file == NULL || tempFile == NULL) {
    printf("Erreur lors de l'ouverture du fichier.");
    return;
  }
  
  int i;
  for (i = 0; i < *numUser; i++) {
    if (user[i].id == s) {
     
      continue;
    }
    fprintf(tempFile, "%s;%s;%s;%d\n", user[i].first_name, user[i].last_name,
            user[i].password, user[i].id);
  
  }
  remove("user.txt");
  rename("temp.txt", "user.txt");
  *numUser = *numUser - 1;
   fclose(file);
  fclose(tempFile);
}
// Procédure pour l'historique d'achat
void purchase_history(User log) {
    char fileName[100];
    sprintf(fileName, "%d.txt", log.id);
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier d'historique d'achat.\n");
        return;
    }

    char lines[3][256];
    int lineCount = 0;

    // Parcourir le fichier et stocker les 3 dernières lignes dans le tableau
    char line[256];
    while (fgets(line, 256, file) != NULL) {
        strcpy(lines[lineCount % 3], line);
        lineCount++;
    }

    fclose(file);

    // Afficher les 3 dernières lignes d'achat
    int i;
    for (i = 0; i < 3; i++) {
        printf("%s", lines[(lineCount - 3 + i) % 3]);
    }
}
int isIdUnique(User user[], int numUsers, int id) {
  for (int i = 0; i < numUsers; i++) {

    if (user[i].id == id) {
      return 0; // L'id n'est pas unique
    }
  }
  return 1; // L'id est unique
}
// Procédure pour l'inscription 
void Register(User user[], int *numuser) {
  User newuser;
  printf("=== Ajout d'un client ===\n");
  printf("Prénom : ");
  while (scanf("%s", newuser.first_name) != 1 ) {
        printf("Saisie invalide.  ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}
  printf("Nom : ");
    while (scanf("%s", newuser.last_name) != 1 ) {
        printf("Saisie invalide.  ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}
  printf("Saisir votre mot de passe : ");
    while (scanf("%s", newuser.password) != 1 ) {
        printf("Saisie invalide.  ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}
do {
    printf("Saisir votre identifiant :\n ");
    if (scanf("%d", &newuser.id) != 1) {
        printf("Veuillez saisir un identifiant entier.\n");
        while (getchar() != '\n');  // Vider le tampon d'entrée pour éviter une boucle infinie
    }
    else if (isIdUnique(user, *numuser, newuser.id) == 0) {
        printf("Identifiant déjà utilisé. Veuillez en saisir un autre.\n");
    }
} while (!isIdUnique(user, *numuser, newuser.id) || getchar() != '\n');

  // Ajouter le nouvel utilisateur à la liste
  user[*numuser] = newuser;
  (*numuser)++;

  printf("Client ajouté avec succès.\n");
}
User Login(User user[], int *numUser) {
  User login;
  printf("Saisissez votre prénom :\n");
    while (scanf("%s", login.first_name) != 1 ) {
        printf("Saisie invalide.  ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}
  printf("Saisissez votre nom :\n");
    while (scanf("%s", login.last_name) != 1 ) {
        printf("Saisie invalide.  ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}
    printf("Saisissez votre id :\n");
    while (scanf("%d", &login.id) != 1 ) {
        printf("Saisie invalide.  ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}
  printf("Saisissez votre mot de passe :\n");
 
    while (scanf("%s", login.password)!= 1 ) {
        printf("Saisie invalide.  ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}

  for (int i = 0; i < *numUser; i++) {
    if (strcmp(user[i].first_name, login.first_name) == 0 &&
        strcmp(user[i].last_name, login.last_name) == 0 &&
        strcmp(user[i].password, login.password) == 0 &&
        user[i].id==login.id)  {
      printf("Bonjour, heureux de vous revoir %s %s\n", user[i].first_name,
             user[i].last_name);
      return user[i];
      
    }
  }

  printf("Identifiant ou mot de passe incorrect, assurez vous d'avoir un compte\n");
int choice;
printf("1.Recommencez\n");
printf("2.Ou creer un compte\n");
  while (scanf("%d",&choice) != 1 ) {
        printf("Saisie invalide. Veuillez entrer un entier : ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}
  while(choice>2 || choice<1){
  printf("Saisie invalide.\n");
 printf("1.Recommencez\n");
printf("2.Ou creer un compte\n");
  while (scanf("%d",&choice) != 1 ) {
        printf("Saisie invalide. Veuillez entrer un entier : ");
        while (getchar() != '\n'); // Vide le tampon d'entrée
}
  }
switch(choice){
  case 1:
    Login(user, numUser);
  break;
  case 2:
  Register(user,numUser);
  break;
  
}
}






