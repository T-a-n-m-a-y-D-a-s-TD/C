****************************************************************************************************************************
"""
#c file-01: NFA string 'a'
"""
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    START,
    STATE_A,
    STATE_REJECT  // State to reject invalid strings
} State;

// Function to check if the string is accepted by the NFA
int is_accepted(const char *input) {
    int current_states[3] = {0};  // Array to track active states
    int next_states[3];           // Array for the next states after processing input
    int active_count = 1;         // Number of active states

    // Start with the initial state
    current_states[0] = START;

    printf("\nNFA State Transitions:\n");

    for (int i = 0; input[i] != '\0'; i++) {
        char symbol = input[i];
        next_states[0] = 0;  // Reset next states count
        int next_count = 0;

        // Process each active state
        for (int j = 0; j < active_count; j++) {
            State current_state = current_states[j];

            switch (current_state) {
                case START:
                    if (symbol == 'a') {
                        next_states[next_count++] = STATE_A;  // Transition to STATE_A on 'a'
                        printf("State: START --(%c)--> STATE_A\n", symbol);
                    } else {
                        next_states[next_count++] = STATE_REJECT;  // Transition to REJECT on anything else
                        printf("State: START --(%c)--> REJECTED\n", symbol);
                    }
                    break;

                case STATE_A:
                    // If we are in STATE_A and get any more input, reject the string
                    next_states[next_count++] = STATE_REJECT;
                    printf("State: STATE_A --(%c)--> REJECTED (extra input after 'a')\n", symbol);
                    return 0;

                case STATE_REJECT:
                    // Once in REJECT state, further input is ignored and the NFA stops.
                    printf("State: REJECT --(%c)--> REJECTED\n", symbol);
                    return 0;
            }
        }

        // Update current states to the next states
        memcpy(current_states, next_states, next_count * sizeof(int));
        active_count = next_count;  // Update the active count
    }

    // Check if any of the current states is an accepting state (STATE_A)
    for (int j = 0; j < active_count; j++) {
        if (current_states[j] == STATE_A) {
            return 1;  // Accepted if we end in STATE_A
        }
    }

    return 0;  // Rejected if no accepting states are active
}

int main() {
    char input[100];
    printf("Enter a string (only 'a' and 'b' allowed): ");
    scanf("%s", input);

    if (is_accepted(input)) {
        printf("\nThe string '%s' is accepted by the NFA.\n", input);
    } else {
        printf("\nThe string '%s' is rejected by the NFA.\n", input);
    }

    return 0;
}

