#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the string matches the regular expression 'a*b+'
bool match_a_star_b_plus(const char *str) {
    int i = 0;

    // Check for zero or more 'a's
    while (str[i] == 'a') {
        i++;
    }

    // There must be at least one 'b'
    if (str[i] != 'b') {
        return false;
    }

    // Check for one or more 'b's
    while (str[i] == 'b') {
        i++;
    }

    // The string should end here
    return str[i] == '\0';
}
int main() {
    char input[100];

    // Get input string from the user
    printf("Enter a string: ");
    scanf("%s", input);

    // Check for each regular expression
    if (match_a_star_b_plus(input)) {
        printf("\nThe string matches 'a*b+'.\n");
    }
        else {
        printf("\nThe string does not match of the regular expressions.\n");
    }

    return 0;
}

