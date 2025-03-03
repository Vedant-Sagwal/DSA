#include <iostream>
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector <int> smaller;
    vector <int> equal;
    vector <int> larger;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < pivot) {
            smaller.push_back(nums[i]);
        }
        else if (nums[i] == pivot) {
            equal.push_back(nums[i]);
        }
        else {
            larger.push_back(nums[i]);
        }
    }
    int count = 0;
    for (int i = 0; i < smaller.size(); i++) {
        nums[count++] = smaller[i];
    }
    for (int i = 0; i < equal.size(); i++) {
        nums[count++] = equal[i];
    }
    for (int i = 0; i < larger.size(); i++) {
        nums[count++] = larger[i];
    }
    return nums; 
}

int main() {
    return 0;
}
