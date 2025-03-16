#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string add_two_strings(string a, string b) {
    string ans = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while (i >= 0 && j >= 0) {
        int a1 = a[i] - '0';
        int b1 = b[j] - '0';
        int sum = a1 + b1 + carry;
        carry = sum / 10;
        ans.push_back((sum % 10) + '0');
        i--;
        j--;
    }
    while (i >= 0) {
        int a1 = a[i] - '0';
        int sum = a1 + carry;
        carry = sum / 10;
        ans.push_back((sum % 10) + '0');
        i--;
    }
    while (j >= 0) {
        int b1 = b[j] - '0';
        int sum = b1 + carry;
        carry = sum / 10;
        ans.push_back((sum % 10) + '0');
        j--;
    }
    if (carry != 0) {
        ans.push_back(carry + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string vector_to_string(vector<string > &v1) {
    string ans = "";
    if (v1.size() == 0) {
        return "";
    } 
    ans = v1[0];
    for (int i = 1; i < v1.size(); i++) {
        ans = add_two_strings(ans, v1[i]);
    }
    return ans;
}

string solve(string num1, string num2) {
    string ans = "";
    int n1 = num1.length();
    int n2 = num2.length();
    int i = num1.length() - 1;
    vector <string> v1;
    while (i >= 0) {
        string temp = "";
        for (int a = i; a < n1 - 1;a++) {
            temp.push_back('0');
        }
        int carry = 0;
        for (int j = n2 -1; j >= 0; j--) {
            int a = num1[i] - '0';          
            int b = num2[j] - '0';          
            int product = a * b;
            product += carry;
            int c = product % 10;
            carry = product / 10;
            temp.push_back(c + '0');
        }
        if (carry != 0) {
            temp.push_back(carry + '0');
        }
        reverse(temp.begin(), temp.end());
        v1.push_back(temp);
        i--;
    }
    ans = vector_to_string(v1);
    int l = 0;
    while (l < ans.length() && ans[l] == '0') {
        ans.erase(0, 1);
    }
    return ans;
}

string multiply(string num1, string num2) {
    if (num1 == 0 ) {
        return num2;
    }
    if (num2 == 0) {
        return num1;
    }
    if (num1 > num2) {
        return solve(num1, num2);
    }
    else {
        return solve(num2, num1);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a1;
        string a2;
        cin >> a1 >> a2;
        cout << multiply(a1, a2) << endl;
    }
    return 0;
}
