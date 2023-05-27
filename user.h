#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#define MAX_NAME_LENGTH 50


typedef struct {
  char first_name[MAX_NAME_LENGTH];
  char last_name[MAX_NAME_LENGTH];
  char password[MAX_NAME_LENGTH];
  int id;
} User;

void saveUser(User user[], int numCustomers);

void loadUser(User user[], int *numCustomers);

void deleteUser(User user[], int id, int *numUser);

void purchase_history(User log);
int isIdUnique(User user[], int numUsers, int id);
void Register(User user[], int *numuser);
User Login(User user[], int *numUser);

#endif
