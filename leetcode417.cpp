#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool can_reach(vector <vector <int> > &heights, int row, int col, bool &atlantic, bool &pacific) {
    //Base Case
    if (i < 0 || i > height.size() || (j < 0 || j > heights[0].size())) {
        return false;
    }
    if (row == 0) {
        pacific = true;
    }
    if (row == heights.size()) {
        atlantic = true;
    }
    if (col == 0) {
        pacific = true;
    }
    if (col == heights[0].size()) {
        atlantic = true;
    }
    bool left, right ,top, down = false;
    //left
    if ((col - 1 >= 0) && heights[row][col] >= heights[row][col - 1]) {
        left = can_reach(heights, row, col - 1);
        if (left == true) {
            pacific = true;
        }
    }
    //right
    if ((col + 1 >= 0) && heights[row][col] >= heights[row][col + 1]) {
        right = can_reach(heights, row, col + 1);
        if (right == true) {
            pacific = true;
        }
    }
    //top

    //down

}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int> > v1;
    vector <vector <int> > visited(heights,size(), vector <int> (heights[0].size(), 0));
    for (int i = 0; i < heights.size(); i++) {
        for (int j = 0; j < height[i].size(); j++) {
            bool canReach = can_reach(heights, i, j);
            if (canReach) {
                v1.push_back({i, j});
            }
        }
    }
}

int main() {
    return 0;
}
