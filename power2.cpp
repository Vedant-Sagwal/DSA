#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int mod = 1e9 + 7;

long long int xpowern(long long int x, long long int n) {
    long long int result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result*x) % mod ; 
        }
        x = (x *x) % mod;
        n = n / 2;
    }
    return result % mod;
}
long long int onesinBinary(long long int n) {
    long long int ans = 0;
    while (n != 0) {
        long long int ques = n / 2 % (xpowern(10, 9) + 7);
        long long int rem = n % 2;
        if (rem == 1) {
            ans += 1;
        }
        n = ques % (xpowern(10, 9) + 7);
    }
    return ans % (xpowern(10, 9) + 7);
}
long long int power2(long long int n) {
    long long int ones = onesinBinary(n) % (xpowern(10, 9) + 7);    
    long long int power = n * ones % (xpowern(10, 9) + 7); 
    long long int ans = xpowern(2, power) % (xpowern(10, 9) + 7);
    return ans;
}

int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n; 
        cout << power2(n) << endl;
    }
    return 0;
}
