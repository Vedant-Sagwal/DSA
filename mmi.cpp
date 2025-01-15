#include <iostream>
using namespace std;

int EEA(int a, int b, int &x, int &y) {
    if (a == 0) {
        if (b == 0) {
            return -1;
        }
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = EEA(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}
int MMI(int a, int m) {
    if (m == 1) {
        return -1;
    }
    int x, y, gcd;
    if (a < m) {
        gcd = EEA(a, m, x, y); 
    }
    else {
        gcd = EEA(m, a, y, x);
    }
    if (gcd != 1) {
        cout << "No Solution Possible" << endl;
        return -1;
    } 
    return (x % m + m) % m;
}
int main() {
    int a, m;
    cout << "Enter a and m : " << endl;
    cin >> a >> m;
    cout << "MMI : " << MMI(a, m) << endl;
    return 0;
}
