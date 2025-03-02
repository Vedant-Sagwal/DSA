#include <iostream>
using namespace std;
//
//int getSum(int a, int b) {
//    int ans = 0;
//    int carry = 0;
//    int count = 0;
//    while (a != 0 && b != 0) {
//        int sum = ((a & 1) ^ (b & 1) ^ (carry));
//        carry = ((a & 1) & (b & 1)) | (carry & ((a & 1) ^ (b & 1)));
//        a = a >> 1;
//        b = b >> 1;
//        ans += sum * (int(pow(2, count)));
//        count++;
//    }        
//   
//    while (a != 0) {
//        int sum = ((a & 1) ^ (b & 1) ^ (carry));
//        carry = ((a & 1) & (b & 1)) | (carry & ((a & 1) ^ (b & 1)));
//        a = a >> 1;
//        b = b >> 1;
//        ans += sum * (int(pow(2, count)));
//        count++;
//    }    
//    while (b != 0) {
//        int sum = ((a & 1) ^ (b & 1) ^ (carry));
//        carry = ((a & 1) & (b & 1)) | (carry & ((a & 1) ^ (b & 1)));
//        a = a >> 1;
//        b = b >> 1;
//        ans += sum * (int(pow(2, count)));
//        count++;
//    }    
//    if (carry != 0) {
//        ans += carry * (int(pow(2, count)));
//    }
//    return ans;
//}

int getSum(int a, int b) {
    int carry = 0;
    while (b != 0) {
        carry = (a & b)<<1;
        a = (a^b); 
        b = carry;
    }
    return a;
}

int main() {
    return 0;
}
