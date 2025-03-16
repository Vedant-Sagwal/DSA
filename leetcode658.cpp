#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

Vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int> ans;
    if (k > arr.size()) {
        return {};
    }
    int j = k - 1;
    for (int i = k; i < arr.size(); i++) {
        if (abs(arr[i] - x) < abs(arr[i - k] - x)) {
            j = i;
        }
    }
    for (int a = j - k + 1; a <= j; a++) {
        ans.push_back(arr[a]);
    }
    return ans;
}

int main() {
    return 0;
}
