#include <iostream>
#include <vector> 
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> s1;
    vector <int> ans(temperatures.size());
    for (int i = temperatures.size() - 1; i >= 0; i--) {
        while (!s1.empty() && temperatures[i] >= temperatures[s1.top()]) {
            s1.pop(); 
        } 
        if (s1.empty()) {
            ans[i] = 0;
        }
        else {
            ans[i] = (s1.top() - i);
        }
        s1.push(i);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> temperatures(n); 
        for (int i = 0; i < n; i++) {
            cin >> temperatures[i];
        }
        vector <int> ans = dailyTemperatures(temperatures);
        for (auto i :ans) {
            cout << i << "\t";
        }
        cout << endl;
    }
    return 0;
}
