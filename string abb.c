#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the string matches the regular expression 'abb'
bool match_abb(const char *str) {
    return strcmp(str, "abb") == 0;
}

int main() {
    char input[100];

    // Get input string from the user
    printf("Enter a string: ");
    scanf("%s", input);

    // Check for each regular expression
    if (match_abb(input)) {
        printf("\nThe string matches 'abb'.\n");
    }
        else {
        printf("\nThe string does not match of the regular expressions.\n");
    }

    return 0;
}

