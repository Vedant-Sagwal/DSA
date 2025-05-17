#include <iostream>
using namespace std;

int powerxnBit(int x, int n) {
  int result = 1;
  while (n != 0) {
    int lastBit = n & 1;
    if (lastBit == 1) {
      result *= x;
    }
    x = x * x;
    n = n >> 1;
  }
  return result;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    int n;
    cin >> x >> n;
    cout << powerxnBit(x, n) << endl;
  }
  return 0;
}
