#include <iostream>
#include <vector>
#include <string>
using namespace std;

int numberOfSubstrings(string s) {
    int ans = 0;
    int a_included = 0;        
    int b_included = 0;        
    int c_included = 0;        
    int i = 0;
    int j = 0;
    for (j = 0; j < s.length(); j++) {
        if (s[j] == 'a') {
            a_included++;
        }
        if (s[j] == 'b') {
            b_included++;
        }
        if (s[j] == 'c') {
            c_included++;
        }
        while ((a_included > 0) && (b_included > 0) && (c_included > 0)) {
            ans += (s.length() - j); 
            if (s[i] == 'a') {
                a_included--;
            }
            if (s[i] == 'b') {
                b_included--;
            }
            if (s[i] == 'c') {
                c_included--;
            }
            i++;
        }
    }
    return ans;
}

int main() {
    return 0;
}
