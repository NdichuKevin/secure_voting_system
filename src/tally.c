#include <stdio.h>
#include <string.h>

void tally_votes() {
    FILE *file = fopen("votes.txt", "r");
    if (file == NULL) {
        printf("No votes have been cast yet.\n");
        return;
    }

    int votes[3] = {0}; // Alice, Bob, Charlie
    char line[100];
    int choice;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%*s %*s %*s %d", &choice) == 1) {
            if (choice >= 1 && choice <= 3) {
                votes[choice - 1]++;
            }
        }
    }
    fclose(file);

    printf("\nVote Tally:\n");
    printf("Alice: %d votes\n", votes[0]);
    printf("Bob: %d votes\n", votes[1]);
    printf("Charlie: %d votes\n", votes[2]);
}