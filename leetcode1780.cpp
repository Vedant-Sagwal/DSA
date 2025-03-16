#include <iostream>
using namespace std;

bool checkPowersOfThree(int n) {
    if (n % 3 != 0 && (n - 1) % 3 !=0) {
        return false;
    }
    while (n != 0) {
        if (n % 3 != 0 && (n - 1) % 3 != 0) {
            return false;
        } 
        if (n % 3 == 0) {
            n = n / 3;
        }
        else if ((n - 1) % 3 == 0) {
            n = (n - 1) / 3;
        }
        else {
            return false;
        }
    }         
    return true;
}

int main() {
    return 0;
}
