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