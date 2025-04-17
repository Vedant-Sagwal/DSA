#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
    public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

Node* solve(vector <vector <int> > &grid, int left_start, int left_end, int right_start , int right_end) {
    int n = grid.size();
    //Base case

    //check if all values of grid equal
    bool flag = true;
    int temp = grid[left_start][right_start];
    for (int i = left_start; i <= left_end; i++) {
        for (int j = right_start; j <= right_end ; j++) {
            if (grid[i][j] != temp) {
                flag = false;
                break;
            }
        }
        if(flag== false ) {break;}
    }
    //divide into 4 subparts
    Node* root = NULL;
    if (flag == false )  {
        root = new Node(true, false);
        int left_mid = (left_start + left_end) / 2;
        int right_mid = (right_start + right_end) / 2;
        root->topLeft = solve(grid, left_start, left_mid , right_start, right_mid);
        root->bottomLeft = solve(grid, left_mid + 1 , left_end, right_start, right_mid);
        root->topRight = solve(grid, left_start, left_mid, right_mid + 1, right_end);
        root->bottomRight = solve(grid, left_mid + 1, left_end, right_mid + 1, right_end);
    }
    else {
        root = new Node(temp, true, NULL, NULL, NULL, NULL);
    }
    return root;
}

Node* construct(vector<vector<int>>& grid) {
    return solve(grid, 0, grid.size() - 1, 0, grid.size() - 1);
}

int main() {
    return 0;
}
