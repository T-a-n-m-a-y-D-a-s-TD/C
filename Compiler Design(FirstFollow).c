#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAX_SYMBOLS 50
#define MAX_RULES 50

// Structure for grammar rules
typedef struct {
    char lhs;
    char rhs[MAX][MAX_SYMBOLS]; // Right-hand side can have multiple symbols
    int rhs_count; // Number of rules for a given left-hand side
} Production;

Production grammar[MAX_RULES];
int prod_count = 0;

// First and Follow sets
char first[MAX_SYMBOLS][MAX]; // First set
char follow[MAX_SYMBOLS][MAX]; // Follow set
int first_count[MAX_SYMBOLS]; // Counts for first sets
int follow_count[MAX_SYMBOLS]; // Counts for follow sets

// Function to add a production rule
void add_production(char lhs, char* rhs) {
    for (int i = 0; i < prod_count; i++) {
        if (grammar[i].lhs == lhs) {
            strcpy(grammar[i].rhs[grammar[i].rhs_count++], rhs);
            return;
        }
    }
    grammar[prod_count].lhs = lhs;
    strcpy(grammar[prod_count].rhs[0], rhs);
    grammar[prod_count].rhs_count = 1;
    prod_count++;
}

// Function to find the index of a non-terminal
int get_non_terminal_index(char nt) {
    for (int i = 0; i < prod_count; i++) {
        if (grammar[i].lhs == nt) {
            return i;
        }
    }
    return -1;
}

// Function to calculate First set
void calculate_first() {
    int added;

    // Initialize the first set
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        first_count[i] = 0;
        first[i][0] = '\0'; // Initialize
    }

    do {
        added = 0;

        for (int i = 0; i < prod_count; i++) {
            for (int j = 0; j < grammar[i].rhs_count; j++) {
                char* rule = grammar[i].rhs[j];
                for (int k = 0; k < strlen(rule); k++) {
                    char symbol = rule[k];

                    // If terminal, add to First set
                    if (symbol >= 'a' && symbol <= 'z') {
                        if (!strchr(first[i], symbol)) {
                            first[i][first_count[i]++] = symbol;
                            added = 1;
                        }
                        break;
                    }

                    // If non-terminal, find its First set
                    int nt_index = get_non_terminal_index(symbol);
                    if (nt_index != -1) {
                        for (int m = 0; m < first_count[nt_index]; m++) {
                            if (!strchr(first[i], first[nt_index][m])) {
                                first[i][first_count[i]++] = first[nt_index][m];
                                added = 1;
                            }
                        }
                        if (strchr(first[nt_index], 'ε')) {
                            continue; // Epsilon found, check next symbol
                        } else {
                            break; // No need to check further
                        }
                    } else {
                        break; // Symbol is not a terminal or non-terminal
                    }
                }
            }
        }
    } while (added); // Repeat until no new symbols are added
}

// Function to calculate Follow set
void calculate_follow() {
    int added;

    // Initialize the follow set
    for (int i = 0; i < MAX_SYMBOLS; i++) {
        follow_count[i] = 0;
        follow[i][0] = '\0'; // Initialize
    }

    // Follow of the start symbol contains $
    follow[0][follow_count[0]++] = '$';

    do {
        added = 0;

        for (int i = 0; i < prod_count; i++) {
            for (int j = 0; j < grammar[i].rhs_count; j++) {
                char* rule = grammar[i].rhs[j];
                for (int k = 0; k < strlen(rule); k++) {
                    char symbol = rule[k];

                    // If symbol is a non-terminal
                    if (symbol >= 'A' && symbol <= 'Z') {
                        int nt_index = get_non_terminal_index(symbol);

                        // If it's the last symbol
                        if (k + 1 == strlen(rule)) {
                            if (symbol != grammar[i].lhs) {
                                for (int m = 0; m < follow_count[i]; m++) {
                                    if (!strchr(follow[nt_index], follow[i][m])) {
                                        follow[nt_index][follow_count[nt_index]++] = follow[i][m];
                                        added = 1;
                                    }
                                }
                            }
                        } else {
                            char next_symbol = rule[k + 1];

                            // If next symbol is terminal
                            if (next_symbol >= 'a' && next_symbol <= 'z') {
                                if (!strchr(follow[nt_index], next_symbol)) {
                                    follow[nt_index][follow_count[nt_index]++] = next_symbol;
                                    added = 1;
                                }
                            }

                            // If next symbol is non-terminal, add its First set
                            if (next_symbol >= 'A' && next_symbol <= 'Z') {
                                int next_index = get_non_terminal_index(next_symbol);
                                for (int m = 0; m < first_count[next_index]; m++) {
                                    if (first[next_index][m] != 'ε' && !strchr(follow[nt_index], first[next_index][m])) {
                                        follow[nt_index][follow_count[nt_index]++] = first[next_index][m];
                                        added = 1;
                                    }
                                }
                                if (strchr(first[next_index], 'ε')) {
                                    for (int m = 0; m < follow_count[i]; m++) {
                                        if (!strchr(follow[nt_index], follow[i][m])) {
                                            follow[nt_index][follow_count[nt_index]++] = follow[i][m];
                                            added = 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } while (added); // Repeat until no new symbols are added
}

// Function to display First and Follow sets
void display_sets() {
    printf("\nFirst Sets:\n");
    printf("Non-Terminal\tFirst\n");
    for (int i = 0; i < prod_count; i++) {
        printf("%c\t\t", grammar[i].lhs);
        for (int j = 0; j < first_count[i]; j++) {
            printf("%c ", first[i][j]);
        }
        printf("\n");
    }

    printf("\nFollow Sets:\n");
    printf("Non-Terminal\tFollow\n");
    for (int i = 0; i < prod_count; i++) {
        printf("%c\t\t", grammar[i].lhs);
        for (int j = 0; j < follow_count[i]; j++) {
            printf("%c ", follow[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of production rules: ");
    scanf("%d", &n);

    printf("Enter production rules in the form A -> B (e.g., S -> AB):\n");
    for (int i = 0; i < n; i++) {
        char lhs, rhs[MAX_SYMBOLS];
        scanf(" %c -> %s", &lhs, rhs);
        add_production(lhs, rhs);
    }

    calculate_first();
    calculate_follow();
    display_sets();

    return 0;
}

//2
//S->aAc
//A->b|d
