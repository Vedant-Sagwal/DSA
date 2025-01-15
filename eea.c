#include <stdio.h>

int eea(int a, int b) {
    while (a != 0) {
        int temp = a;
        a = b % a;
        b = temp;
    }
    return b;
}
int eeaRecursive (int a, int b) {
    //base case 
    if (a == 0) {   
        return b;
    }
    return eeaRecursive(b % a, a);
int main() {
    int a, b;
    printf("Enter 1st no. : ");
    scanf("%d", &a);
    printf("Enter 2nd no. : ");
    scanf("%d", &b);
    if (a < b) {
        printf("%d\n", eea(a, b));
        printf("%d", eeaRecursive(a, b));
    }
    else {
        printf("%d\n", eea(b, a));
        printf("%d", eeaRecursive(b, a));
    }
    return 0;
}