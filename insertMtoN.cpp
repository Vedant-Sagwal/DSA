#include <iostream>
using namespace std;

unsigned int solve(unsigned int m, unsigned int n, int i, int j) {
    if (i <= j) {
        for (int a = i; a <= j; a++) {
            m = m & ~(1U << a); 
        }
        cout << "m : " << m << endl;
        n = n << i;
        cout << "n : " << n << endl;
        m = m | n;
        return m;
    }
    else {
        return -1;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i, j;
        cin >> m >> n >> i >> j;
        cout << solve(m, n, i, j) << endl;
    }
    return 0;
}
