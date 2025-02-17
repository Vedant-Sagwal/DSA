#include <iostream>
using namespace std;

long long int superDigit(long long int num) {
    //Base Case
    if (num < 10 && num >= 0) {
        return num;
    }
    long long int sum = 0;
    while (num != 0) {
        long long int rem = num % 10;
        sum += rem;
        num = num / 10;
    }
    return superDigit(sum);
}

long long int solve(long long int n, long long int k) {
    long long int temp1 = superDigit(n);
    long long int temp2 = superDigit(temp1 * k);
    return temp2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}
