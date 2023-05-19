#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 40

struct Client {
    char nom[50];
    char prenom[50];
    char id[50];
};

struct User {
    char username[50];
    char lastname[50];
    char firstname[50];
    char password[100];
    char id[50];
    char type[50];
};

struct Car{
  int num_ref;
  char name;
  int quantity;
  int price;
  int size;
}Car; 

void Resupply(){
  printf("Which car you want to add ?\n");
  FILE*f;
  f=fopen("car.txt", "r");
   if (f==NULL){
    printf("Error, try again");
  }
  fprintf (f, "ref :%d; name: %s; quantity: %d; price:%d; size:%d \n" , Car.num_ref, &Car.name,Car.quantity,Car.price,Car.size);
}

void initializeUser(struct User* user) {
    memset(user, 0, sizeof(struct User));
}

void login(struct User* user) {
    printf("Enter your username: ");
    fgets(user->username, sizeof(user->username), stdin);
    user->username[strcspn(user->username, "\n")] = '\0'; // Remove newline character
}
void viewCar(){
  FILE* f;
  char c;
   f = fopen("car.txt","r");
  if (f==NULL){
    printf("Error, try again");
  }
    while((c=fgetc(f))!=EOF){
      printf("%c",c);
    }
}

void AddCart() {
    
    FILE* fichier = fopen("AddCart.txt", "a");
    if (fichier == NULL) {
        printf("Error when opening the file, try again.\n");
        exit(1); // or any other appropriate action
    }

    printf("Choose another car :\n");
     FILE* f;
  char c;
   f = fopen("car.txt","r");
  if (f==NULL){
    printf("Error, try again");
  }
    while((c=fgetc(f))!=EOF){
      printf("%c",c);
    }

    int choice;
    printf("Enter your choice : ");
    scanf("%d", &choice);

    const char* chaine = NULL;

    switch (choice) {
        case 1:
            chaine = "AUDI-rs6";
            break;
        case 2:
            chaine = "BMX-M3copet";
            break;
        case 3:
            chaine = "LAMBORGINI-URUS";
            break;
        case 4:
            chaine = "FERRARI-5T";
            break;
        case 5:
            chaine = "CLIO2-ABBES";
            break;
        default:
            printf("invalid choice.\n");
            fclose(fichier);
            return;
    }
   int rec;
  printf("Do you want to buy something else ?\n ");
  printf("If yes press 1, otherwise press 2\n ");
    scanf("%d", &rec);
    switch(rec){
      case 1:
      AddCart();
      case 2:
    fprintf(fichier, "%s\n", chaine);
    fclose(fichier);
    }
}


void managementMode() {
    // Code for management mode
    printf("You are in management mode.\n");
    printf("Welcome back, %s!\n");
    printf("=========================================\n");
    printf("              Car Shop              \n");
    printf("=========================================\n");
    printf("Available options:\n");
    printf("1. Resupply\n");
    printf("2. The products\n");
    printf("3. Favourite products of the month\n");
    printf("4. The Customers\n");
    printf("5. Logout\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            Resupply();
            // Add code for browsing products
            break;
        case 2:
            printf("See the most popular purchases...\n");
            // Add code for adding to cart
            break;
        case 3:
            // Add code for viewing cart
            viewCar();
            break;
        case 4:
            printf("Help area...\n");
            // Add code for checkout
            break;
        case 5:
            printf("Logging out...\n");
            // Add code for logging out
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void clientMode() {
    // Code for client mode
    printf("You are in client mode.\n");
    printf("Welcome to the Car shop, %s!\n");
    printf("=========================================\n");
    printf("              Car Shop              \n");
    printf("=========================================\n");
    printf("Available options:\n");
    printf("1. Browse Products\n");
    printf("2. Add to Cart\n");
    printf("3. View Cart\n");
    printf("4. View history\n");
    printf("5. Logout\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Browsing products...\n");
            // Add code for browsing products
            break;
        case 2:
            AddCart();
            // Add code for adding to cart
            break;
        case 3:
            viewCar();
            break;
        case 4:
            printf("Checking out...\n");
            // Add code for checkout
            break;
        case 5:
            printf("Logging out...\n");
            // Add code for logging out
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void carMode(){
  printf("Choise one car to buy\n");
  
}


void saveUserData(struct User client) {
    // Generate the file name by concatenating the client ID with the ".txt" extension
    char nomFichier[100];
    strcpy(nomFichier, client.lastname);
    strcat(nomFichier, ".txt");

    // Open the file in write mode
    FILE* fichier = fopen(nomFichier, "w");

    if (fichier == NULL) {
        printf("Error, file not created, try again.\n");
        return;
    }

    // Write the customer information to the file
    fprintf(fichier, "Last name: %s\n", client.lastname);
    fprintf(fichier, "First name: %s\n", client.firstname);
    fprintf(fichier, "ID: %s\n", client.id);
    fprintf(fichier,"Password: %s ",client.password);
    // Fermer le fichier
    fclose(fichier);

    printf("The file for client %s has been successfully created.\n", client.id);
}

int main() {
    char mode[20];
    struct User user;

    printf("Welcome! Please enter your ID: ");
    fgets(user.id, sizeof(user.id), stdin);
    user.id[strcspn(user.id, "\n")] = '\0'; // Remove newline character

    printf("Please enter your firstname: ");
    fgets(user.firstname, sizeof(user.firstname), stdin);
    user.firstname[strcspn(user.firstname, "\n")] = '\0'; // Remove newline character

    printf("Please enter your lastname: ");
    fgets(user.lastname, sizeof(user.lastname), stdin);
    user.lastname[strcspn(user.lastname, "\n")] = '\0'; // Remove newline character

    printf("Please enter your password: ");
    fgets(user.password, sizeof(user.password), stdin);
    user.password[strcspn(user.password, "\n")] = '\0'; // Remove newline character
  
    printf("Please choose a mode (management/client): ");
    fgets(mode, sizeof(mode), stdin);
    mode[strcspn(mode, "\n")] = '\0'; // Remove newline character

    printf("Welcome, %s!\n", user.firstname);

    if (strcmp(mode, "management") == 0) {
        managementMode();
    } else if (strcmp(mode, "client") == 0) {
        clientMode();
    } else {
        printf("Invalid mode selected. Exiting...\n");
        return 1;
    }
      saveUserData(user); // Save user data to file

    return 0;
}
