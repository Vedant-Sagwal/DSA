#include <iostream>
#include <vector>
#include <queue>

int leastInterval(vector<char>& tasks, int n) {
    vector <int> count(26, 0);
    for (int i = 0; i < tasks.size(); i++) {
        count[tasks[i] - 'A']++;
    }
    priority_queue<int> pq1;
    for (auto a : count) {
        if (a > 0) {
            pq1.push(a);
        } 
    }
    int ans = 0;
    queue<pair<int, int> > q1;
    while (!pq1.empty() && !q1.empty()) {
        ans++;
        if (pq1.empty()) {
            ans = q1.front().second; 
        }
        else {
            int maxi = pq1.top();
            pq1.pop();
            if (maxi - 1 > 0) {
                q1.push(make_pair(maxi - 1, ans + n));
            }
        }
        if (!q1.empty() && ans == q1.front().second) {
            int temp = q1.front().first;
            q1.pop();
            pq1.push(temp);
        }
    }
    return ans;
}

int main() {
    return 0;
}
