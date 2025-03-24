#include <iostream>
#include <cmath>
using namespace std;

long long int mini_steps(long long int n, long long int k) {
    //Base Case
    if (n <= 0) {
        return 0LL;
    }
    if (n <= k) {
        return 1LL;
    }
    if (((n % 2) != 0LL) && ((k % 2) != 0LL)) {
        return 1LL + (mini_steps((n - k), k));
    }
    else if ((n % 2 == 0 && k % 2 == 0)) {
        long long int skipped = ceil(n / k);
        return skipped;
    }
    else if ((n % 2 == 0 && k % 2 != 0)) {
        long long int skipped = ceil((double(n) / (k-1)));
        return skipped;
    }
    else {
        return 1LL + (mini_steps(n - (k - 1), k));
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n, k;
        cin >> n >> k;
        cout << mini_steps(n, k) << endl;
    }
    return 0;
}
