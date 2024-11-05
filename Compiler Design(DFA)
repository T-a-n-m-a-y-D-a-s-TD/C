****************************************************************************************************************************
"""
#c file-01: DFA string 'a'
"""
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    START,
    STATE_A,
    STATE_REJECT  // State to reject invalid strings
} State;

int is_accepted(const char *input) {
    State current_state = START;
    printf("\nDFA State Transitions:\n");

    for (int i = 0; input[i] != '\0'; i++) {
        char symbol = input[i];

        switch (current_state) {
            case START:
                if (symbol == 'a') {
                    current_state = STATE_A;  // Transition to STATE_A on 'a'
                    printf("State: START --(%c)--> STATE_A\n", symbol);
                } else {
                    current_state = STATE_REJECT;  // Reject if input doesn't start with 'a'
                    printf("State: START --(%c)--> REJECTED\n", symbol);
                    return 0;
                }
                break;

            case STATE_A:
                current_state = STATE_REJECT;  // If any character appears after 'a', reject the string
                if (symbol == '\0') {  // This is just to handle empty string, not necessary here
                   printf("State: STATE_A (ACCEPT)\n");
                } else {
                    printf("State: STATE_A --(%c)--> REJECTED (extra input after 'a')\n", symbol);
                    return 0;  // Reject on any extra input
                }
                break;

            case STATE_REJECT:
                printf("State: REJECT --(%c)--> REJECTED\n", symbol);
                return 0;  // Reject and stop processing further input
        }
    }

    // If the final state is STATE_A (i.e., the string was exactly "a"), accept it.
    if (current_state == STATE_A) {
        return 1;  // Accept if the final state is STATE_A
    }

    return 0;  // Reject otherwise
}

int main() {
    char input[100];
    printf("Enter a string (only 'a' and 'b' allowed): ");
    scanf("%s", input);

    if (is_accepted(input)) {
        printf("\nThe string '%s' is accepted by the DFA.\n", input);
    } else {
        printf("\nThe string '%s' is rejected by the DFA.\n", input);
    }

    return 0;
}

****************************************************************************************************************************
"""
#c file-02: DFA string 'a.b+'
"""
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    START,
    STATE_A,
    STATE_B,
    STATE_REJECT  // State to reject invalid strings
} State;

int is_accepted(const char *input) {
    State current_state = START;
    printf("\nDFA State Transitions:\n");

    for (int i = 0; input[i] != '\0'; i++) {
        char symbol = input[i];
        int is_last_symbol = (input[i + 1] == '\0');  // Check if it's the last symbol

        switch (current_state) {
            case START:
                if (symbol == 'a') {
                    current_state = STATE_A;  // Transition from START to STATE_A on 'a'
                    printf("State: START --(%c)--> STATE_A\n", symbol);
                } else if (symbol == 'b') {
                    current_state = STATE_B;  // Transition from START to STATE_B on 'b'
                    printf("State: START --(%c)--> STATE_B\n", symbol);
                } else {
                    printf("State: START --(%c)--> REJECTED\n", symbol);
                    return 0;  // Reject if the first character is neither 'a' nor 'b' and stop processing
                }
                break;

            case STATE_A:
                if (symbol == 'a') {
                    printf("State: STATE_A --(%c)--> STATE_A\n", symbol);  // Stay in STATE_A on 'a'
                    if (is_last_symbol) {
                        current_state = STATE_REJECT;  // Reject if the string ends with 'a'
                        printf("State: STATE_A --(%c)--> REJECTED (There is no b)\n", symbol);
                        return 0;  // Stop processing if rejected
                    }
                } else if (symbol == 'b') {
                    current_state = STATE_B;  // Transition to STATE_B on 'b'
                    printf("State: STATE_A --(%c)--> STATE_B\n", symbol);
                } else {
                    printf("State: STATE_A --(%c)--> REJECTED\n", symbol);
                    return 0;  // Reject and stop processing
                }
                break;

            case STATE_B:
                if (symbol == 'b') {
                    printf("State: STATE_B --(%c)--> STATE_B\n", symbol);  // Stay in STATE_B on 'b'
                } else if (symbol == 'a') {
                    current_state = STATE_REJECT;  // Reject if 'a' appears after 'b'
                    printf("State: STATE_B --(%c)--> REJECTED (Ends with a)\n", symbol);
                    return 0;  // Stop processing immediately
                } else {
                    printf("State: STATE_B --(%c)--> REJECTED\n", symbol);
                    return 0;  // Reject and stop processing
                }
                break;

            case STATE_REJECT:
                // Once in REJECT state, further input is ignored and the DFA stops.
                return 0;  // Reject and stop processing
        }
    }

    // Check if the final state is an accepting state
    if (current_state == STATE_B) {
        return 1;  // Accept if we end in STATE_B
    }

    return 0;  // Reject otherwise (e.g., if the string ends with 'a' or invalid sequence)
}

