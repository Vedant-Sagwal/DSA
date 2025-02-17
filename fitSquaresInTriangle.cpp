#include <iostream>
#include <cmath.h>
using namespace std;

int squares_in_triangle(int n) {
    //Base Case
    if (n == 1) {
        return 0;
    }
    if (n == 2 ) {
        return 0;
    }
    if (n % 2 == 0) {
        return squares_in_triangle(n - 1);
    }
    int temp = squares_in_triangle(n - 2);
    int ans = temp;
    float a1 = n / 2;
    float a2 = (n - 2) / 2;
    if (((a1 + a2) / 2 ) % 2 == 0) {
        ans += 1; 
    }
    int a3 = sqrt((n - 1) * (n - 1) + (4));
    int a4 = sqrt((n - 3) * (n - 3) + (4));

    if (a3 > )
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n; 
        cout << squares_in_triangle(n) << endl;
    }
    return 0;
}
