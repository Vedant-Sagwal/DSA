#include <iostream>
using namespace std;

int reverse(int x) {
    int maxi = INT_MAX;
    int mini = INT_MIN;
    int ans = 0;
    bool isNegative = false;
    if (x < 0) {
        isNegative = true;
        if (x == mini) {return 0;}
        x = x * -1;
    }
    while (x != 0) {
        int rem = x % 10;
        if (ans > maxi || (ans) + (rem/10)  > (maxi/10)) {
            return 0;
        }
        ans = (ans * 10) + rem;
        x = x / 10;
    }
    if (ans <= maxi && ans >= mini) {
        if (isNegative) {
            return (-1 * ans);
        }
        return ans;
    }
    else {
        return 0;
    }
}

int main() {
    return 0;
}
