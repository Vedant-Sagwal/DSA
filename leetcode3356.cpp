#include <iostream>
#include <vector>
using namespace std;

bool can_form_zero_array(vector<int> &nums, vector<vector<int> > &queries, int k) {
    vector <int> prefix_sum(nums.size(), 0);
    for (int i = 0; i < k; i++) {
        int left_index = queries[i][0]; 
        int right_index = queries[i][1]; 
        int max_value = queries[i][2]; 
        prefix_sum[left_index] += max_value;
        if (right_index + 1 < nums.size()) {
            prefix_sum[right_index + 1] -= max_value;
        }
    }
    for (int i = 1; i < nums.size(); i++) {
        prefix_sum[i] += prefix_sum[i - 1];
    }
    for (int i = 0; i < nums.size(); i++) {
        if (prefix_sum[i] < nums[i]) {
            return false;
        }
    }
    return true;
}

int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int left = 0;
    int right = queries.size();
    if (!can_form_zero_array(nums, queries, queries.size())) {
        return -1;
    }
    while (left < right) {
        int mid = left + (right - left)/ 2;
        if (can_form_zero_array(nums, queries, mid)) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    } 
    return left;
}

int main() {
    return 0;
}
