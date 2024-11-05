#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int integerCount = 0;

bool isValidInteger(char* str) {
    int i, len = strlen(str);
    if (len == 0)
        return false;
    for (i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9' || (str[i] == '-' && i > 0))
            return false;
    }
    return true;
}

void detectTokens(char* str) {
    int left = 0, right = 0;
    int length = strlen(str);

    while(isValidInteger(subStr) == true) {
                printf("Valid Integer : '%s'\n", subStr);
                integerCount++;
            }
            free(subStr);
            left = right;
        }
    }
}


int main() {
    char str[1000];

    // Get user input
    printf("Enter here to analyze: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    printf("\nThe Program is : '%s'\n", str);
    printf("All Tokens are :\n");

    detectTokens(str);

    // Print summary of token counts
    printf("\nSummary:\n");
    printf("Integers: %d\n", integerCount);

    return 0;
}

//int a = 1; int b = 9; int c = a + b;
