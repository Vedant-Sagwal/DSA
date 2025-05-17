#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solve(string text1, string text2, int index1, int index2) {
  // Base Case
  if (index1 >= text1.length() || index2 >= text2.length()) {
    return 0;
  }
  // include
  int include = 0;
  if (text1[index1] == text2[index2]) {
    include = 1 + solve(text1, text2, index1 + 1, index2 + 1);
  }
  int exclude1 = solve(text1, text2, index1 + 1, index2);
  int exclude2 = solve(text1, text2, index1, index2 + 1);
  int exclude3 = solve(text1, text2, index1 + 1, index2 + 1);
  return max(include, max(exclude1, max(exclude2, exclude3)));
}

int solveMem(string &text1, string &text2, int index1, int index2,
             vector<vector<int>> &v1) {
  // Base Case
  if (index1 >= text1.length() || index2 >= text2.length()) {
    return 0;
  }
  if (v1[index1][index2] != -1) {
    return v1[index1][index2];
  }
  // include
  int include = 0;
  if (text1[index1] == text2[index2]) {
    include = 1 + solveMem(text1, text2, index1 + 1, index2 + 1, v1);
  }
  int exclude1 = solveMem(text1, text2, index1 + 1, index2, v1);
  int exclude2 = solveMem(text1, text2, index1, index2 + 1, v1);
  int exclude3 = solveMem(text1, text2, index1 + 1, index2 + 1, v1);
  v1[index1][index2] = max(include, max(exclude1, max(exclude2, exclude3)));
  return v1[index1][index2];
}

int solveTab(string &text1, string &text2) {
  int n1 = text1.size();
  int n2 = text2.size();
  vector<vector<int>> v1(n1 + 1, vector<int>(n2 + 1, 0));
  for (int index1 = n1 - 1; index1 >= 0; index1--) {
    for (int index2 = n2 - 1; index2 >= 0; index2--) {
      // include
      int include = 0;
      if (text1[index1] == text2[index2]) {
        include = 1 + v1[index1 + 1][index2 + 1];
      }
      int exclude1 = v1[index1 + 1][index2];
      int exclude2 = v1[index1][index2 + 1];
      int exclude3 = v1[index1 + 1][index2 + 1];
      v1[index1][index2] = max(include, max(exclude1, max(exclude2, exclude3)));
    }
  }
  return v1[0][0];
}

int solveOpt(string &text1, string &text2) {
  int n1 = text1.size();
  int n2 = text2.size();
  vector<int> curr(n2 + 1, 0);
  vector<int> next(n2 + 1, 0);
  for (int index1 = n1 - 1; index1 >= 0; index1--) {
    for (int index2 = n2 - 1; index2 >= 0; index2--) {
      // include
      int include = 0;
      if (text1[index1] == text2[index2]) {
        include = 1 + next[index2 + 1];
      }
      int exclude1 = next[index2];
      int exclude2 = curr[index2 + 1];
      int exclude3 = next[index2 + 1];
      curr[index2] = max(include, max(exclude1, max(exclude2, exclude3)));
    }
    next = curr;
  }
  return curr[0];
}

int longestCommonSubsequence(string text1, string text2) {
  return solveOpt(text1, text2);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string first_string;
    string second_string;
    cin >> first_string;
    cin >> second_string;
    cout << longestCommonSubsequence(first_string, second_string) << endl;
  }
}
