#include <stdio.h>
int main(void) {
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2;
    int i, j, k;
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    if (r1 == r2 && c1 == c2) {
        printf("Addition:\n");
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c1; j++) {
                c[i][j] = a[i][j] + b[i][j];
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
        printf("Subtraction:\n");
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c1; j++) {
                c[i][j] = a[i][j] - b[i][j];
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Addition and subtraction not possible\n");
    }
    if (c1 == r2) {
        printf("Multiplication:\n");
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c2; j++) {
                c[i][j] = 0;
                for (k = 0; k < c1; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Multiplication not possible\n");
    }
    printf("Transpose of first matrix:\n");
    for (i = 0; i < c1; i++) {
        for (j = 0; j < r1; j++) {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
    printf("Transpose of second matrix:\n");
    for (i = 0; i < c2; i++) {
        for (j = 0; j < r2; j++) {
            printf("%d ", b[j][i]);
        }
        printf("\n");
    }
    return 0;
}

