#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
     int a = INT_MIN+ 1;
    cout << a << endl;
    int v = a >> 1;
    a = a << 1;
    cout << a <<   ":" << v << endl;
    return 0;
}
