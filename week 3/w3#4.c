#include <stdio.h>
int main() {
    int arr[10];  
    int i, index;
    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the index (0-9): ");
    scanf("%d", &index);
    if (index < 0 || index >= 10) {
        printf("Invalid index! Please enter between 0 and 9.\n");
    } else {
        int *ptr = arr;  
        printf("Element at index %d is: %d\n", index, *(ptr + index));
    }
    return 0;
}

