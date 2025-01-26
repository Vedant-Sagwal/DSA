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


void stockSpan(int* price, int n) {
    stack s1;
    int s[n];
    s[0] = 1;
    push(&s1, 0);
    for (int i = 1; i < n; i++) {
        printf("top view : %d\n", price[topView(&s1)]);
        while (!isEmpty(&s1) && price[i] > price[topView(&s1)]) {
           printf("popped : %d\n", price[pop(&s1)]); 
        }
        if (isEmpty(&s1)) {
            printf("Emptied %d\n", i);
            s[i] = i + 1;
        }
        else {
            s[i] = i - topView(&s1);
        }
        push(&s1, i);
    }
    for (int i = 0; i < n; i++) {
        printf("%d\t",s[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n; 
        scanf("%d", &n);
        int price[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &price[i]); 
        }
        stockSpan(price, n);
    }
    return 0;
}

