#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maximumCount(vector<int>& nums) {
    int neg = 0;
    int pos = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            continue;
        }
        //negative
        if (nums[i] < 0) {
            neg++;    
        }
        //positive
        else {
            pos++;
        }
    }
    return max(neg, pos);
}

int main() {
    retur 0;
}
