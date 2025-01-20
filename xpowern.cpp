#include <iostream>
#include <vector>
using namespace std;

int powerxn(int x, int n) {
    //base case
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return powerxn(x, n / 2) * powerxn(x, n / 2);
    }
    else {
        return x * powerxn(x, n / 2) * powerxn(x, n / 2);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        int n;
        cin >> x >> n;
        cout << powerxn(x, n) << endl;
    }
    return 0;
}
