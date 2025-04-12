#include <iostream>
#include <vector>
using namespace std;

class comparator1 {
    public :
        bool operator() (vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        }
};

vector<int> getOrder(vector<vector<int>>& tasks) {
    vector <int> ans;
    int timer = tasks[0][0];        
    int index = 0;
    priority_queue<vector <int> , vector <vector <int> >, comparator> pq1;
    sort(tasks.begin(), tasks.end(), comparator1());
    ans.push_back(0);
    for (int i = 1; i < tasks.size(); i++) {
          
    }      
}

int main() {
    return 0;
}
