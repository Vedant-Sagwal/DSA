#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector <int> productExceptSelf(vector <int> &nums) {
    vector <int> temp(nums.size(), 1);
    int pred = 1;
    for (int i = 0; i < nums.size(); i++) {
        temp[i] = pred * temp[i];
        pred *= nums[i];
    }
    int succ = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
        temp[i] = succ * temp[i];
        succ *= nums[i];
    }
    return temp;
}

int longestConsecutive(vector <int> &nums) {
    int ans = 1;
    unordered_map<int, pair<int, bool> > m1;
    for (int i = 0; i < nums.size(); i++) {
        m1[nums[i]] = make_pair(1, false);
    }
    for (int i = 0; i < nums.size(); i++) { 
        if (m1[nums[i]].second == false) {
            m1[nums[i]].second = true; 
            if (m1[nums[i] - 1].second == true) {
                m1[nums[i] - 1].first = m1[nums[i]].first + 1;
            }
            if (m1[nums[i] + 1].second == true) {
                m1[nums[i] + 1].first = m1[nums[i]].second + 1;
            }
        }
    }
for (auto i : m1) {
    if (i.second.second == true && i.second.first > ans) {
        ans = i.first;
    }
}
return ans;
}

int main() {
    return 0;
}
