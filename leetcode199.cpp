#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

vector<int> rightSideView(TreeNode* root) {
    if (root == NULL) {
        return {};
    }
    vector <int> ans;
    queue<TreeNode*> q1;
    q1.push(root);
    while (!q1.empty()) {
        int size = q1.size();
        vector <int> temp;
        for (int i = 0 ; i < size; i++) {
            TreeNode*  top = q1.front();
            q1.pop();
            temp.push_back(top->val);
            if (top->left) {
                q1.push(top->left);
            }
            if (top->right) {
                q1.push(top->right);
            }
        }
        ans.push_back(temp[temp.size() - 1]);
    }
    return ans;
}

int main() {
    return 0;
}
