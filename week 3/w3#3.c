#include <stdio.h>
int main() {
    int n, i;
    int arr[100];   
    int *ptr;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    ptr = arr;
    printf("Array elements are:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
    return 0;
}

