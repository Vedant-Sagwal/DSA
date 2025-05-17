#include <iostream>
#include <vector>
using namespace std;

void next_value(vector<int> &x, int n, int k) {
  while (true) {
    x[k] = (x[k] + 1) % 3; // cycle through 0, 1, then 2 (used as stop flag)
    if (x[k] == 2) {
      x[k] = -1; // exhausted
      return;
    } else {
      return; // binary has no constraints — always valid
    }
  }
}

void general_backtrack(vector<int> &x, int n, int k, vector<string> &results) {
  while (true) {
    next_value(x, n, k);
    if (x[k] == -1)
      return;

    if (k == n - 1) {
      string s;
      for (int i = 0; i < n; i++) {
        s += to_string(x[i]);
      }
      results.push_back(s);
    } else {
      general_backtrack(x, n, k + 1, results);
    }
  }
}

vector<string> generate_binary_strings(int n) {
  vector<int> x(n, -1); // initialize all bits to -1 (unassigned)
  vector<string> results;
  general_backtrack(x, n, 0, results);
  return results;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> binaryStrings = generate_binary_strings(n);
    for (auto &s : binaryStrings) {
      cout << s << endl;
    }
  }
  return 0;
}
