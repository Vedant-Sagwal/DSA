#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int countPrimes(int n) {
    bool * arr = (bool *)malloc((n - 1) * sizeof(bool));
    for (int i = 0; i < n - 2; i++) {
        arr[i + 2] = true;
    }
    for (int i = 2; i < n; i++ ) {
        if (arr[i] == true) {
            printf("%d\t", i);
            for (int j = i; j * i < n; j++) {
                arr[j * i] = false; 
            }
        } 
    } 
    int count = 0; 
    for (int i = 0; i < n; i++) {
        if (arr[i] == true) {
            count++;
        }
    }
    return count;
}
int main () {
    printf("%d", countPrimes(10));
    return 0;
}
