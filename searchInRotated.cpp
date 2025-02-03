#include <iostream>
#include <vector>
using namespace std;

int solve(vector <int> &nums, int p, int r, int target) {
    //Base Case
    if (p > r) {
        return -1;
    }
    int mid = (p + r) / 2;
    if (nums[mid] == target) {
        return mid;
    }
    else if (nums[p] <= nums[mid]) {
        if (nums[p] <= target && target < nums[mid]) {
            return solve(nums, p, mid - 1, target);
        } 
        else {
            return solve(nums, mid + 1, r, target);
        }
    }
    else {
        if (nums[r] >= target && target > nums[mid]) {
            return solve(nums, mid + 1, r,target);
        }
        else {
            return solve(nums, p, mid - 1, target);
        }
    }
}

int search(vector<int>& nums, int target) {
    return solve(nums, 0, nums.size() - 1, target);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int target;
        cin >> target;
        vector <int> nums(n);
        for (int i= 0; i < n; i++) {
            cin >> nums[i]; 
        }
        vector <int> ans;
        ans.push_back(search(nums,target));
    }
    for (auto i : ans) {
        cout << i << endl;
    }
    return 0;
}

/*

7 0
4 5 6 7 0 1 2
7 3
4 5 6 7 0 1 2
1 0
1
3 3
5 1 3
2 3 
1 3
8 8 
4 5 6 7 8 1 2 3
*/
