#include <iostream>
#include <vector>
using namespace std;

int solve(int n, int m, int a, int b) {
   return ((min(a, b) * (3 * (n * m) - 3)));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        cout << solve(n, m , a, b) << endl;
    }
    return 0;
}
