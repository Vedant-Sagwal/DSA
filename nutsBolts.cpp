#include <iostream>
using namespace std;

int partition(char arr[], int low, int high, char pivot) {
  int i = low;
  char temp1, temp2;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      temp1 = arr[i];
      arr[i] = arr[j];
      arr[j] = temp1;
      i++;
    } else if (arr[j] == pivot) {
      temp1 = arr[j];
      arr[j] = arr[high];
      arr[high] = temp1;
      j--;
    }
  }
  temp2 = arr[i];
  arr[i] = arr[high];
  arr[high] = temp2;

  return i;
}

void solve(char nuts[], char bolts[], int low, int high) {
  if (low < high) {

    int pivot = partition(nuts, low, high, bolts[high]);

    partition(bolts, low, high, nuts[pivot]);

    solve(nuts, bolts, low, pivot - 1);
    solve(nuts, bolts, pivot + 1, high);
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char nuts[n];
    char bolts[n];
    for (int i = 0; i < n; i++) {
      cin >> nuts[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> bolts[i];
    }
    solve(nuts, bolts, 0, n - 1);
    for (int i = 0; i < n; i++) {
      cout << nuts[i] << " :: " << bolts[i] << "\n";
    }
  }
}

