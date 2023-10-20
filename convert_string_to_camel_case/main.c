#include <stdio.h>
#include <string.h>


void to_camel_case(const char *text, char *camel) {
    int len = strlen(text);
    int i, j = 0;
    int capitalizeNext = 0;

    for (i = 0; i < len; i++) {
        if (text[i] == '-' || text[i] == '_') {
            capitalizeNext = 1;
        } else {
            if (capitalizeNext) {
                camel[j++] = toupper(text[i]);
                capitalizeNext = 0;
            } else {
                camel[j++] = text[i];
            }
        }
    }
    camel[j] = '\0';
}

int main() {
    const char input[] = "the-stealth-warrior";
    char camel[100]; 
    to_camel_case(input, camel);
    printf("%s\n", camel); 

    const char input2[] = "The_Stealth_Warrior";
    char camel2[100]; 
    to_camel_case(input2, camel2);
    printf("%s\n", camel2);  

    const char input3[] = "The_Stealth-Warrior";
    char camel3[100]; 
    to_camel_case(input3, camel3);
    printf("%s\n", camel3);  

    return 0;
}