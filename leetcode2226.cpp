#include <iostream>
#include <vector>
using namespace std;

bool max_candies(vector<int> &candies, long long k, long long int ans) {
    if (ans == 0) {
        return true;
    }
    long long int sum = 0;
    for (auto i : candies) {
        sum += (i / ans);
    }
    if (sum >= k) {
        return true;
    }
    return false;
}

int maximumCandies(vector<int>& candies, long long k) {
    int maxi = INT_MAX;
    for (auto i : candies) {
        if (i > maxi) {
            maxi = i;
        }
    }
    int left = 0;
    int right = maxi;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (max_candies(candies, k, mid)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return right;
}

int main() {
    return 0;
}
