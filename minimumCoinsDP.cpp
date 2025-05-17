#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &coins, int amount, vector<int> &v1) {
  v1[0] = 0;
  for (int i = 1; i <= amount; i++) {
    int mini = INT_MAX;
    for (auto j : coins) {
      if (i - j >= 0 && v1[i - j] != INT_MAX) {
        v1[i] = min(1 + v1[i - j], mini);
        mini = v1[i];
      }
    }
  }
  return v1[amount];
}

int coinChange(vector<int> &coins, int amount) {
  vector<int> v1(amount + 1, INT_MAX);
  int ass = solve(coins, amount, v1);
  if (ass == INT_MAX) {
    return -1;
  }
  return ass;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, ammount;
    cin >> n >> ammount;
    vector<int> v1(n);
    for (int i = 0; i < n; i++) {
      cin >> v1[i];
    }
    cout << coinChange(v1, ammount) << endl;
  }
  return 0;
}
