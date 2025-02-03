#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int missingNumber1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ans; 
    if (nums[0] != 0) {
        return 0;
    }
    for (int i = 1; i < nums.size(); i++) {
        int diff = nums[i] - nums[i - 1];
        if (diff != 1) {
            return nums[i] - 1;
        }
    }
    if (nums[nums.size() - 1] != nums.size()) {
        return nums.size();
    }
    return -1;
}

int missingNumber(vector<int>& nums) {
    int a1 = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        a1  = a1 ^  nums[i];
    }
    int a2 = 0;
    for (int i = 1; i <= nums.size(); i++) {
        a2 = a2 ^ (i); 
    }
    return (a1 ^ a2);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << missingNumber(nums) << endl;
   }
    return 0;
}
