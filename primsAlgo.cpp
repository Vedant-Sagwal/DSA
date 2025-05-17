#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
  int val;
  int key;
  int weight;
  int index;
  Node *parent;
  Node *next;
};

void heapify(vector<Node *> &values, int i, int size) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int smallest = i;
  if (left < size && values[left]->key < values[smallest]->key) {
    smallest = left;
  }
  if (right < size && values[right]->key < values[smallest]->key) {
    smallest = right;
  }
  if (smallest != i) {
    swap(values[smallest], values[i]);
    values[smallest]->index = smallest;
    values[i]->index = i;
    heapify(values, smallest, size);
  }
}

void build_priority_queue(vector<Node *> &values, int n) {
  for (int i = n / 2; i >= 0; i--) {
    heapify(values, i, n);
  }
  for (int i = 0; i < values.size(); i++) {
    values[i]->index = i;
  }
}
Node *extract_min(vector<Node *> &values) {
  if (values.empty()) {
    return NULL;
  }
  Node *temp = values[0];
  swap(values[0], values[values.size() - 1]);
  values[0]->index = 0;
  values.pop_back();
  heapify(values, 0, values.size());
  return temp;
}

void decreaseKey(vector<Node *> &values, int index, int newValue) {
  values[index]->key = newValue;
  int parentIndex = (index - 1) / 2;
  while (parentIndex >= 0 && values[parentIndex]->key > values[index]->key) {
    swap(values[parentIndex], values[index]);
    values[parentIndex]->index = parentIndex;
    values[index]->index = index;
    index = parentIndex;
    parentIndex = (index - 1) / 2;
  }
}

void solve(vector<Node *> adjList, int vertices) {
  vector<Node *> pq1;
  for (int i = 0; i < vertices; i++) {
    pq1.push_back(adjList[i]);
  }
  build_priority_queue(pq1, vertices);
  vector<int> inMST(vertices, false);
  for (int i = 0; i < vertices; i++) {
    Node *u = extract_min(pq1);
    inMST[u->val] = true;
    Node *ptr = adjList[u->val]->next;
    while (ptr != NULL) {
      int weight = ptr->weight;
      int val = ptr->val;
      Node *actualNode = adjList[val];
      if (!inMST[val] && weight < actualNode->key) {
        // make parent
        actualNode->parent = u;
        // change key
        decreaseKey(pq1, actualNode->index, weight);
      }
      ptr = ptr->next;
    }
  }
}

// taking adjList as input
vector<Node *> take_input() {
  int vertices, edges;
  cin >> vertices >> edges;
  vector<Node *> v1(vertices);
  for (int i = 0; i < vertices; i++) {
    Node *nn = new Node();
    nn->val = i;
    if (i == 0) {
      nn->key = 0;
    } else {
      nn->key = INT_MAX;
    }
    nn->weight = 0;
    v1[i] = nn;
  }
  for (int i = 0; i < edges; i++) {
    int one, two, weight;
    cin >> one >> two;
    cin >> weight;
    // one -> two
    Node *nn2 = new Node();
    nn2->val = two;
    nn2->weight = weight;
    nn2->key = weight;
    nn2->next = v1[one]->next;
    v1[one]->next = nn2;
    // two -> one
    Node *nn1 = new Node();
    nn1->val = one;
    nn1->weight = weight;
    nn1->key = weight;
    nn1->next = v1[two]->next;
    v1[two]->next = nn1;
  }
  return v1;
}

void displayMST(vector<Node *> adjList) {
  for (int i = 0; i < adjList.size(); i++) {
    if (adjList[i]->parent) {
      cout << adjList[i]->parent->val << " :: " << adjList[i]->val
           << " :: " << adjList[i]->key << endl;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<Node *> adjList = take_input();
    solve(adjList, adjList.size());
    displayMST(adjList);
  }
  return 0;
}
