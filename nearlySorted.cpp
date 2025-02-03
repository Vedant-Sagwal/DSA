#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void nearlySorted(int arr[], int n, int k) {
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

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        nearlySorted(arr, n, k);
        for (auto i : arr) {
            cout << i << "  ";
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
