#include <iostream>
#include <vector>
using namespace std;

bool checkPermutation(string s1, string s2) {
  if (s1.length() > s2.length()) {
    return false;
  }
  vector<int> visited(26, 0);
  for (int i = 0; i < s1.length(); i++) {
    visited[s1[i] - 'a']++;
  }
  vector<int> visited1(26, 0);
  for (int i = 0; i < s1.length(); i++) {
    visited1[s2[i] - 'a']++;
  }
  if (visited == visited1) {
    return true;
  }
  for (int i = s1.length(); i < s2.length(); i++) {
    visited1[s2[i - s1.length()] - 'a']--;
    visited1[s2[i] - 'a']++;
    if (visited1 == visited) {
      return true;
    }
  }
  return false;
}

int main() { return 0; }
