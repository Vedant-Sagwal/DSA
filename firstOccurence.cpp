#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector <int> &arr,int p, int r, int k) {
    //Base case
    if (p > r) {
        return -1;
    }
    int mid = (p + r) / 2;
    if ((mid == p && arr[mid] == k) || (arr[mid] == k && arr[mid - 1] != k)) {
        return mid;
    }
    else if (arr[mid] >= k) {
        return firstOccurence(arr, p, mid - 1, k);
    }
    else {
        return firstOccurence(arr, mid + 1, r, k);
    }
}


int lastOccurence(vector <int> &arr,int p, int r, int k) {
    //Base case
    if (p > r) {
        return -1;
    }
    int mid = (p + r) / 2;
    if (((mid == r && arr[mid] == k) ||arr[mid] == k && arr[mid + 1] != k)) {
        return mid;
    }
    else if (arr[mid] > k) {
        return lastOccurence(arr, p, mid - 1, k);
    }
    else {
        return lastOccurence(arr, mid + 1, r, k);
    }
}

vector<int> searchRange(vector<int>& nums, int target) { 
    vector <int> ans;
    if (nums.size() == 0) {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    if (nums.size() == 1) {
        if (nums[0] == target) {
            ans.push_back(0);
            ans.push_back(0);
            return ans;
        }
        else {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;       
        }
    }
    ans.push_back(firstOccurence(nums, 0, nums.size() - 1, target));
    ans.push_back(lastOccurence(nums, 0, nums.size() - 1, target));
    return ans; 
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
        cout << firstOccurence(nums,0,n - 1, target) << endl;
    }
    return 0;
}
