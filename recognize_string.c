****************************************************************************************************************************
"""
#c main file: recognize string
"""
#include <stdio.h>
#include <stdlib.h>

//Fuction to recognize string under 'a'
int match_a(const char*str){
return(strlen(str)==1 &&str[0]=='a');
}
//Fuction to recognize string under 'a*b+'
int match_a_star_b_plus(const char*str){
int i=0;



//Matching a*
while(str[i]=='a'){
i++;
}



//Matching b+
int b_count=0;
while(str[i]=='b'){
        i++;
b_count++;
}

//if there was at least one 'b' and we have reached the end of the string
return (b_count>0 &&str[i]=='\0');
}

//fuction to recognize string under 'abb'
int match_abb(const char*str){
    return strcmp(str,"abb")==0;
}


int main(){
char str[100];

//Input string
printf("Enter a string:");
scanf("%s",str);

//Check if string matches any of the patterns
if(match_a(str)){
    printf("The string matches the pattern'a'.\n");
}else if (match_a_star_b_plus(str)){
printf("The string matches the pattern 'a*b+'.\n");
}else if (match_abb(str)){

printf("The string matches the pattern 'abb'.\n");
}else{
printf("The string does not match any pattern.\n ");
}
return 0;
}

****************************************************************************************************************************
"""
#c file-01: string 'a'
"""
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

****************************************************************************************************************************
"""
#c file-02: string 'a.b+'
"""
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

****************************************************************************************************************************
"""
#c file-03: string 'abb'
"""
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

****************************************************************************************************************************
