#include <iostream>
#include <list>
#include <vector>
using namespace std;

void solve(unordered_map<int, list<int>> &adjList, vector<bool> &visited,
           stack<int> &s1, int i) {

  visited[i] = true;

  for (auto j : adjList[i]) {
    if (visited[j] == false) {
      solve(adjList, visited, s1, j);
    }
  }
  s1.push(i);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
  vector<int> ans;
  // adj list
  unordered_map<int, list<int>> adjList;
  vector<bool> visited(v);
  stack<int> s1;
  for (int i = 0; i < e; i++) {
    int n1 = edges[i][0];
    int n2 = edges[i][1];

    adjList[n1].push_back(n2);
  }

  for (int i = 0; i < v; i++) {
    if (visited[i] == false) {
      solve(adjList, visited, s1, i);
    }
  }

  while (!s1.empty()) {
    ans.push_back(s1.top());
    s1.pop();
  }
  return ans;
}
