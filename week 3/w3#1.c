#include <stdio.h>
#define SIZE 25
void createArray(int arr[], int *n);
void displayArray(int arr[], int n);
void deleteAtBeginning(int arr[], int *n);
void deleteAtMiddle(int arr[], int *n);
void deleteAtEnd(int arr[], int *n);
void insertAtPosition(int arr[], int *n, int pos, int value);
int main() {
    int arr[SIZE], n = 0, choice, pos, value;
    while (1) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Delete at Beginning\n");
        printf("4. Delete at Middle\n");
        printf("5. Delete at End\n");
        printf("6. Insert at Position\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createArray(arr, &n);
                break;
            case 2:
                displayArray(arr, n);
                break;
            case 3:
                deleteAtBeginning(arr, &n);
                break;
            case 4:
                deleteAtMiddle(arr, &n);
                break;
            case 5:
                deleteAtEnd(arr, &n);
                break;
            case 6:
                printf("Enter position (1 to %d): ", n+1);
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtPosition(arr, &n, pos, value);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
void createArray(int arr[], int *n) {
    int i;
    printf("Enter number of elements (max %d): ", SIZE);
    scanf("%d", n);
    if (*n > SIZE) {
        printf("Size exceeds limit. Setting size to %d.\n", SIZE);
        *n = SIZE;
    }
    printf("Enter %d elements:\n", *n);
    for (i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}
void displayArray(int arr[], int n) {
    int i;
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("New Array elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void deleteAtBeginning(int arr[], int *n) {
    int i;
    if (*n == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (i = 0; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Deleted element at beginning.\n");
    displayArray(arr,*n);
}
void deleteAtMiddle(int arr[], int *n) {
    int i, mid;
    if (*n == 0) {
        printf("Array is empty.\n");
        return;
    }
    mid = *n / 2; 
    for (i = mid; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Deleted element at middle.\n");
    displayArray(arr,*n);
}
void deleteAtEnd(int arr[], int *n) {
    if (*n == 0) {
        printf("Array is empty.\n");
        return;
    }
    (*n)--;
    printf("Deleted element at end.\n");
    displayArray(arr,*n);
}
void insertAtPosition(int arr[], int *n, int pos, int value) {
    int i;
    if (*n >= SIZE) {
        printf("Array is full.\n");
        return;
    }
    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position.\n");
        return;
    }
    for (i = *n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    (*n)++;
    printf("Inserted %d at position %d.\n", value, pos);
    displayArray(arr,*n);
}
