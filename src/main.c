#include <stdio.h>
#include "auth.h"
#include "voting.h"  // Include this to declare vote()
#include "tally.h"

int main() {
    char username[20];
    int option;

    printf("Welcome to the Secure Voting System\n");
    printf("1. Vote\n");
    printf("2. View Vote Tally\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    if (option == 1) {
        if (authenticate_user(username)) {
            printf("User authenticated. Proceeding to voting...\n");
            vote(username);  // Now the compiler knows about vote()
        } else {
            printf("Authentication failed!\n");
        }
    } else if (option == 2) {
        tally_votes();
    } else {
        printf("Invalid option. Exiting.\n");
    }

    return 0;
}
