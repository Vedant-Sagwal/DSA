#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
};
bool isPalindrome(ListNode *head) {
  if (head->next == NULL) {
    return true;
  }
  ListNode *hare = head->next;
  ListNode *turtle = head;
  while (hare && hare->next) {
    turtle = turtle->next;
    hare = hare->next->next;
  }
  ListNode *prev = NULL;
  ListNode *forward = NULL;
  ListNode *curr = turtle->next;

  while (curr) {
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
  }
  turtle->next = prev;
  ListNode *ptr1 = head;
  ListNode *ptr2 = turtle->next;
  while (ptr2) {
    if (ptr1->val != ptr2->val) {
      return false;
    }
    ptr2 = ptr2->next;
    ptr1 = ptr1->next;
  }

  return true;
}

int main() { return 0; }
