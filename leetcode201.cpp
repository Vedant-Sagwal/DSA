#include <iostream>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int ans = 0;        
    for (int i = 0; i < 32; i++) {
        int bit = (left>>i) & 1;
        if (!bit) {
            continue;
        }  

    }
}

int main() {
    return 0;
}
