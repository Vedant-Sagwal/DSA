#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int kIncreasing(vector <int> &nums, int p, int r) {
    //base case
    if (p > r) {
        return -1;
    } 
    int mid = (p + r) / 2;
    if (((mid - 1 >= 0) && nums[mid] > nums[mid - 1]) && ((mid + 1 < nums.size())&& nums[mid] > nums[mid + 1])) {
        return nums[mid];
    }
    else if (((mid - 1 >= 0) && nums[mid] > nums[mid - 1]) && ((mid + 1 < nums.size())&& nums[mid] < nums[mid + 1])) {
        return kIncreasing(nums, mid + 1, r);
    }
    else {
        return kIncreasing(nums, p, mid - 1);
    }
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
        cout << kIncreasing(nums, 0, n - 1) << endl;
   }
    return 0;
}P

