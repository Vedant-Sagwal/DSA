#include <iostream>
#include <vector>
#include <string>
using namespace std;

void reverseString(string &s) {
    int n = s.length();
    for (int i = 0; i <(n / 2); i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp; 
    }
}

string convertToTitle(int columnNumber) {
    string ans;
    while (columnNumber != 0) {
        columnNumber--;
        char letter = (columnNumber % 26) + 'A';
        ans.push_back(letter);
        columnNumber /= 26;
    }
    reverseString(ans);
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << convertToTitle(n) << endl;
    }
}