****************************************************************************************************************************
"""
#c file-02: NFA string 'a.b+'
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
    int current_states[4] = {0};  // Array to track active states
    int next_states[4];           // Array for the next states after processing input
    int active_count = 1;         // Number of active states

    // Start with the initial state
    current_states[0] = START;

    printf("\nNFA State Transitions:\n");

    for (int i = 0; input[i] != '\0'; i++) {
        char symbol = input[i];
        next_states[0] = 0;  // Reset next states count
        int next_count = 0;

        // Process each active state
        for (int j = 0; j < active_count; j++) {
            State current_state = current_states[j];

            switch (current_state) {
                case START:
                    if (symbol == 'a') {
                        next_states[next_count++] = STATE_A;  // Transition to STATE_A on 'a'
                        printf("State: START --(%c)--> STATE_A\n", symbol);
                    } else if (symbol == 'b') {
                        next_states[next_count++] = STATE_B;  // Transition to STATE_B on 'b'
                        printf("State: START --(%c)--> STATE_B\n", symbol);
                    } else {
                        next_states[next_count++] = STATE_REJECT;  // Transition to REJECT on invalid input
                        printf("State: START --(%c)--> REJECTED\n", symbol);
                    }
                    break;

                case STATE_A:
                    if (symbol == 'a') {
                        next_states[next_count++] = STATE_A;  // Stay in STATE_A on 'a'
                        printf("State: STATE_A --(%c)--> STATE_A\n", symbol);
                    } else if (symbol == 'b') {
                        next_states[next_count++] = STATE_B;  // Transition to STATE_B on 'b'
                        printf("State: STATE_A --(%c)--> STATE_B\n", symbol);
                    } else {
                        next_states[next_count++] = STATE_REJECT;  // Transition to REJECT on invalid input
                        printf("State: STATE_A --(%c)--> REJECTED\n", symbol);
                    }
                    break;

                case STATE_B:
                    if (symbol == 'b') {
                        next_states[next_count++] = STATE_B;  // Stay in STATE_B on 'b'
                        printf("State: STATE_B --(%c)--> STATE_B\n", symbol);
                    } else if (symbol == 'a') {
                        next_states[next_count++] = STATE_REJECT;  // Reject if 'a' appears after 'b'
                        printf("State: STATE_B --(%c)--> REJECTED (invalid sequence)\n", symbol);
                    } else {
                        next_states[next_count++] = STATE_REJECT;  // Transition to REJECT on invalid input
                        printf("State: STATE_B --(%c)--> REJECTED\n", symbol);
                    }
                    break;

                case STATE_REJECT:
                    // Once in REJECT state, further input is ignored and the NFA stops.
                    printf("State: REJECT --(%c)--> REJECTED\n", symbol);
                    return 0;  // Reject and stop processing
            }
        }

        // Update current states to the next states
        memcpy(current_states, next_states, next_count * sizeof(int));
        active_count = next_count;  // Update the active count
    }

    // Check if any of the current states is an accepting state (STATE_B)
    for (int j = 0; j < active_count; j++) {
        if (current_states[j] == STATE_B) {
            return 1;  // Accepted if we end in STATE_B
        }
    }

    return 0;  // Rejected if no accepting states are active
}

int main() {
    char input[100];
    printf("Enter a string (only 'a' and 'b' allowed): ");
    scanf("%s", input);

    if (is_accepted(input)) {
        printf("\nThe string '%s' is accepted by the NFA.\n", input);
    } else {
        printf("\nThe string '%s' is rejected by the NFA.\n", input);
    }

    return 0;
}

****************************************************************************************************************************
"""
#c file-03: NFA string 'abb'
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

// Function to check if the string is accepted by the NFA
int is_accepted(const char *input) {
    int current_states[4] = {0};  // Array to track active states
    int next_states[4];           // Array for the next states after processing input
    int active_count = 1;         // Number of active states

    // Start with the initial state
    current_states[0] = START;

    printf("\nNFA State Transitions:\n");

    for (int i = 0; input[i] != '\0'; i++) {
        char symbol = input[i];
        next_states[0] = 0;  // Reset next states count
        int next_count = 0;

        // Process each active state
        for (int j = 0; j < active_count; j++) {
            State current_state = current_states[j];

            switch (current_state) {
                case START:
                    if (symbol == 'a') {
                        next_states[next_count++] = STATE_A;  // Transition to STATE_A on 'a'
                        printf("State: START --(%c)--> STATE_A\n", symbol);
                    }
                    break;

                case STATE_A:
                    if (symbol == 'b') {
                        next_states[next_count++] = STATE_AB;  // Transition to STATE_AB on 'b'
                        printf("State: STATE_A --(%c)--> STATE_AB\n", symbol);
                    }
                    break;

                case STATE_AB:
                    if (symbol == 'b') {
                        next_states[next_count++] = STATE_ABB;  // Transition to STATE_ABB on 'b'
                        printf("State: STATE_AB --(%c)--> STATE_ABB\n", symbol);
                    }
                    break;

                case STATE_ABB:
                    printf("State: STATE_ABB --(%c)--> REJECTED (extra input)\n", symbol);
                    return 0;  // Reject if there's extra input after 'abb'
            }
        }

        // Update current states to the next states
        memcpy(current_states, next_states, next_count * sizeof(int));
        active_count = next_count;  // Update the active count
    }

    // Check if any of the current states is an accepting state (STATE_ABB)
    for (int j = 0; j < active_count; j++) {
        if (current_states[j] == STATE_ABB) {
            return 1;  // Accepted if in STATE_ABB
        }
    }

    return 0;  // Rejected if no accepting states are active
}

int main() {
    char input[100];
    printf("Enter a string (only 'a' and 'b' allowed): ");
    scanf("%s", input);

    if (is_accepted(input)) {
        printf("\nThe string '%s' is accepted by the NFA.\n", input);
    } else {
        printf("\nThe string '%s' is rejected by the NFA.\n", input);
    }

    return 0;
}

****************************************************************************************************************************
