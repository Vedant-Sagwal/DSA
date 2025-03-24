#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_cost(vector <long long int> &values, int &n, int &k) {
    sort(values.begin(), values.end());
    long long int sum = 0;
    for (int i = n - 1; i >= n - k; i--) {
        sum += values[i];
    }
    sum += values[n - k - 1];
    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <long long int> v1(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v1[i];
        }
        cout << max_cost(v1, n, k) << endl;
    }
    return 0;
}
