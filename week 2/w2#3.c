#include <stdio.h>
struct Complex {
    int real;
    int imag;
};
struct Complex add(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}
int main(void) {
    struct Complex c1, c2, sum;
    printf("Enter first complex number (real imag): ");
    scanf("%d %d", &c1.real, &c1.imag);
    printf("Enter second complex number (real imag): ");
    scanf("%d %d", &c2.real, &c2.imag);
    sum = add(c1, c2);
    if (sum.imag >= 0)
        printf("Sum = %d+%di\n", sum.real, sum.imag);
    else
        printf("Sum = %d%di\n", sum.real, sum.imag);
    return 0;
}

