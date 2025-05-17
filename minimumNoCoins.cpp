#include <iostream>
#include <vector>
using namespace std;

void makeCoins(vector<int> &coins) {
  coins.push_back(1);
  coins.push_back(2);
  coins.push_back(5);
  coins.push_back(10);
  coins.push_back(20);
  coins.push_back(50);
  coins.push_back(100);
  coins.push_back(200);
  coins.push_back(500);
  coins.push_back(2000);
}

vector<int> minPartition(int N) {
  vector<int> ans;
  vector<int> coins;
  makeCoins(coins);
  int i = coins.size() - 1;
  while (i >= 0 && N != 0) {
    if (N >= coins[i]) {
      ans.push_back(coins[i]);
      N -= coins[i];
    } else {
      i--;
    }
  }
  return ans;
}

int main() { return 0; }
