#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class comparator {
    public:
        bool operator() (pair<int, int> p1, pair<int, int> p2) {
            return p1.first < p2.first;
        }
};

int activitySelection(vector<int> &start, vector<int> &end) {
    int count = 0;
    vector <pair<int, int> > v1;
    for (int i = 0; i < end.size(); i++) {
        v1.push_back(make_pair(end[i], start[i])); 
    }
    sort(v1.begin(), v1.end(), comparator());
    int stop = 0;
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i].second > stop) {
            stop = v1[i].first;
            count++;
        } 
    }
    return count;
}

int main() {
    return 0;
}
