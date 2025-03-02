#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b) {
    string sum = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;        
    int i = 0;
    int j = 0;
    while (i < a.length() && j < b.length()) {
        int a1 = a[i] - '0';
        int b1 = b[j] - '0';
        int ans = (a1 + b1 + carry);
        if (ans >= 2) { 
            ans = ans % 2;
            carry = 1;
        }
        else {
            carry = 0;
        }
        sum.push_back(ans + '0');
        i++;
        j++;
    }
    while (i < a.length()) {
        int a1 = a[i] - '0';
        int ans = a1 + carry;
         if (ans >= 2) { 
            ans = ans % 2;
            carry = 1;
        }
         else {
            carry = 0;
         }
        sum.push_back(ans + '0');
        i++;
    }
    while (j < b.length()) {
        int b1 = b[j] - '0';
        int ans = b1 + carry;
         if (ans >= 2) { 
            ans = ans % 2;
            carry = 1;
        }
         else {
            carry = 0;
         }
        sum.push_back(ans + '0');
        j++;
    }
    if (carry) {
        sum.push_back(carry + '0');
    }
    reverse(sum.begin(), sum.end());
    return sum;
}

int main() {
    return 0;
}
