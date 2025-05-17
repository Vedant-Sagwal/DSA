#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int findMedian(vector<int> &arr, int left, int n) {
  sort(arr.begin() + left, arr.begin() + left + n);

  if (n % 2 == 1) {
    return arr[left + n / 2];
  } else {
    return (arr[left + (n / 2)] + arr[left + (n / 2) - 1]) / 2;
  }
}

int partition(vector<int> &arr, int left, int right, int pivot) {
  int pivotIndex;
  for (pivotIndex = left; pivotIndex < right; ++pivotIndex)
    if (arr[pivotIndex] == pivot)
      break;
  swap(arr[pivotIndex], arr[right]);

  int storeIndex = left;
  for (int i = left; i < right; ++i) {
    if (arr[i] < pivot) {
      swap(arr[storeIndex], arr[i]);
      storeIndex++;
    }
  }
  swap(arr[storeIndex], arr[right]);
  return storeIndex;
}

int kthSmallest(vector<int> &arr, int left, int right, int k) {
  if (k > 0 && k <= right - left + 1) {
    int n = right - left + 1;

    vector<int> medians;
    int i;
    for (i = 0; i < n / 5; i++) {
      int median = findMedian(arr, left + i * 5, 5);
      medians.push_back(median);
    }
    if (i * 5 < n) {
      int median = findMedian(arr, left + i * 5, n % 5);
      medians.push_back(median);
    }

    int medOfMed;
    if (medians.size() == 1) {
      medOfMed = medians[0];
    } else {
      medOfMed =
          kthSmallest(medians, 0, medians.size() - 1, medians.size() / 2);
    }
    

    int pos = partition(arr, left, right, medOfMed);

    if (pos - left == k - 1)
      return arr[pos];
    if (pos - left > k - 1)
      return kthSmallest(arr, left, pos - 1, k);
    return kthSmallest(arr, pos + 1, right, k - pos + left - 1);
  }

  return INT_MAX;
}

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
    cout << kthSmallest(arr, 0, arr.size() - 1, k) << endl;
  }
  return 0;
}

/*
13
10 5
1 10 9 8 7 6 5 4 3 2

6 3
7 10 4 3 20 15

5 3
1 2 3 4 5

5 3
5 4 3 2 1

5 3
7 7 7 7 7

6 1
7 10 4 3 20 15

6 6
7 10 4 3 20 15

15 8
11 52 37 45 26 98 74 63 21 19 33 58 67 72 84

1 1
42

2 1
42 17

7 4
-10 -5 0 5 10 15 20

10 9
12 35 87 44 69 23 56 78 90 11

11 6
42 27 18 35 89 64 53 71 96 12 38
*/

/*
5
7
3
3
7
3
20
52
42
17
5
87
42
*/