#include <iostream>
#include <vector>
using namespace  std;

int solve(int little) {
    int bit1 = little & (0x000000FF); 
    int bit2 = little & (0x0000FF00); 
    int bit3 = little & (0x00FF0000); 
    int bit4 = little & (0xFF000000); 
    int ans = 0;
    bit1 = bit1 << 24;
    bit2 = bit2<< 8;
    bit3 = bit3 >> 8;
    bit4 = bit4 >> 24;
    cout << bit1 << bit2 << bit3 << bit4 << endl;
    ans = bit1 | bit2 | bit3 | bit4; 
    return ans;
}

int main() {
    int little = 0x12345678;
    cout << hex <<  solve(little) << endl;
    return 0;
}
