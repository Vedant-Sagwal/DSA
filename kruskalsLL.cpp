#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

static bool cmp(vector<int> &a, vector<int> &b) { return a[2] < b[2]; }
struct node {
  int data;
  node *parent;
  node *next;
};
struct linkedlistset {
  node *head;
  node *tail;
};
unordered_map<node *, linkedlistset *> sets;
unordered_map<int, node *> nodemp;
void makeSet(int v) {
  node *newnode = new node{v, NULL, NULL};
  linkedlistset *newset = new linkedlistset{newnode, newnode};
  newnode->parent = newnode;
  sets[newnode] = newset;
  nodemp[v] = newnode;
}
node *findParent(int v) { return nodemp[v]->parent; }
void unionSet(int u, int v) {
  node *parentu = findParent(u);
  node *parentv = findParent(v);
  if (parentu == parentv)
    return;
  linkedlistset *setu = sets[parentu];
  linkedlistset *setv = sets[parentv];
  if (setu->head == setu->tail) {
    setu->head->next = setv->head;
    setu->tail = setv->tail;
    node *temp = setv->head;
    while (temp) {
      temp->parent = parentu;
      temp = temp->next;
    }
    delete setv;
  } else {
    setv->tail->next = setu->head;
    setv->tail = setu->tail;
    node *temp = setu->head;
    while (temp) {
      temp->parent = parentv;
      temp = temp->next;
    }
    delete setu;
  }
}
int kruskal(int n, vector<vector<int>> &edges) {
  sort(edges.begin(), edges.end(), cmp);
  for (int i = 0; i < n; i++) {
    makeSet(i);
  }
  int mstWeight = 0;
  vector<vector<int>> mst;
  for (auto edge : edges) {
    int u = edge[0];
    int v = edge[1];
    int weight = edge[2];
    if (findParent(u) != findParent(v)) {
      mstWeight += weight;
      mst.push_back({u, v, weight});
      unionSet(u, v);
    }
  }
  cout << "MST:" << endl;
  for (auto edge : mst) {
    cout << edge[0] << "-" << edge[1] << ":" << edge[2] << endl;
  }
  return mstWeight;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      edges.push_back({u, v, w});
    }
    cout << "mst weight:" << kruskal(v, edges) << endl;
  }
  return 0;
}
