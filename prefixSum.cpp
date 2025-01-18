#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
using namespace std;

int prefixSum(vector <pair<int, int> > abVal, int n, int m) {
    vector <int> val(n);
    vector <int> prefix(n);
    for (int i = 0;i < m; i++) {
        int a = abVal[i].first;
        int b = abVal[i].second;
        val[a] += 100;
        if (b + 1 < n) {
            val[b + 1] -= 100;
        }
    }
    cout << "val : " << endl;
    for (auto i :val) {
        cout << i << "\t";
    }
    cout << endl; 
    //code for calculating prefix
    int maxi = INT_MIN;
    prefix[0] = val[0];
    for (int i = 1; i < n; i++) {
        prefix[i] += prefix[i - 1] + val[i];
        maxi = max(maxi, prefix[i]);
    }
    return maxi;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <pair<int, int> > abVal;
        for (int i = 0; i < m; i++) {
            int a, b; 
            cin >> a >> b;
            pair<int, int> p1 = make_pair(a, b);
            abVal.push_back(p1);
        }
        cout << prefixSum(abVal, n, m) << endl;
    }
    return 0;
}
