#include <iostream>
#include <vector>
#include <string>
#include <priority_queue>
using namespace std;
class compare {
    public:
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        }
};

vector <vector <string> >groupAnagrams(vector <string> &strs) {
    vector <vector <string> > ans;
    unordered_map<string, vector <string> > m1;
    for (auto i : strs) {
        vector <int> v1(26, 0);
        for (auto j : i) {
            v1[j - 'a']++;
        }
        string key = to_string(v1[0]);
        for (int i = 1; i < 26; i++) {
            key += "," + to_string(v1[i]);
        }
        m1[key].push_back(i);
    }
    for (auto i : m1) {
        ans.push_back(i.second);
    }
    return ans;
}

vector <int> topKFrequent(vector <int> &nums, int k) {
    vector <int> ans;
    priority_queue<pair<int, int> , vector <pair<int, int > > ,compare>   pq1;
    for (int i = 0; i < k; i++ ) {
        pq1.push(make_pair(0, 0));
    }
    unordered_map<int, int> m1;
    for (auto  i : nums) {
        m1[i]++;
    }
    for (auto i : m1) {
        if (i.second > pq1.top().second) {
            pq1.pop();
            pq1.push(make_pair(i.first, i.second));
        }

    }
    while (!pq1.empty()) {
        ans.push_back(pq1.top().first); 
        pq1.pop();
    }
    return ans;
}

string encode (vector <string> &strs) {
    string ans = "";
    for (int i = 0; i < strs.size(); i++) {
        ans += "$" + strs[i];
    }
    return ans;
}


vector <string> decode(string s) {
    vector <string> ans;
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '$') {
            ans.push_back(temp);
        }
        else {
            ans.push(s[i]);
        }
    }
    return ans;
}

int main() {
    return 0;
}
