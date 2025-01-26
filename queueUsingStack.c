#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACKSIZE 100000

typedef struct stack {
    int arr[STACKSIZE];
    int top = -1;
} stack;

bool isEmpty(stack* s1) {
    if (s1->top == -1) {
        return true;
    }
    else {
        return false;
    }
}
void push(stack* s1, int a) {
    //overflow check
    if (((s1->top) + 1) >= STACKSIZE) {
        return ;
    }
    s1->top++;
    s1->arr[s1->top] = a;
}
int pop(stack* s1){
    //underflow check
    if (isEmpty(s1)) {
        return -1 ;
    }
    int temp = s1->arr[s1->top];
    s1->top = s1->top - 1;
    return temp;
}
int topView(stack* s1) {
    if (isEmpty(s1)) {
        return -1;
    }
    return s1->arr[s1->top];
}


int main() {
    return 0;
}
