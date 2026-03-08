#include <stdio.h>
struct Time {
    int h;
    int m;
    int s;
};
int toSeconds(struct Time t) {
    return t.h * 3600 + t.m * 60 + t.s;
}
struct Time difference(struct Time t1, struct Time t2) {
    struct Time diff;
    int sec1 = toSeconds(t1);
    int sec2 = toSeconds(t2);
    int total;
    if (sec1 > sec2)
        total = sec1 - sec2;
    else
        total = sec2 - sec1;
    diff.h = total / 3600;
    total %= 3600;
    diff.m = total / 60;
    diff.s = total % 60;
    return diff;
}
int main(void) {
    struct Time t1, t2, diff;
    printf("Enter first time (HH MM SS): ");
    scanf("%d %d %d", &t1.h, &t1.m, &t1.s);
    printf("Enter second time (HH MM SS): ");
    scanf("%d %d %d", &t2.h, &t2.m, &t2.s);
    diff = difference(t1, t2);
    printf("Absolute Difference = %02d:%02d:%02d\n", diff.h, diff.m, diff.s);
    return 0;
}

