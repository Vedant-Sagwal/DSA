#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

class comp {
    public:
        bool operator() (pair<int, float> a, pair<int, float> b) {
            return a.second < b.second; 
        }
};

float length(int a, int b) {
    return (sqrt((a*a) + (b * b)));
}

pair<int, int> kthClosest(vector<vector<int>>& points, int k) {
    vector <vector< int> > ans;
    //max heap
    priority_queue <pair<float, int> > pq1;
    for (int i = 0; i < k; i++) {
        pair<float, int> p1 = make_pair(length(points[i][0], points[i][1]), i);
        pq1.push(p1);
    } 
    for (int i = k; i < points.size(); i++ ) {
        float lengthTemp = length(points[i][0], points[i][1]);
        if (lengthTemp < pq1.top().first) {
            pq1.pop();
            pq1.push(make_pair(lengthTemp, i));
        }
    }
    return make_pair (points[pq1.top().second][0], points[pq1.top().second][1]);
}

vector <vector< int> > kClosest (vector <vector <int > > &points, int k) {
    if (k == points.size ()) {
        return points;
    }
    vector <vector <int > > ans;
    for (int i = 1; i <= k; i++ ) {
        pair<int, int> temp = kthClosest (points, i); 
        vector <int> tempVec;
        tempVec.push_back(temp.first);
        tempVec.push_back(temp.second);
        ans.push_back(tempVec);
    }
    return ans;
}

int main() {
    return 0;
}
