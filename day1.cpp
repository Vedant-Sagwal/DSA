#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsDuplicate(vector <int> &nums) {
    unordered_map<int, bool> m1;
    for (auto i : nums) {
        if (m1[i] == false) {
            m1[i] = true;
        }
        else {
            return true;
        }
    }
    return false;
}

bool isAnagram(string s, string t) {
    vector <int> v1(26, 0);
    //1 based indexing of all alphabets
    for (auto i : s) {
        int index = i - 'a';
        v1[index]++;
    }
    vector <int> v2(26, 0);
    for (auto i : t) {
        int index = i - 'a';
        v2[index]++;
    }
    for (int i = 0; i < 26; i++) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

vector <int> twoSum(vector <int> &nums, int target) {
    vector <int> ans;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) { 
            if (nums[i] + nums[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}

vector <int> twoSum1(vector <int> &nums, int target) {
    vector <int> ans; //O(1)
    unordered_map<int, pair<int, bool> > m1; //O(n)
    for (int i = 0; i < nums.size(); i++) { //O(n)
        int toFound = target - nums[i];
        if (m1[nums[i]].second == true) {
            ans.push_back(m1[nums[i]].first - 1);
            ans.push_back(i);
        }
        m1[toFound] = make_pair(i + 1, true);
    }
    return ans;
}

int main() {
    vector <int> temp; 
    temp.push_back(3);
    temp.push_back(21);
    temp.push_back(5);
    temp.push_back(12);
    temp.push_back(23);
    temp.push_back(8);
    temp.push_back(7);
    temp.push_back(4);
    int target = 15;
    vector <int> ans = twoSum(temp, target);
    for (auto i : ans) {
        cout << i << "  ";
    }
    return 0;
}
