#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> twoSum(vector <int> &nums, int target) {
    vector <int> ans;
    int i = 0;
    int j = nums.size() - 1;
    sort(nums.begin(), nums.end());
    while (i < j) {
        if (nums[i] + nums[j] == target) {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;
            j--;
        }
        else if (nums[i] + nums[j] > target) {
            j--;
        }
        else {
            i++; 
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
        vector <int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i]; 
        }
        int target;
        cin >> target;
        vector <int> ans = twoSum(nums, target);
        cout << "Ans : " << endl;
        for (auto i : ans) {
            cout << i << "\t";
        }
        cout << endl;
    }
    return 0;
}
