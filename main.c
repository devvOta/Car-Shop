#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char username[50];
    char lastname[50];
    char firstname[50];
    char password[100];
    char id[50];
    char type[50];
};

void initializeUser(struct User* user) {
    memset(user, 0, sizeof(struct User));
}

void login(struct User* user) {
    printf("Enter your username: ");
    fgets(user->username, sizeof(user->username), stdin);
    user->username[strcspn(user->username, "\n")] = '\0'; // Remove newline character
}


void managementMode() {
    // Code for management mode
    printf("You are in management mode.\n");
    printf("Welcome back, %s!\n");
    printf("=========================================\n");
    printf("              Car Shop              \n");
    printf("=========================================\n");
    printf("Available options:\n");
    printf("1. Browse Products\n");
    printf("2. Add to Cart\n");
    printf("3. View Cart\n");
    printf("4. Checkout\n");
    printf("5. Logout\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("See the missing products...\n");
            // Add code for browsing products
            break;
        case 2:
            printf("See the most popular purchases...\n");
            // Add code for adding to cart
            break;
        case 3:
            printf("The users...\n");
            // Add code for viewing cart
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
    printf("4. Checkout\n");
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
            printf("Adding to cart...\n");
            // Add code for adding to cart
            break;
        case 3:
            printf("Viewing cart...\n");
            // Add code for viewing cart
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

void saveUserData(struct User user) {
    FILE *fp;
    fp = fopen("users.txt", "a"); // open the file in append mode

    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fprintf(fp, "%s %s\n", user.firstname, user.password);
    fclose(fp);

    printf("User data saved successfully.\n");
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
