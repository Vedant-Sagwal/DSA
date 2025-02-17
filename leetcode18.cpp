#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n1 = nums.size();
    vector< vector<int> > ans;
    map<vector< int>, bool> m1;
    int left1 = 0;
    int right1 = n1 - 1;
    for (left1 = 0;  left1 < n1 -1 ; left1++) {
        for (right1 = n1 - 1; right1 > 0; right1--) {
            int left2 = left1 + 1;
            int right2 = right1 - 1;
            while (left2 < right2) {
                int sum = nums[left1] + nums[left2] + nums[right1] + nums[right2];
                if (sum == target) {
                    vector <int> temp;
                    temp.push_back(nums[left1]);
                    temp.push_back(nums[left2]);
                    temp.push_back(nums[right1]);
                    temp.push_back(nums[right2]);
                    if (m1[temp] !=true) {
                        m1[temp] = true;
                        ans.push_back(temp);
                    }
                    left2++;
                    right2--;
                }
                else if (sum < target) {
                    left2++;
                }
                else {
                    right2--;
                }
            }
        }
    }
    return ans;
}


vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n1 = nums.size();
    vector< vector<int> > ans;
    map<vector< int>, bool> m1;
    int left1 = 0;
    int right1 = n1 - 1;
    for (left1 = 0;  left1 < n1 -1 ; left1++) {
        for (right1 = n1 - 1; right1 > 0; right1--) {
            int left2 = left1 + 1;
            int right2 = right1 - 1;
            while (left2 < right2) {
                int sum = nums[left1] + nums[left2] + nums[right1] + nums[right2];
                if (sum == target) {
                    vector <int> temp;
                    temp.push_back(nums[left1]);
                    temp.push_back(nums[left2]);
                    temp.push_back(nums[right1]);
                    temp.push_back(nums[right2]);
                    if (m1[temp] !=true) {
                        m1[temp] = true;
                        ans.push_back(temp);
                    }
                    left2++;
                    right2--;
                }
                else if (sum <= target) {
                    left2++;
                }
                else {
                    right2--;
                }
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
