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

// Function for Top-Down Parsing with Backtracking
int top_down_parse(char symbol) {
    printf("Trying to parse: %c\n", symbol); // Print the current symbol being parsed

    // If the current symbol matches the input character at the pointer
    if (symbol == input[input_ptr]) {
        printf("Matched: %c\n", symbol); // Print a match
        input_ptr++;
        return 1;
    }

    // Try each production rule for the current symbol
    for (int i = 0; i < prod_count; i++) {
        if (grammar[i].lhs == symbol) {
            printf("Expanding: %c -> %s\n", symbol, grammar[i].rhs); // Show expansion

            int temp_ptr = input_ptr;
            int flag = 1;
            // Try to parse the right-hand side of the production
            for (int j = 0; j < strlen(grammar[i].rhs); j++) {
                if (!top_down_parse(grammar[i].rhs[j])) {
                    flag = 0; // Mark if parsing fails
                    break;
                }
            }

            if (flag) {
                return 1; // Successfully parsed this production
            } else {
                // Backtrack
                input_ptr = temp_ptr;
                printf("Backtracking from: %c\n", symbol); // Print backtracking
            }
        }
    }
    return 0; // Parsing failed for this symbol
}

// Function for Bottom-Up Parsing (Extended Shift-Reduce Parsing)
void bottom_up_parse() {
    printf("\nBottom-Up Parsing:\n");

    char stack[MAX];
    int stack_ptr = 0;

    for (int i = 0; i < strlen(input); i++) {
        stack[stack_ptr++] = input[i];
        stack[stack_ptr] = '\0';

        printf("Shift: %s, Stack: %s\n", &input[i], stack);

        // Check if we can reduce after every shift
        int reduced = 1;
        while (reduced) {
            reduced = 0;
            for (int j = 0; j < prod_count; j++) {
                if (stack_ptr >= strlen(grammar[j].rhs) &&
                    strcmp(&stack[stack_ptr - strlen(grammar[j].rhs)], grammar[j].rhs) == 0) {
                    stack_ptr -= strlen(grammar[j].rhs);
                    stack[stack_ptr++] = grammar[j].lhs;
                    stack[stack_ptr] = '\0';
                    printf("Reduce: %c -> %s, Stack: %s\n", grammar[j].lhs, grammar[j].rhs, stack);
                    reduced = 1;
                    break;
                }
            }
        }
    }

    if (stack_ptr == 1 && stack[0] == grammar[0].lhs) {
        printf("Bottom-up parsing successful\n");
    } else {
        printf("Bottom-up parsing Failed\n");
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

    // Top-down parsing
    printf("\nTop-Down Parsing:\n");
    input_ptr = 0;

    if (top_down_parse(grammar[0].lhs) && input[input_ptr] == '\0') {
        printf("Top-down parsing successful\n");
    } else {
        printf("Top-down parsing Failed\n");
    }

    // Bottom-up parsing
    bottom_up_parse();

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
