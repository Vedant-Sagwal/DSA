#include <iostream>
#include <stack>
using namespace std;

string removeDuplicates(string s) {
    string ans = ""; 
    stack<char> s1;
    for (int i = 0; i < s.length(); i++) {
        if (s1.empty()) {
            s1.push(s[i]);
        }
        else {
            char top = s1.top();
            if (top == s[i]) {
                s1.pop();
            }
            else {
                s1.push(s[i]);
            }
        }
    }
    while (!s1.empty()) {
        char top = s1.top();
        s1.pop();
        ans.push_back(top);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    return 0;
}
