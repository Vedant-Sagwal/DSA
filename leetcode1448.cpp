#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode* {
    int val;
    TreeNode* left;
    TreeNode* right;
};

int solve(TreeNode* root, int maxi) {
    //base case
    if (root == NULL) {
        return 0;
    }
    int ans = 0;
    if (root->val >= maxi) {
        ans++;
    }

    //go for left and right
    int left = solve(root->left, max(root->val , maxi));
    int right = solve(root->right, max(root->val , maxi));
    ans += left + right;
    return ans;
}

int goodNodes(TreeNode* root) {
    return solve(root, INT_MIN);
}

int main() {
    return 0;
}
