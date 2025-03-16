#include <iostream>
#include <vector>
using namespace std;

void solve(vector <int> &candidates, int target, int index,int currSum,  vector< vector<int> >&ans, vector<int> &temp) {
    //base case
    if (index == candidates.size()) {
        if (currSum == target) {
            ans.push_back(temp);
        }
        return ;
    }
    //include
    if (candidates[index] + currSum <= target) {
        temp.push_back(candidates[index]);
        solve(candidates, target, index,currSum + candidates[index], ans, temp);
        temp.pop_back();
    }
    //exclude
    solve(candidates, target, index + 1, currSum, ans,temp);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector <vector <int> > ans;
    vector <int> temp;
    solve(candidates, target, 0,0, ans, temp);
    return ans;
}

int main() {
    return 0;
}
