#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
  int val;
  Node *next;
  Node *random;
};

Node *addLast(Node *head, int x) {
  Node *nn = new Node();
  nn->val = x;
  if (head == NULL) {
    head = nn;
    return head;
  }
  Node *prev = NULL;
  Node *curr = head;
  while (curr) {
    prev = curr;
    curr = curr->next;
  }
  prev->next = nn;
  return head;
}
Node *cloneLL(Node *head) {
  Node *ans = NULL;
  Node *ptr = head;
  // Step 1
  while (ptr) {
    ans = addLast(ans, ptr->val);
    ptr = ptr->next;
  }
  Node *ptr1 = head;
  Node *ptr2 = ans;
  // Step 2 linking both copy and original LL
  while (ptr1 && ptr2) {
    Node *temp1 = ptr1->next;
    ptr1->next = ptr2;
    Node *temp2 = ptr2->next;
    ptr2->next = temp1;
    ptr2 = temp2;
    ptr1 = temp1;
  }
  ptr1 = head;
  // copying random pointer wohooo!!
  while (ptr1) {
    if (ptr1->next != NULL) {
      if (ptr1->random != NULL) {
        ptr1->next->random = ptr1->random->next;
      } else {
        ptr1->next->random = NULL;
      }
    }
    ptr1 = ptr1->next->next;
  }
  ptr1 = head;
  ptr2 = ans;
  while (ptr1 && ptr2) {
    ptr1->next = ptr2->next;
    ptr1 = ptr1->next;
    if (ptr1 != NULL) {
      ptr2->next = ptr1->next;
    }
    ptr2 = ptr2->next;
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    Node *lst = NULL;
    Node *tail = NULL;
    unordered_map<int, Node *> m3;
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      if (tail == NULL) {
        lst = new Node();
        lst->val = num;
        tail = lst;
      } else {
        tail->next = new Node();
        tail = tail->next;
        tail->val = num;
      }
      m3[tail->val] = tail;
    }
    Node *tail2 = lst;
    while (tail2 != NULL) {
      int n1;
      cin >> n1;
      tail2->random = m3[n1];
      tail2 = tail2->next;
    }
    Node *ans = cloneLL(lst);
    while (lst != NULL) {
      lst = lst->next;
    }
    cout << endl;
    while (ans != NULL) {
      if (ans->random != NULL) {
        cout <<  ans->val << " :: " << ans->random->val << "\t";
      }
      else {
        cout <<  ans->val << " :: " << -1 << "\t";
      }
      ans = ans->next;
    }
    cout << endl;
  }
  return 0;
}

/*

5
1 2 3 4 5
3 4 5 1 2

5
1 2 3 4 5
-1 -1 -1 -1 -1

5
1 2 3 4 5
1 2 3 4 5

1
10
10

5
1 2 3 4 5
3 3 3 3 3

10
1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1

6
1 2 3 4 5 6
4 5 6 1 2 3

8
1 2 3 4 5 6 7 8
1 1 2 3 5 8 7 6
*/

/*
1 :: 3  2 :: 4  3 :: 5  4 :: 1  5 :: 2
1 :: -1 2 :: -1 3 :: -1 4 :: -1 5 :: -1
1 :: 1  2 :: 2  3 :: 3  4 :: 4  5 :: 5
10 :: 10
1 :: 3  2 :: 3  3 :: 3  4 :: 3  5 :: 3
1 :: 10 2 :: 9  3 :: 8  4 :: 7  5 :: 6  6 :: 5  7 :: 4  8 :: 3  9 :: 2  10 :: 1
1 :: 4  2 :: 5  3 :: 6  4 :: 1  5 :: 2  6 :: 3
1 :: 1  2 :: 1  3 :: 2  4 :: 3  5 :: 5  6 :: 8  7 :: 7  8 :: 6
*/
