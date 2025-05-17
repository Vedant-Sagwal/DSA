#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
};

class compare {
public:
  bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};

vector<ListNode *> solve(vector<ListNode *> &lists) {
  vector<ListNode *> v1;
  priority_queue<ListNode *, vector<ListNode *>, compare> pq1;
  for (int i = 0; i < lists.size(); i++) {
    if (lists[i] != NULL) {
      pq1.push(lists[i]);
    }
  }
  while (!pq1.empty()) {
    ListNode *temp = pq1.top();
    v1.push_back(pq1.top());
    pq1.pop();
    if (temp && temp->next) {
      pq1.push(temp->next);
    }
  }
  return v1;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
  if (lists.size() == 0) {
    return NULL;
  }
  vector<ListNode *> v1 = solve(lists);
  if (v1.size() == 0) {
    return NULL;
  }
  int i = 0;
  while (i < v1.size() - 1) {
    if (v1[i] != NULL) {
      v1[i]->next = v1[i + 1];
    }
    i++;
  }
  if (v1[v1.size() - 1] != NULL) {
    v1[v1.size() - 1]->next = NULL;
  }
  return v1[0];
}
int main() { return 0; }
