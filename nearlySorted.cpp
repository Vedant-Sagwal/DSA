#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void nearlySorted(int arr[], int n, int k) {
    //min heap
    priority_queue<int, vector <int>, greater<int> > pq1;
    for (int i = 0; i < k + 1; i++) {
        pq1.push(arr[i]);
    }
    int a = 0;
    for (int i = k + 1; i < n; i++) {
        int mini = pq1.top();
        pq1.pop();
        arr[a++] = mini;
        pq1.push(arr[i]);
    }
    while (!pq1.empty()) {
        arr[a++] = pq1.top();
        pq1.pop();
    }
}

void merge(vector <int> &arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int arr1[n1];
    int arr2[n2];

    for (int i = 0 ; i < n1; i++) {
        arr1[i] = arr[p + i];
    }
    for (int i = 0; i < n2; i++) {
        arr2[i] = arr[q + i + 1];
    }
    int k = p;
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr[k++] = arr1[i++];
        }
        else {
            arr[k++] = arr2[j++];
        }
    }
    while (i < n1) {
        arr[k++] = arr1[i++];
    }
    while (j < n2) {
        arr[k++] = arr2[j++];
    }
}

void mergeSort(vector <int> &arr, int p ,int r ) {
    if (p >= r) {
        return ;
    }
    int q = (p + r) / 2;
    mergeSort(arr, p, q);
    mergeSort(arr, q + 1, r);
    merge(arr, p, q, r);
}

void nearlySortedMerge(vector <int> &arr,int k) { 
    int i;
    int n = arr.size();
    for (int i = 0; i < n; i += k) {
        int right = min(i + k - 1, n - 1);
        mergeSort(arr, i, right);
    }  
    for (int i = 0; i < n; i+= k - 1) {
        int r = min(i + (2 * k) - 1, n - 1);
        int mid = (i + r) / 2;
        merge(arr, i, mid, r);
    }
}
//
//int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        int k;
//        cin >> k;
//        int arr[n];
//        for (int i = 0; i < n; i++) {
//            cin >> arr[i];
//        }
//        nearlySortedMerge(arr, 0, n - 1, k);
//        for (auto i : arr) {
//            cout << i << "  ";
//        }
//        cout << endl;
//    }
//    return 0;
//}
//

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        nearlySortedMerge(arr, k);

        for (auto val : arr) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
2
12 3
4 2 3 1 7 6 5 8 11 10 9 12
6 2
2 1 0 5 4 3
5 3
7 8 5 1 6
*/
