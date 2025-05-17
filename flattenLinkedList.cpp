#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node *child;
};

Node *solve(Node *a, Node *b) {
  Node *curr1 = a;
  Node *next1 = a->child;
  Node *curr2 = b;
  while (next1 && curr2) {
    if (curr2->data <= next1->data && curr2->data >= curr1->data) {
      Node *temp = curr2->child;
      curr1->child = curr2;
      curr2->child = next1;
      curr2 = temp;
      curr1 = curr1->child;
      next1 = next1;
    } else {
      curr1 = curr1->child;
      next1 = next1->child;
    }
  }
  if (curr2 != NULL) {
    curr1->child = curr2;
  }
  return a;
}

Node *mergeLL(Node *a, Node *b) {
  if (a == NULL) {
    return b;
  }
  if (b == NULL) {
    return a;
  }
  if (a->data <= b->data) {
    return solve(a, b);
  } else {
    return solve(b, a);
  }
}

Node *flattenLinkedList(Node *head) {
  // Base Case
  if (head->next == NULL) {
    return head;
  }
  // Recursion
  Node *head1 = flattenLinkedList(head->next);
  return mergeLL(head, head1);
}
