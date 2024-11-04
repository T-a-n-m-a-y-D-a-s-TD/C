#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the string matches the regular expression 'a'
bool match_a(const char *str) {
    return strcmp(str, "a") == 0;
}



int main() {
    char input[100];

    // Get input string from the user
    printf("Enter a string: ");
    scanf("%s", input);

    // Check for each regular expression
    if (match_a(input)) {
        printf("\nThe string matches 'a'.\n");
    }
        else {
        printf("\nThe string does not match of the regular expressions.\n");
    }

    return 0;
}
