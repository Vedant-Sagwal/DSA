#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int mismatch(vector <char> v1, vector <char> v2) {
    int count = 0;
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
            count++;
        }
    }
    return count;
}

int sumPowerBF(string s, int k) {
    //brute force
    int sum = 0 ;
    for (int i = 0; i < s.length() - k; i++) {
        vector <char> a;
        vector <char> b;
        for (int j = i; j < i + k; j++) {
            a.push_back(s[j]);
        }
        for (int j = i + 1; j < i + k + 1; j++) {
            b.push_back(s[j]);
        }
        int count = mismatch(a, b);
        sum += count;
    }
    return sum;
}

long long int sumPowerOpt(string s, int k) {
    int n = s.length();
    long long int count = 0;
    vector <int> prefix(n, 0);
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            prefix[i] = prefix[i - 1] + 1;
        }
        else {
            prefix[i] = prefix[i - 1];
        }
    }
    for (auto i : prefix) {
        cout << i << endl;
    }
    for (int i = k; i < n; i++) {
        count += (prefix[i] - prefix[i - k]);
    }
    return count;
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        int k;
        cin >> n;
        cin >> k;
        string s;
        cin >> s;
        cout << sumPowerOpt(s, k) << endl;
    }
    return 0;
}
