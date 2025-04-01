#include <stdio.h>
#include <string.h>
#include "../include/auth.h"

#define USERNAME "admin"
#define PASSWORD "securepass"

int authenticate_user(char *username) {
    char input_user[20], input_pass[20];

    printf("Enter username: ");
    scanf("%s", input_user);
    printf("Enter password: ");
    scanf("%s", input_pass);

    if (strcmp(input_user, USERNAME) == 0 && strcmp(input_pass, PASSWORD) == 0) {
        strcpy(username, input_user);  // Store authenticated username
        return 1;  // Authentication successful
    }

    return 0;  // Authentication failed
}
