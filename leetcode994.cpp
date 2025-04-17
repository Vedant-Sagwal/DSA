#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int count = 0;
    int m = grid.size();
    int n = grid[0].size();
    //simpy BFS
    //first find a rotten orange
    queue <pair<int, int> > q1;
    for (int i = 0 ; i < m; i++) {
        for (int j = 0 ; j < n; j++) {
            if (grid[i][j] == 2) {
                q1.push(make_pair(i, j));
            }
        }
    }
    while (!q1.empty()) {
        int size1 = q1.size();
        bool flag= false;
        for (int a = 0; a < size1; a++) {
            pair<int, int > p1 = q1.front();
            int i = p1.first;
            int j = p1.second;
            q1.pop();
            //left
            if (j - 1 >= 0) {
                if (grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 2;
                    flag = true;
                    q1.push(make_pair(i, j  - 1));
                }
            }
            //right
            if (j + 1 < n) {
                if (grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 2;
                    flag = true;
                    q1.push(make_pair(i, j  + 1));
                }
            }
            //top
            if (i - 1 >= 0 ) {
                if (grid[i - 1][j] == 1) {
                    grid[i  - 1][j] = 2;
                    flag = true;
                    q1.push(make_pair(i  - 1, j));
                }
            }
            //bottom
            if (i + 1 < m) {
                if (grid[i + 1][j] == 1) {
                    grid[i  + 1][j] = 2;
                    flag = true;
                    q1.push(make_pair(i + 1, j));
                }
            }

        }
        if (flag) {
            count++;
        }
    }
    for (int i = 0 ; i < m; i++) {
        for (int j =  0; j < n; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return count;
}

int main() {
    return 0;
}
