#include <iostream>
#include <vector>
using namespace std;

void solve(vector <int> &candidates, int target,int index, vector< vector <int> > &ans, vector <int> &temp ) {
    if (target == 0) {
        ans.push_back(temp);
        return ;
    }
    for (int i = index; i < candidates.size(); i++) {
        if (candidates[i] > target) {
            break;
        }
        if (i > index && candidates[i] == candidates[i - 1]) {
            continue;
        }
        //include
        temp.push_back(candidates[i]);
        solve(candidates, target - candidates[i],i+1,ans, temp);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector <int> temp;
    vector <vector<int> > ans;
    sort(candidates.begin(), candidates.end());
    solve(candidates, target, 0, ans, temp);
    return ans;
}


int main() {
    return 0;
}
