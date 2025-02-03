#include <iostream>
#include <vector>
#include <string>
using namespace std;

string gcdOfStrings(string str1, string str2) {
    string ans = "";
    int i = 0;
    int j = 0;
    while (i < str1.length() && j < str2.length()) {
        if (str1[i] == str2[j]) {
            ans.push_back(str1[i]);
            i++;
            j++;
        }
        else {
            return "";
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1;
        string str2;
        cin >> str1 >> str2;
        cout << "Ans : " << endl;
        cout << gcdOfStrings(str1, str2) << endl;
    }
}
