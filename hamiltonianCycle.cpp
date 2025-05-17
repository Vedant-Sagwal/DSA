#include <iostream>
#include <vector>
using namespace std;

bool is_valid(vector<int> &x, vector<vector<int>> &graph, int v, int k) {
  // Check if there's an edge from previous vertex
  if (graph[x[k - 1]][v] == 0)
    return false;

  // Check if vertex is already in the path
  for (int i = 0; i < k; i++) {
    if (x[i] == v)
      return false;
  }

  return true;
}

void next_value(vector<int> &x, vector<vector<int>> &graph, int k) {
  int n = graph.size();
  while (true) {
    x[k] = (x[k] + 1) % n;
    if (x[k] == 0) {
      x[k] = -1;
      return; // exhausted options
    }

    if (is_valid(x, graph, x[k], k))
      return;
  }
}

void general_backtrack(vector<int> &x, vector<vector<int>> &graph, int k) {
  int n = graph.size();
  while (true) {
    next_value(x, graph, k);
    if (x[k] == -1)
      return;

    if (k == n - 1) {
      if (graph[x[k]][x[0]] == 1) {
        // It's a cycle
        for (auto i : x) {
          cout << i << "\t";
        }
        cout << endl;
      }
    } else {
      general_backtrack(x, graph, k + 1);
    }
  }
}

void hamiltonian_cycle(vector<int> &x, vector<vector<int>> &graph) {
  int n = graph.size();
  for (int i = 0; i < n; i++) {
    x[i] = -1;
  }
  x[0] = 0; // start from vertex 0

  general_backtrack(x, graph, 1);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<vector<int>> graph;
    int v, e;
    cin >> v;
    graph = vector<vector<int>>(v, vector<int>(v, 0));

    cin >> e;
    for (int i = 0; i < e; i++) {
      int u, v;
      cin >> u >> v;
      graph[u][v] = 1;
      graph[v][u] = 1;
    }
    vector<int> x(v);

    hamiltonian_cycle(x, graph);
  }
  return 0;
}
