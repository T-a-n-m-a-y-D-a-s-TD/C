#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

char input[MAX_LENGTH];
int position = 0;

void parseS();
void parseE();

void match(char expected) {
    if (input[position] == expected) {
        position++;
    } else {
        printf("Error: Expected '%c' but found '%c'\n", expected, input[position]);

        position = -1;
    }
}

void parseS() {
    if (position >= strlen(input))
        return;
    printf("S -> gEd\n");
    match('g');
    if (position == -1)
    return;
    parseE();
    if (position == -1)
    return;
    match('d');
}

void parseE() {
    if (position >= strlen(input))
        return;
    if (input[position] == 'a') {
        printf("E -> a|o\n" "string not matched.\n");
        match('a');
    } else if (input[position] == 'o') {
        printf("E -> a|o\n" "string matched.\n");
        match('o');
    } else {
        printf("Error: Invalid E\n");
        position = -1;
    }
}

int main() {
    printf("Enter a string to parse: ");
    fgets(input, MAX_LENGTH, stdin);

    input[strcspn(input, "\n")] = 0;

    position = 0;
    printf("Parsing string: %s\n", input);

    parseS();

    if (position == strlen(input)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
