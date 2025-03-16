#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &nums, int i, vector<vector <int> > &ans, vector <int> &temp) {
    if (i == nums.size()) {
        ans.push_back(temp);
        return ;
    } 
    //exclude
    solve(nums, i + 1, ans, temp);
    //include 
    temp.push_back(nums[i]);
    solve(nums, i + 1, ans, temp);
    temp.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector <vector <int> > ans;
    vector< int> temp;
    solve(nums, 0, ans, temp);
    return ans;
}

int main() {
    return 0;
}
