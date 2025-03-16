#include <iostream>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int i = 0; 
    unordered_map<int, bool> visited;
    for (i = 0; (i <= k) && (i < nums.size()); i++) {
        if (!visited[nums[i]]) {
            visited[nums[i]] = true;
        }
        else {
            return true;
        }
    }
    for (i = k + 1; i < nums.size(); i++) {
        visited[nums[i - k - 1]] = false;
        if (!visited[nums[i]]) {
            visited[nums[i]] = true;
        }
        else {
            return true;
        } 
    }
    return false;
}

int main() {
    return 0;
}
