#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void swap(int *a, int*b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector <int> &arr, int p, int r) {
    int pivot = arr[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (arr[j] >=  pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

int solve(vector<int> &nums, int p, int n, int k) {
    //base case
    if (p >= n) {
        for (auto i : nums) {
            cout << i << "\t";
        }
        cout << endl;
        return -1;
    }
    int partition1 = partition(nums, p, n - 1); 
    if (partition1 == k - 1) {
        for (auto i : nums) {
            cout << i << "\t";
        }
        cout << endl;
        return nums[partition1];
    }
    else if (partition1 > (k - 1)) {
        return solve(nums, p, partition1, k);
    }
    else {
        return solve(nums, partition1 + 1, n,  k);
    }
}

int kthSmallestQuick(vector <int> &nums, int k) {
    return solve(nums, 0, nums.size(),  k);
}

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
        cout << kthSmallestQuick(nums, k) << endl;
    }
    return 0;
}
