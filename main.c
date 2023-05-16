#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct User {
    char lastname[50];
    char firstname[50];
    char password[100];
    char id[50];
    char type[50];
};

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

    printf("Welcome, %s!\n", user.firstname);

    printf("Please choose a mode (management/client): ");
    fgets(mode, sizeof(mode), stdin);
    mode[strcspn(mode, "\n")] = '\0'; // Remove newline character

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

