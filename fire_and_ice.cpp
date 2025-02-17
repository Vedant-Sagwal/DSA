#include <iostream>
using namespace std;

int solve(int n, int m) {
    //Base Case
    if (n == 1) {
        return 2 % m;
    }
    if (n == 2) {
        return 2 % m;
    }
    int ans;
    if (n % 2 != 0) {
        ans = solve(n - 2,m);
    }
    else {
        ans = solve(n - 1, m)  + 2 * solve(n - 2, m);
    }
    return ans % m;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        cout << solve(n, m) << endl;
    }
    return 0;
}
