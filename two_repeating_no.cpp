#include <iostream>
#include <vector>
using namespace std;

pair<int, int>  solve(vector<int> &v1, int n) {
    int xor1 = 0;
    for (int i = 0;i < v1.size(); i++) {
        xor1 ^= v1[i];
    }
    int xor2 = 0;
    for (int i = 1; i <= n; i++) {
        xor2 ^= i;
    }
    int ansXor = xor1 ^ xor2;
    int rightOne = ansXor & ((~ansXor) + 1);
    int oneNumber = 0;
    int secondNumber = 0;
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] & rightOne) {
            oneNumber ^= v1[i];
        } 
        else {
            secondNumber ^= v1[i];
        }
    }
    for (int i = 1; i <= n;  i++) {
        if (i & rightOne) {
            oneNumber ^= i;
        } 
        else {
            secondNumber ^= i;
        }
    }
    return make_pair(oneNumber, secondNumber);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v1(n + 2, 0);
        for (int i = 0; i < n + 2; i++) {
            cin >> v1[i];
        }
        pair<int, int> ans = solve(v1, n);
        cout << ans.first << "\t" << ans.second << endl;
    }
    return 0;
}
