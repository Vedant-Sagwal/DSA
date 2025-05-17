#include <iostream>
using namespace std;

#define STACKSIZE 100000

struct stack1 {
  int arr[STACKSIZE];
  int top = -1;
};

bool isEmpty(stack1 *s1) {
  if (s1->top == -1) {
    return true;
  } else {
    return false;
  }
}
void push(stack1 *s1, int a) {
  // overflow check
  if (((s1->top) + 1) >= STACKSIZE) {
    return;
  }
  s1->top++;
  s1->arr[s1->top] = a;
}
int pop(stack1 *s1) {
  // underflow check
  if (isEmpty(s1)) {
    return -1;
  }
  int temp = s1->arr[s1->top];
  s1->top = s1->top - 1;
  return temp;
}
int topView(stack1 *s1) {
  if (isEmpty(s1)) {
    return -1;
  }
  return s1->arr[s1->top];
}
int main() {
  stack1 s;

  push(&s, 10);
  push(&s, 20);
  push(&s, 30);

  cout << "Top element: " << topView(&s) << endl;

  // Pop elements and print them
  cout << "Popped: " << pop(&s) << endl;
  cout << "Top element: " << topView(&s) << endl;
  cout << "Popped: " << pop(&s) << endl;
  cout << "Popped: " << pop(&s) << endl;

  cout << "Popped from empty stack: " << pop(&s) << endl;

  return 0;
}
