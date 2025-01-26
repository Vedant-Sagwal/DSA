#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

//O{(n+m)lg(n + m)}
vector <pair<int, int> >  solve(vector <int> &a, vector<int> &b, int k) {
    vector <pair<int, int> > ans;
    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end()); 
    int i = 0;
    int j = b.size() - 1;
    while (i < a.size() && j >= 0) {
        if (a[i] + b[j] == k) {
            ans.push_back(make_pair(a[i], b[j]));
            i++;
            j--;
        }
        else if (a[i] + b[j] < k) {
            i++;
        }
        else {
            j--;
        }
    }
    return ans;
}

bool binarySearch(vector <int> &b,int start, int end,  int goal) {
    //base case
    if (start > end) {
        return false;
    }
    int mid = (start + end) / 2;
    if (b[mid] == goal) {
        return true;
    }
    else if (b[mid] > goal) {
        return binarySearch(b, start, mid - 1, goal);
    }
    else {
        return binarySearch(b, mid + 1, end, goal);
    }
}

bool solve1(vector <int> &a, vector<int> &b, int k) {
    sort(b.begin(), b.end()); 
    for (int i = 0; i < a.size(); i++) {
        int one = a[i];
        int two = k - a[i];
        if (binarySearch(b, 0, b.size() - 1, two) == true) {
            return true;
        }
    } 
    return false; 
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector <int> a(n);
        vector <int> b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        } 
        cout << std::boolalpha << solve1(a, b, k) << endl;
    }
    return 0;
}
