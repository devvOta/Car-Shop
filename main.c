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

void managementMode();
void clientMode();
void saveUserData(struct User user);

void Resupply(){
  printf("Which car you want to add ?\n");
  FILE*f;
  f=fopen("car.txt", "r");
   if (f==NULL){
    printf("Error, try again");
  }
  fprintf (f, "ref :%d; name: %s; quantity: %d; price:%d; size:%d \n" , Car.num_ref, &Car.name,Car.quantity,Car.price,Car.size);
}

void initializeUser() {
    struct User user;

    printf("Please enter your first name: \n");
    fgets(user.firstname, sizeof(user.firstname), stdin);
    user.firstname[strcspn(user.firstname, "\n")] = '\0';

    printf("Please enter your last name: \n");
    fgets(user.lastname, sizeof(user.lastname), stdin);
    user.lastname[strcspn(user.lastname, "\n")] = '\0';

    printf("Please enter your ID: \n");
    fgets(user.id, sizeof(user.id), stdin);
    user.id[strcspn(user.id, "\n")] = '\0';

    printf("Please enter your password: \n");
    fgets(user.password, sizeof(user.password), stdin);
    user.password[strcspn(user.password, "\n")] = '\0';

    strcpy(user.type, "client");  // Définition du type en tant que "client"

    printf("Welcome, %s!\n", user.firstname);

    if (strcmp(user.type, "management") == 0) {
        managementMode();
    } else if (strcmp(user.type, "client") == 0) {
        clientMode();
    } else {
        printf("Invalid type selected. Exiting...\n");
        return;
    }

    saveUserData(user);
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
    printf("Choose a car to add to the cart:\n");
    viewCar();

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    const char* carNames[] = {
        "AUDI-rs6",
        "BMX-M3copet",
        "LAMBORGHINI-URUS",
        "FERRARI-5T",
        "CLIO2-ABBES"
    };

    if (choice < 1 || choice > 5) {
        printf("Invalid choice.\n");
        return;
    }

    FILE* file = fopen("AddCart.txt", "a");
    if (file == NULL) {
        printf("Error opening the file, try again.\n");
        return;
    }
    fprintf(file, "%s\n", carNames[choice - 1]);
    fclose(file);
    printf("Car added to the cart!\n");
}

void resupply() {
    printf("Which car do you want to add?\n");
    struct Car car;
    printf("Enter the car reference number: ");
    scanf("%d", &car.num_ref);
    printf("Enter the car name: ");
    scanf("%s", car.name);
    printf("Enter the car quantity: ");
    scanf("%d", &car.quantity);
    printf("Enter the car price: ");
    scanf("%d", &car.price);
    printf("Enter the car size: ");
    scanf("%d", &car.size);

    FILE* file = fopen("car.txt", "a");
    if (file == NULL) {
        printf("Error opening the file, try again.\n");
        return;
    }
    fprintf(file, "ref: %d; name: %s; quantity: %d; price: %d; size: %d\n",
            car.num_ref, car.name, car.quantity, car.price, car.size);
    fclose(file);
    printf("Car added successfully!\n");
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
            AddCart();
            //code for browsing products
            break;
        case 2:
            viewCar();
            break;
        case 3:
            printf("Checking out...\n");
            // code for checkout
            break;
        case 4:
            printf("Logging out...\n");
            // code for logging out
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void carMode(){
  printf("Choose one car to buy\n");
  
}
void saveUserData(struct User client) {
     // Générer le nom du fichier en concaténant l'identifiant du client avec l'extension ".txt"
    char nomFichier[100];
    strcpy(nomFichier, client.lastname);
    strcat(nomFichier, ".txt");

    // Ouvrir le fichier en mode écriture
    FILE* fichier = fopen(nomFichier, "w");

    if (fichier == NULL) {
        printf("Erreur lors de la création du fichier.\n");
        return;
    }

    // Écrire les informations du client dans le fichier
    fprintf(fichier, "Nom: %s\n", client.lastname);
    fprintf(fichier, "Prénom: %s\n", client.firstname);
    fprintf(fichier, "Identifiant: %s\n", client.id);
    fprintf(fichier, "Mot de passe: %s\n ", client.password);
    fprintf(fichier, "Type: %s\n ", client.type);
    // Fermer le fichier
    fclose(fichier);

    printf("Le fichier pour le client %s a été créé avec succès.\n", client.id);
}

int login() {
    char filename[100];
    printf("Please enter your username: ");
    getchar();  // Consommer le caractère de nouvelle ligne restant

    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';
    strcat(filename, ".txt");

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 0;
    }

    char id[100];
    char password[100];
    char type[100];

    printf("Please enter your ID: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    printf("Please enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "ID:") != NULL) {
            char savedID[100];
            fgets(savedID, sizeof(savedID), file);
            savedID[strcspn(savedID, "\n")] = '\0';
            if (strcmp(savedID, id) == 0) {
                fgets(line, sizeof(line), file);
                if (strstr(line, "Password:") != NULL) {
                    char savedPassword[100];
                    fgets(savedPassword, sizeof(savedPassword), file);
                    savedPassword[strcspn(savedPassword, "\n")] = '\0';
                    if (strcmp(savedPassword, password) == 0) {
                        fgets(line, sizeof(line), file);
                        if (strstr(line, "type:") != NULL) {
                            fgets(type, sizeof(type), file);
                            type[strcspn(type, "\n")] = '\0';
                            fclose(file);
                            if (strcmp(type, "client") == 0) {
                                printf("Welcome, client!\n");
                                // Code pour l'interface client
                                
                                clientMode();
                            } else if (strcmp(type, "management") == 0) {
                                printf("Welcome, manager!\n");
                                // Code pour l'interface management
    
                                managementMode();
                            } else {
                                printf("Invalid user type.\n");
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    fclose(file);
    printf("Invalid ID or password.\n");
    return 0;
}


int main() {
    char mode[20];
    int choice;
    printf("Welcome to the Car Shop!\n");

    while (1) {
        printf("=========================================\n");
        printf("              Car Shop              \n");
        printf("=========================================\n");
        printf("Available options:\n");
        printf("1. Register\n");
        printf("2. Log in\n");
        printf("3. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initializeUser();
                break;
            case 2:
                if (login()) {
                    printf("Login successful!\n");
                    break;
                } else {
                    printf("Invalid username or password. Please try again.\n");
                    break;
                }
            case 3:
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
