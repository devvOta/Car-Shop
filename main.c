#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void editFile(char *filename, char *newContent) {
    FILE *fp;
    char buffer[1000];
    int len;

    fp = fopen(filename, "w"); // open file for writing

    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }

    // write new content to file
    fprintf(fp, "%s", newContent);

    fclose(fp); // close file
    printf("File %s successfully edited!\n", filename);
}
void appendToFile(char *filename, char *newContent) {
    FILE *fp;

    fp = fopen(filename, "a"); // open file for appending

    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }

    // write new content to file
    fprintf(fp, "%s", newContent);

    fclose(fp); // close file
    printf("New content successfully appended to file %s!\n", filename);
}
struct User {
    char name[50];
    char password[50];
    char type[10];
};

void saveUserToFile(struct User user) {
    FILE *fp;

    fp = fopen("users.txt", "a"); // open file for appending

    if (fp == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    // write user to file
    fprintf(fp, "%s %s %s\n", user.name, user.password, user.type);

    fclose(fp); // close file
    printf("User saved to file!\n");
}
struct User findUserByName(char *filename, char *name) {
    FILE *fp;
    char line[150];
    struct User user = {"", "", ""};

    fp = fopen(filename, "r"); // open file for reading

    if (fp == NULL) {
        printf("Failed to open file.\n");
        return user;
    }

    // read each line of the file
    while (fgets(line, 150, fp)) {
        // parse the line into name, password, and type
        char *token = strtok(line, " ");
        strcpy(user.name, token);
        token = strtok(NULL, " ");
        strcpy(user.password, token);
        token = strtok(NULL, " ");
        strcpy(user.type, token);

        // remove newline character from type string
        user.type[strcspn(user.type, "\n")] = 0;

        // check if the user's name matches the name we're looking for
        if (strcmp(user.name, name) == 0) {
            fclose(fp); // close file
            return user; // return the user structure
        }
    }

    fclose(fp); // close file
    printf("User not found.\n");
    return user;
}
int main() {
    // char *filename = "example.txt";
    // char *newContent = "\nOk good now"; 

    // appendToFile(filename, newContent);

    // return 0;
  // create a user
    // struct User user1;
    // strcpy(user1.name, "Yassir");
    // strcpy(user1.password, "password123");
    // strcpy(user1.type, "client");
    
    // save user to file
    // saveUserToFile(user1);
  char *filename = "users.txt";
  struct User user = findUserByName(filename, "Yassir");
  printf("%s",user.password);
    return 0;
}
