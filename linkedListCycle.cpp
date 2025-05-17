#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle1(ListNode *head) {
  if (head == NULL) {
    return false;
  }
  unordered_map<ListNode *, bool> visited;
  while (head != NULL && visited[head] != true) {
    visited[head] = true;
    head = head->next;
  }
  if (head == NULL) {
    return false;
  }
  return true;
}

bool hasCycle(ListNode *head) {
  if (head == NULL) {
    return false;
  }
  ListNode *hare = head->next;
  ListNode *turtle = head;
  while (hare != NULL && hare->next != NULL && hare != turtle) {
    hare = hare->next->next;
    turtle = turtle->next;
  }
  if (hare == turtle) {
    return true;
  }
  return false;
}

ListNode *detectCycle(ListNode *head) {
  if (head == NULL) {
    return NULL;
  }
  ListNode *hare = head;
  ListNode *turtle = head;
  while (hare != NULL && hare->next != NULL) {
    hare = hare->next->next;
    turtle = turtle->next;
    if (hare == turtle) {
      break;
    }
  }
  if (hare == NULL || hare->next == NULL) {
    return NULL;
  }
  hare = head;
  while (hare != turtle) {
    hare = hare->next;
    turtle = turtle->next;
  }
  return turtle;
}

int main() { return 0; }
