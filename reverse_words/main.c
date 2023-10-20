#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//brain damage

char* reverseWords(const char* text) {
    int len = strlen(text);
    char* new_word = (char *)malloc(len * sizeof(char *));

    memcpy(new_word,text, len * sizeof(char *));

    int start = 0;
    int end = 0;
    
    while (end < len) {
        while (end < len && new_word[end] != ' ') {
            end++;
        }
        
        int i = start;
        int j = end - 1;
        while (i < j) {
            char temp = new_word[i];
            new_word[i] = new_word[j];
            new_word[j] = temp;
            i++;
            j--;
        }
        start = end + 1;
        end = start;
    }

    return new_word;
    free(new_word);
}

int main() {
    const char* word = " asd  asd1 `````||>dçsda{}}{$##%%ds}";
    char* res = reverseWords(word);
    printf("%s", res);
    free(res);
    return 0;
}
