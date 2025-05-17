#include <iostream>
#include <vector>
using namespace std;

bool is_valid(vector<int> &x, vector<vector<int>> &graph, int v, int k) {
  for (int i = 0; i < graph.size(); i++) {
    if (graph[k][i] && x[i] == v) {
      return false;
    }
  }
  return true;
}

void next_value(vector<int> &x, vector<vector<int>> &graph, int m, int k) {
  int n = graph.size();
  while (true) {
    x[k] = (x[k] + 1) % (m + 1);
    if (x[k] == 0) {
      return;
    }
    if (is_valid(x, graph, x[k], k)) {
      return;
    }
  }
}

void general_backtrack(vector<int> &x, vector<vector<int>> &graph, int m, int k,
                       vector<vector<int>> &results) {
  int n = graph.size();
  while (true) {
    next_value(x, graph, m, k);
    if (x[k] == 0)
      return;

    if (k == n - 1) {
      results.push_back(x);
    } else {
      general_backtrack(x, graph, m, k + 1, results);
    }
  }
}

vector<vector<int>> m_coloring(vector<vector<int>> &graph, int m) {
  int n = graph.size();
  vector<int> x(n, 0);
  vector<vector<int>> results;
  general_backtrack(x, graph, m, 0, results);
  return results;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int v, e, m;
    cin >> v >> e >> m;

    vector<vector<int>> graph(v, vector<int>(v, 0));

    for (int i = 0; i < e; i++) {
      int u, vtx;
      cin >> u >> vtx;
      graph[u][vtx] = 1;
      graph[vtx][u] = 1;
    }

    vector<vector<int>> solutions = m_coloring(graph, m);

    if (solutions.empty()) {
      cout << "No valid coloring possible.\n";
    } else {
      for (auto &sol : solutions) {
        for (int color : sol) {
          cout << color << " ";
        }
        cout << endl;
      }
    }
  }

  return 0;
}
