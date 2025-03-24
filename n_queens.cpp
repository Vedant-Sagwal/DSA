#include<iostream>
#include <vector>
using namespace std;

bool can_place(int &n, int &row, int &col, vector <int> &x) {
    if (row == 0) {
        return true;
    }
    //col check
    for (int i = 0; i < row; i++) {
        if (x[i] == col) {
            return false;
        }
    }
    //diagonal check
    int i = row;
    int j = col;
    while (i != 0 && j >= 0) {
        if ((x[i - 1] == j - 1)) {
            return false;
        }
        i--;
        j--;
    }
    i = row;
    j = col;
    while (i != 0 && j < n) {
        if ((x[i - 1] == j + 1)) {
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void n_queen_placement(int n, int row, vector <int> &x,int &count) {
    if (row >= n) { 
        for (auto i : x) {
                cout << i + 1 << " " ; 
        }
        cout << endl;
        count++;
        return ; 
    }
    // i => columns
    for (int i = 0; i < n; i++) {
        if (can_place(n, row, i, x)) {
            x[row] = i;
            n_queen_placement(n, row + 1, x ,count);
            x[row] = -1;
        } 
   }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> ans(n , -1);
        int count = 0;
        n_queen_placement(n, 0, ans, count); 
        cout << endl << count << endl;
    }
    return 0;
}
