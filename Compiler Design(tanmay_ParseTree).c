#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure for grammar rules
typedef struct {
    char lhs;
    char rhs[MAX];
} Production;

Production grammar[MAX];
int prod_count = 0;
char input[MAX];
int input_ptr = 0;

// Function to add grammar production
void add_production(char lhs, char* rhs) {
    grammar[prod_count].lhs = lhs;
    strcpy(grammar[prod_count].rhs, rhs);
    prod_count++;
}

// Function to display grammar
void display_grammar() {
    printf("Grammar Productions:\n");
    for (int i = 0; i < prod_count; i++) {
        printf("%c -> %s\n", grammar[i].lhs, grammar[i].rhs);
    }
}

// Function to print parse tree recursively
void print_parse_tree(char symbol, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%c\n", symbol);

    for (int i = 0; i < prod_count; i++) {
        if (grammar[i].lhs == symbol) {
            for (int j = 0; j < strlen(grammar[i].rhs); j++) {
                print_parse_tree(grammar[i].rhs[j], depth + 1);
            }
            break;
        }
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of production rules: ");
    scanf("%d", &n);

    printf("Enter production rules in the form A -> B (e.g., S -> AB):\n");
    for (int i = 0; i < n; i++) {
        char lhs, rhs[MAX];
        scanf(" %c -> %s", &lhs, rhs);
        add_production(lhs, rhs);
    }

    display_grammar();

    printf("Enter input string to parse: ");
    scanf("%s", input);

    // Parse tree
    printf("\nParse Tree:\n");
    print_parse_tree(grammar[0].lhs, 0);

    return 0;
}

//S -> A+B*C
//A -> a
//B -> b
//C -> c
//a+b*c
