#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void heapify(vector <int> &a, int i, int n) {
    int left = 2 *i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, largest, n);
    }
}

void buildHeap(vector <int> &a, int n) {
    for (int i = n / 2; i >= 0; i--) {
        heapify(a, i, n);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    for (int i = 0; i < m; i++) {
        a.push_back(b[i]);
    }
    buildHeap(a, a.size());
    return a;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector <int> a;
        vector <int> b;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            a.push_back(num);
        }
        for (int i = 0; i < m; i++) {
            cin >> num;
            b.push_back(num);
        }
        vector <int> ans = mergeHeaps(a, b, n, m);
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
