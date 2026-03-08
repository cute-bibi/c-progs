#include <stdio.h>
#include <string.h>
int main(void) {
    char str1[1000], str2[1000], str3[1000];
    int choice, i, len;
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    if (str1[strlen(str1) - 1] == '\n') str1[strlen(str1) - 1] = '\0';
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    if (str2[strlen(str2) - 1] == '\n') str2[strlen(str2) - 1] = '\0';
    printf("Choose operation:\n");
    printf("1. Addition (Concatenation)\n");
    printf("2. Copying\n");
    printf("3. Reverse\n");
    printf("4. Length of String\n");
    scanf("%d", &choice);
    if (choice == 1) {
        strcat(str1, str2);
        printf("Result of addition: %s\n", str1);
    } else if (choice == 2) {
        strcpy(str3, str1);
        printf("Copy of first string: %s\n", str3);
    } else if (choice == 3) {
        len = strlen(str1);
        for (i = 0; i < len; i++) {
            str3[i] = str1[len - i - 1];
        }
        str3[len] = '\0';
        printf("Reverse of first string: %s\n", str3);
    } else if (choice == 4) {
        printf("Length of first string: %d\n", (int)strlen(str1));
    } else {
        printf("Invalid choice\n");
    }
    return 0;
}

