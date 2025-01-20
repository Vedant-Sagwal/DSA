#include <iostream>
#include <vector> 
#include <climits>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

bool multiFlair(int n, int m, vector <vector <int>  > tuple) {
    if (gcd(n, 8) == 1) {
        return true;
    }
    return false; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; 
        cin >> n >> m;
        vector <vector <int> > tuple(n, vector <int> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> tuple[i][j];
            }
        }
        if (multiFlair(n, m, tuple) == true) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
