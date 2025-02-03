#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100000

typedef struct stack {
    int arr[STACKSIZE];
    int top = 0;
} stack;

void push(stack s1, int a) {
    //overflow check
    if (top + 1 >= STACKSIZE) {
        return ;
    }
    arr[++top] = a;
}
int pop(stack s1) {
    //underflow check
    if (top == 0) {
        return ;
    }
    return arr[top--];
}
int topView(stack s1) {
    if (isEmpty(s1)) {
        return -1;
    }
    return s1[top];
}
bool isEmpty(stack s1) {
    return s1.top() == -1;
}

int* stockSpan(int* price, int n) {
    stack s1;
    int s[n];
    s[0] = 1;
    push(s1, 0);
    for (int i = 1; i < n; i++) {
        while (!empty(s1) && price[i] > price[top(s1)]) {
           int temp = pop(s1); 
        }
        if (isEmpty(s1) ) {
            s[i] = i + 1;
        }
        else {
            s[i] = i - top(s1);
        }
    }
    return s;
}

int main() {
    int t;
    while (t--) {
        int n; 
        int price[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &price[i]); 
        }
        int * s = stockSpan(price, n);
        for (int i = 0; i < n; i++) {
            printf(s[i]);
        }
    }
    return 0;
}

