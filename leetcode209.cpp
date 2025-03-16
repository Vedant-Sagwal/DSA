#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int i = 0;
    int ans_length = INT_MAX ;
    int current_length = 0;
    int current_sum = 0;
    for (int j = 0; j < nums.size(); j++) {
        current_sum += nums[j]; 
        current_length++;
        while (current_sum >= target) {
            ans_length = min(ans_length, current_length);
            current_sum -= nums[i];
            i++;
            current_length--;
        }
    }
    if (ans_length == INT_MAX) {
        return 0;
    }
    return ans_length;
}

int main() {
    return 0;
}
