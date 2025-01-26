#include <iostream>
#include <vector>
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
        if (arr[j] > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quickSort(vector <int> &nums, int p, int r) {
    if (p < r) {
        int q = partition(nums, p, r);
        quickSort(nums, p, q - 1);
        quickSort(nums, q + 1, r);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> nums(n);
        for (int i = 0;i < n; i++) {
            cin >> nums[i];
        }
        quickSort(nums, 0, n - 1);
        for (auto i : nums) {
            cout << i << "\t";
        }
        cout << endl;
    }
    return 0;
}
