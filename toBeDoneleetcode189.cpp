#include <iostream>
#include <vector>
using namespace std;
//
//void rotate(vector<int>& nums, int k) {
//    int n = nums.size();
//    vector <int> temp(nums.size(), 0);
//    for (int i = 0; i < nums.size(); i++) {
//        temp[(i + k) % n] = nums[i]; 
//    }
//    nums = temp;
//}

void rotate(vector<int> &nums, int k) {
    int count = 0;
    int n = nums.size();
    int temp = nums[0];
    int i = 0;
    while (count < n) {
        int next_index = (i + k) % n;
        int temp1 = nums[next_index];
        nums[next_index] = temp;
        temp = temp1;
        i = next_index;
        count++;
    }
}

int main() {
    return 0;
}
