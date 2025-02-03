#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int * arr, int p, int r) {
    //Base Case
    if (p > r) {
        return -1;
    }
    int mid = (p + r) / 2;
    if (arr[mid] == 0 && arr[mid - 1] == 1) {
        return mid; 
    }
    else if (arr[mid] == 1) {
        return binarySearch(arr, mid + 1, r);
    }
    else {
        return binarySearch(arr, p, mid - 1);
    }
}


int firstZero(int * arr,int p, int i) {
    if (p > i) {
        return -1;
    }
    if (arr[i] == 0 && arr[i - 1] == 1) {
        return i;
    }
    int nextIndex = 2* i;
    if (arr[i] == 1) {
        return firstZero(arr,i, nextIndex);
    }
    else {
        return binarySearch(arr, i / 2, i);
    } 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i= 0; i < n; i++) {
            cin >> arr[i]; 
        }
        cout << "Ans : " <<   firstZero(arr, 0, 1) << endl;
    }
    return 0;
}
