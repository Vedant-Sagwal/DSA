#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

int maxPathSum(TreeNode* root) {
    //base case
    if (root == NULL ) {
        return 0;
    }
    if (root->left== NULL && root->right == NULL) {
        return root->val;
    }

    //left
    int left = maxPathSum(root->left);
    //right
    int right = maxPathSum(root->right);

    int sum = left + right + root->val;

    if (sum > left && sum > right && sum > root->val) {
        return sum;
    }
    else {
        //root is decreasing the value of sum
        if (root->val < 0) {
            if (root->left && root->right) {
                return max(max(left, right), root->val);
            }
            else if (root->left && root->right == NULL) {
                return max(left, root->val);
            }
            else {
                return max(root->val, right);
            }
        }
        else {
            return root->val + max(left, right);
        }
    }
}

int main() {
    return 0;
}
