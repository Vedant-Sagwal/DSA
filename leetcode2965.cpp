#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    vector <int> ans;
    int n = grid.size();
    unordered_map<int, bool> m1;
    for (int i = 1; i <= (n * n); i++) {
        m1[i] == false;
    }
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (m1[grid[i][j]] == false) {
                m1[grid[i][j]] = true;
            }
            else {
                ans.push_back(grid[i][j]); 
            }
        }
    }
    for (auto i : m1) {
        if (i.second == false) {
            ans.push_back(i.first);
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
    vector <vector<int> > &grid()
    }
    return 0;
}
