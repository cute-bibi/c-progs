#include <stdio.h>
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        merged[k++] = arr1[i++];
    }
    while (j < size2) {
        merged[k++] = arr2[j++];
    }
}
int main() {
    int size1, size2, i;
    printf("Enter size of first array: ");
    scanf("%d", &size1);
    printf("Enter size of second array: ");
    scanf("%d", &size2);
    int arr1[100], arr2[100], merged[200];
    printf("Enter elements of first sorted array:\n");
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter elements of second sorted array:\n");
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }
    mergeArrays(arr1, size1, arr2, size2, merged);
    printf("Merged sorted array:\n");
    for (i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");
    return 0;
}
