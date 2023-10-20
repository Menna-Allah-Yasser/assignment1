#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    union {
        bool isActive;
        bool isLoggedIn;
    } status;
} User;

User users[MAX_USERS];
int numUsers = 0;

void registerUser() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached!\n");
        return;
    }

    User newUser;

    printf("Enter username: ");
    scanf("%s", newUser.username);

    printf("Enter password: ");
    scanf("%s", newUser.password);

    char Active[6];
    printf("Is the user active? (1 for true, 0 for false): ");
    scanf("%s", Active);


    char t1[]="true";
    char t2[]="1";

    if (strcmp(Active, "true") == 0 || strcmp(Active, "1") == 0){
        newUser.status.isActive = true;
        printf("%s\n","menna allah" );
    }
    else
        newUser.status.isActive = false;

    users[numUsers++] = newUser;

    printf("Registration successful!\n");
}

void loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    int i;
    for (i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            if (users[i].status.isActive) {
                users[i].status.isLoggedIn = true;
                printf("Login successful!\n");
            } else {
                printf("User is not active. Cannot log in.\n");
            }
            return;
        }
    }

    printf("Invalid username or password!\n");
}

int main() {
    int choice;

    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}
