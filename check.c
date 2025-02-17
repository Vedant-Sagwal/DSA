#include <stdio.h>

int main() {
    int x = 1;
    x = x << sizeof(int) * 8;
    printf("x : %d", x);
}
