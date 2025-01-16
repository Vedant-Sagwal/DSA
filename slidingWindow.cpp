#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumK(vector<int> arr, int k) {
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i]; 
    }
    ans = sum;
    int n = arr.size();
    for (int j = k; j < n; j++) {
        sum = sum + arr[j] - arr[j - k]; 
        if (sum > ans) {
            ans = sum;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector <int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << "Ans : " << maxSumK(arr, k) << endl;
    }
    return 0;
}
