#include <bits/stdc++.h>
using namespace std;

int solve(vector <int> length, int d) {
    sort(length.begin(), length.end());
    int count = 0;
    int i = 0;
    int j = 1;
    while (j < length.size()) {
        if (length[j] - length[i] <= d) {
            count++;
            i += 2;
            j += 2;
        }  
        else {
            i++;
            j++;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        vector <int> length(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> length[i];
        }
        cout << solve(length, d) << endl;
    }
    return 0;
}
