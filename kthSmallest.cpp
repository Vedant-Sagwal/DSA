#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector <int> nums, int k) {
    //max heap 
    priority_queue<int, vector <int> > pq1; 
    for (int i = 0; i < k; i++) {
        pq1.push(nums[i]);     
    }
    for (int i = k ;i < nums.size(); i++) {
        if (nums[i] <  pq1.top()) {
            pq1.pop(); 
            pq1.push(nums[i]);
        } 
    }
    return pq1.top();
}
int kthLargest(vector <int> nums, int k) {
    //min heap 
    priority_queue<int, vector <int> , greater<int> > pq1; 
    for (int i = 0; i < k; i++) {
        pq1.push(nums[i]);     
    }
    for (int i = k ;i < nums.size(); i++) {
        if (nums[i] >  pq1.top()) {
            pq1.pop(); 
            pq1.push(nums[i]);
        } 
    }
    return pq1.top();
}
int kthSmallestQuick(vector <int> nums, int k) {
    }
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector <int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << kthSmallest(nums, k) << endl;
    }
    return 0;
}
