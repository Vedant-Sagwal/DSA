#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void printOptimalParens(const vector<vector<int>> &s, int i, int j) {
  if (i == j) {
    cout << "A" << i + 1;
  } else {
    cout << "(";
    printOptimalParens(s, i, s[i][j]);
    printOptimalParens(s, s[i][j] + 1, j);
    cout << ")";
  }
}

int Mcm(const vector<int> &p) {
  int n = p.size() - 1;
  vector<vector<int>> dp(n, vector<int>(n, 0));
  vector<vector<int>> s(n, vector<int>(n, 0));

  for (int l = 2; l <= n; l++) {
    for (int i = 0; i <= n - l; i++) {
      int j = i + l - 1;
      dp[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        int q = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
        if (q < dp[i][j]) {
          dp[i][j] = q;
          s[i][j] = k;
        }
      }
    }
  }

  cout << "Optimal Parenthesization: ";
  printOptimalParens(s, 0, n - 1);
  cout << endl;

  return dp[0][n - 1];
}

int main() {
  int n;
  cout << "Enter the number of dimensions: ";
  cin >> n;

  if (n < 2) {
    cout << "Invalid input. Number of dimensions must be >= 2." << endl;
    return 0;
  }

  vector<int> p(n);
  cout << "Enter the dimensions array: ";
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  int minCost = Mcm(p);
  cout << "Minimum number of multiplications: " << minCost << endl;

  return 0;
}
