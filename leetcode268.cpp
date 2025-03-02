#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int xor1 = 0;        
    for (int i = 0; i < nums.size(); i++) {
        xor1 ^= nums[i];
    }
    for (int i = 0; i <= nums.size(); i++) {
        xor1 ^= i;
    }
    return xor1;
}

int main() {
    return 0;
}
