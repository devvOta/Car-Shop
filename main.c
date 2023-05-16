#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUTTONS 5

struct User {
    char lastname[50];
    char firstname[50];
    char password[100];
    char id[50];
    char type[50];
    char username[50];
};
void initializeUser(struct User* user) {
    memset(user, 0, sizeof(struct User));
}

void managementMode() {
    // Code for management mode
    printf("You are in management mode.\n");
    // Add your management mode functionality here
}

void clientMode() {
    // Code for client mode
    printf("You are in client mode.\n");
    // Add your client mode functionality here
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
struct UserChoice {
    char Choice[50];
    bool isLoginSelected;
    bool isRegisterSelected;
};

void initializeChoice(struct UserChoice* choice) {
    choice->isLoginSelected = false;
    choice->isRegisterSelected = false;
}

void selectLogin(struct UserChoice* choice, struct User* user) {
    choice->isLoginSelected = true;
    choice->isRegisterSelected = false;
    printf("Enter your username: ");
    fgets(user->username, sizeof(user->username), stdin);
    user->username[strcspn(user->username, "\n")] = '\0';
    printf("Enter your password: ");
    fgets(user->password, sizeof(user->password), stdin);
    user->password[strcspn(user->password, "\n")] = '\0';// Remove newline character
}

void welcomeInterface(struct User* user) {
    printf("Welcome, %s!\n", user);
    printf("This is the welcome interface.\n");
    // Add interface functionality here
}

void selectRegister(struct UserChoice* choice) {
    choice->isLoginSelected = false;
    choice->isRegisterSelected = true;
    printf("Register selected.\n");
}
void registerUser(struct User* user) {
    printf("Welcome! Please enter your ID: ");
    fgets(user->id, sizeof(user->id), stdin);
    user->id[strcspn(user->id, "\n")] = '\0'; // Remove newline character

    printf("Please enter your firstname: ");
    fgets(user->firstname, sizeof(user->firstname), stdin);
    user->firstname[strcspn(user->firstname, "\n")] = '\0'; // Remove newline character

    printf("Please enter your lastname: ");
    fgets(user->lastname, sizeof(user->lastname), stdin);
    user->lastname[strcspn(user->lastname, "\n")] = '\0'; // Remove newline character

    printf("Please enter your password: ");
    fgets(user->password, sizeof(user->password), stdin);
    user->password[strcspn(user->password, "\n")] = '\0'; // Remove newline character
}
void chooseType(struct User* user) {
    printf("Please choose a mode (management/client): ");
    fgets(user->type, sizeof(user->type), stdin);
    user->type[strcspn(user->type, "\n")] = '\0'; // Remove newline character

    if (strcmp(user->type, "management") == 0) {
        printf("Management mode selected.\n");
        // Call management mode function
    } else if (strcmp(user->type, "client") == 0) {
        printf("Client mode selected.\n");
        // Call client mode function
    } else {
        printf("Invalid mode selected. Exiting...\n");
    }
}


int main() {
    char type[20];
    struct User user;
    struct UserChoice choice;
    initializeChoice(&choice);
    initializeUser(&user);
    char input;
    scanf(" %c", &input);

    if (input == 'R' || input == 'r') {
        registerUser(&user);
        chooseType(&user);
    } else if (input == 'L' || input == 'l') {
        printf("Login to access the welcome interface.\n");
        // Perform authentication here (e.g., verify username and password)
        welcomeInterface(&user);
    } else if (input == 'Q' || input == 'q') {
        printf("Exiting...\n");
    } else {
        printf("Invalid choice.\n");
    }

    // Perform authentication here (e.g., verify username and password)

    // If authentication is successful
    welcomeInterface(&user);

    saveUserData(user); // Save user data to file

    return 0;
}

