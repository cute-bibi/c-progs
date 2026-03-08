#include <stdio.h>
#include <string.h>
int main(void) {
    char str[1000];
    char word[100];
    char result[1000];
    int i, j, k, lenStr, lenWord, match;
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    printf("Enter the word to remove: ");
    if (fgets(word, sizeof(word), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    if (word[strlen(word) - 1] == '\n') {
        word[strlen(word) - 1] = '\0';
    }
    lenStr = strlen(str);
    lenWord = strlen(word);
    j = 0;
    for (i = 0; i < lenStr; ) {
        match = 1;
        if (strncmp(&str[i], word, lenWord) == 0) {
            if ((i == 0 || str[i-1] == ' ') &&
                (str[i+lenWord] == ' ' || str[i+lenWord] == '\0')) {
                i += lenWord;
                if (str[i] == ' ') {
                    i++; 
                }
                match = 0;
            }
        }
        if (match) {
            result[j++] = str[i++];
        }
    }
    result[j] = '\0';
    printf("String after removing word: %s\n", result);
    return 0;
}

