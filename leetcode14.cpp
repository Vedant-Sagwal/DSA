#include <iostream>
#include <vector>
#include <string>

string longestCommonPrefix(vector<string>& strs) {
    string ans = "";
    int count = 0; 
    int maxString  = 0;
    if (strs.size() == 1) {
        ans = strs[0];
        return ans;
    }
    for (int i = 0; i < strs.size(); i++) {
        if(strs[i].length() > maxString) {
            maxString = strs[i].length();
        }
    }
    while (count < maxString) {
        char checker = strs[0][count];
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i][count] != checker) {
                return ans;                    
            }
       }
        ans.push_back(checker);
        count++;
    }
    return ans;
}

int main() {
    return 0;
}