int main() {
    char input[100];
    printf("Enter a string (only 'a' and 'b' allowed): ");
    scanf("%s", input);

    if (is_accepted(input)) {
        printf("\nThe string '%s' is accepted by the DFA.\n", input);
    } else {
        printf("\nThe string '%s' is rejected by the DFA.\n", input);
    }

    return 0;
}

****************************************************************************************************************************
"""
#c file-03: DFA string 'abb'
"""
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    START,
    STATE_A,
    STATE_AB,
    STATE_ABB,
    STATE_REJECT  // State to reject invalid strings
} State;

int is_accepted(const char *input) {
    State current_state = START;
    printf("\nDFA State Transitions:\n");

    for (int i = 0; input[i] != '\0'; i++) {
        char symbol = input[i];

        switch (current_state) {
            case START:
                if (symbol == 'a') {
                    current_state = STATE_A;  // Transition to STATE_A on 'a'
                    printf("State: START --(%c)--> STATE_A\n", symbol);
                } else {
                    current_state = STATE_REJECT;  // Reject if input doesn't start with 'a'
                    printf("State: START --(%c)--> REJECTED (starts with b)\n", symbol);
                    return 0;
                }
                break;

            case STATE_A:
                if (symbol == 'b') {
                    current_state = STATE_AB;  // Transition to STATE_AB on 'b'
                    printf("State: STATE_A --(%c)--> STATE_AB\n", symbol);
                } else {
                    current_state = STATE_REJECT;  // Reject if anything other than 'b' after 'a'
                    printf("State: STATE_A --(%c)--> REJECTED\n", symbol);
                    return 0;
                }
                break;

            case STATE_AB:
                if (symbol == 'b') {
                    current_state = STATE_ABB;  // Transition to STATE_ABB on 'b'
                    printf("State: STATE_AB --(%c)--> STATE_ABB\n", symbol);
                } else {
                    current_state = STATE_REJECT;  // Reject if anything other than 'b' after 'ab'
                    printf("State: STATE_AB --(%c)--> REJECTED (a after b)\n", symbol);
                    return 0;
                }
                break;

            case STATE_ABB:
                current_state = STATE_REJECT;  // Reject if there is any more input after 'abb'
                printf("State: STATE_ABB --(%c)--> REJECTED (extra input)\n", symbol);
                return 0;

            case STATE_REJECT:
                printf("State: REJECT --(%c)--> REJECTED\n", symbol);
                return 0;  // Stop further input processing in the REJECT state
        }
    }

    // Check if the final state is STATE_ABB (i.e., if the string was exactly "abb")
    if (current_state == STATE_ABB) {
        return 1;  // Accept if the final state is STATE_ABB
    }

    return 0;  // Reject otherwise
}

int main() {
    char input[100];
    printf("Enter a string (only 'a' and 'b' allowed): ");
    scanf("%s", input);

    if (is_accepted(input)) {
        printf("\nThe string '%s' is accepted by the DFA.\n", input);
    } else {
        printf("\nThe string '%s' is rejected by the DFA.\n", input);
    }

    return 0;
}

****************************************************************************************************************************
