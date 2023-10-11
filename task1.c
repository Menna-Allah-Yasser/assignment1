#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int isLoggedIn;
} User;

User users[MAX_USERS];
int userCount = 0;

int registerUser(const char* username, const char* password) {
    if (userCount >= MAX_USERS) {
        return 0;
    }

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return 0;
        }
    }

    User newUser;
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);
    newUser.isLoggedIn = 0;

    users[userCount] = newUser;
    userCount++;

    return 1;
}

User* login(const char* username, const char* password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            users[i].isLoggedIn = 1;
            return &users[i];
        }
    }

    return NULL;
}

void logout(User* user) {
    if (user != NULL) {
        user->isLoggedIn = 0;
    }
}

int main() {
    int choice;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                if (registerUser(username, password)) {
                    printf("Registration successful.\n");
                } else {
                    printf("Registration failed. Please try again.\n");
                }
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                User* loggedInUser = login(username, password);

                if (loggedInUser != NULL) {
                    printf("Login successful. Welcome, %s!\n", loggedInUser->username);
                } else {
                    printf("Invalid username or password. Please try again.\n");
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
