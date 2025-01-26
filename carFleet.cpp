#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class comp{
    public:
        bool operator() (pair<int, int> p1, pair<int, int> p2) {
            return p1.first < p2.first;
        }
};

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    int ans = n;
    vector <pair<int, int> > storage;
    stack<int> s1;
    for (int i = 0; i < speed.size(); i++) {
        storage.push_back(make_pair(position[i], speed[i]));
    }
    sort(storage.begin(), storage.end(), comp());
    for (int i = 0; i < storage.size(); i++) {
        int time = ((target - storage[i].first) / storage[i].second);
        storage[i].second = time; 
        while (!s1.empty() && time > s1.top()) {
            s1.pop();
        }
        if (!s1.empty() && time <= s1.top()) {
            ans--;
        }
        s1.push(time);
    } 
    return ans;
}   

int main() {
    return 0;
}
