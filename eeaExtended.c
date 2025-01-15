#include <stdio.h>
#include <stdlib.h>

int eeaExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        if (b == 0) {
            return -1;
        }
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1; 
    int gcd = eeaExtended(b%a, abs(a), &x1, &y1); 

    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}


int main() {
    int a, b, x, y;
    printf("Enter 1st No: ");
    scanf("%d", &a);
    printf("Enter 2nd No: ");
    scanf("%d", &b);
    if (a < b) {
        printf("gcd : %d", eeaExtended(a, b, &x, &y));
    }
    else {
        printf("gcd : %d", eeaExtended(b, a, &x, &y));
    }
    return 0;
}
