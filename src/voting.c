#include <stdio.h>
#include <string.h>

#define MAX_LINE 100

int has_voted(char *username) {
    FILE *file = fopen("votes.txt", "r");
    if (!file) {
        return 0;  // If file doesn't exist, no votes yet
    }

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, username) != NULL) {  // Check if username exists
            fclose(file);
            return 1;  // User has already voted
        }
    }
    
    fclose(file);
    return 0;  // User has not voted
}

void vote(char *username) {
    if (has_voted(username)) {
        printf("You have already voted! Duplicate votes are not allowed.\n");
        return;
    }

    int choice;
    printf("Select a candidate to vote for:\n1. Alice\n2. Bob\n3. Charlie\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    FILE *file = fopen("votes.txt", "a");
    if (!file) {
        printf("Error opening vote file.\n");
        return;
    }

    fprintf(file, "%s voted for candidate %d\n", username, choice);
    fclose(file);

    printf("You have voted successfully!\n");
}
