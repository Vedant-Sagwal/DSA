#include <iostream>
#include <vector<
using namespace std;

//tle afdsgagfdagfdjhgpsfibngisfndihgbohsfhublhfsjhbvojfgshfgjlbs
int solve(vector <int> &nums, int k, int index, vector <vector <int> > &v1) {
    if (k == 0) {
        return 0;
    }
    if (index >= nums.size()) {
        return INT_MAX;
    }
    if (v1[index][k] != INT_MAX) {
        return v1[index][k];
    }
    //include
    int include = max(solve(nums, k -1, index + 2, v1), nums[index]);
    int exclude = solve(nums, k, index + 1, v1);
    v1[index][k] = min(include, exclude);
    return min(include, exclude);
}

int minCapability1(vector<int>& nums, int k) {
    //row => index, col => k
    vector < vector <int> > v1(nums.size() + 1, vector <int> (k + 1, INT_MAX));
    return solve(nums, k, 0  , v1); 
}

bool can_be_ans(vector <int> &nums, int k, int ans) {
    int index = 0;
    int count = 0;
    while (index < nums.size() && count < k) {
        if (nums[index] <= ans) {
            count++;
            index += 2;
        }
        else {
            index++;
        }
    }
    if (count >= k) {
        return true;
    }
    return false;
}

int minCapability(vector<int>& nums, int k) {
    int maxi = INT_MIN;
    for (auto i : nums) {
        if (i > maxi) {
            maxi = i;
        }
    }
    int i = 1;
    int j = maxi;
    while (i <= j) {
        int mid = i + (j - i) / 2;
        if (can_be_ans(nums, k, mid)) {
            j = mid - 1;
        }
        else {
            i = mid + 1;
        }
    }
    return i;
}

int main() {
    return 0;
}
