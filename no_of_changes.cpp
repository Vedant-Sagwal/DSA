#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool solve(vector <int> &money) {
    int n = money.size();
    if (money[0] != 5) {
        return false;
    }
    int fives = 0;
    int tens = 0;
    for (int i = 0; i < n; i++) {
        //if 5
        if (money[i] == 5) {
            fives++;
        }
        else if (money[i] == 10) {
            if (fives == 0) {
                return false;
            }
            else {
                tens++;
                fives--;
            }
        }
        else {
            if (tens) {
                tens--;
                if (fives) {
                    fives--;
                }
                else {
                    return false;
                }
            }
            else {
                if (fives >= 3) {
                    fives = fives - 3;
                }
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> money(n, 0);
        for (int i = 0; i < n;i++ ) {
            cin >> money[i];
        }
        cout << boolalpha << solve(money) << endl;
    }
    return 0;
}

/*
10
5
5 5 5 10 10
4
10 5 5 5
25
5 5 5 5 10 10 5 5 5 5 20 5 5 5 5 10 10 5 5 5 5 5 5 5 20

*/
