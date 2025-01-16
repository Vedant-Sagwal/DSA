#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int kadane(vector <int> &nums) {
    int bestSum = 0, currSum = 0;
    bool isPositive = false;
    int mini = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            isPositive = true;
        }
        mini = max(mini, nums[i]);
        if (nums[i] + currSum < 0) {
            currSum = 0;
        } 
        else {
            currSum += nums[i];
            if (currSum > bestSum) {
                bestSum = currSum;
            }
        }
    }
    if (isPositive == false) {
        return mini;
    }
    return bestSum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n; //size of array
        vector <int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << kadane(nums) << endl;
    }
    return 0;
}
