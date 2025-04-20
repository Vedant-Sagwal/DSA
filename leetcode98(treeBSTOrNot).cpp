#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

int maxi(TreeNode* root) {
    if (root == NULL) {
        return INT_MIN;
    }
    while (root != NULL) {
        root = root -> right;
    }
    return root->val;
}

int mini(TreeNode* root) {
    if (root == NULL) {
        return INT_MAX;
    }
    while (root != NULL) {
        root = root -> left;
    }
    return root->val;
}

bool isValidBST(TreeNode* root) {
    //base case
    if (root == NULL) {
        return true;
    }

    bool left = false;
    bool right = false;
    //check current root
    if (root->left && (root->val > (root->left ->val))) {
        int maxi_left = maxi(root->left);
        if (maxi_left < root->val) {
            left = isValidBST(root->left);
        }
    }
    else if (!root->left) {
        left = true;
    }
    if (root->right && (root->val < (root->right -> val))) {
        int mini_right = mini(root->right);
        if (mini_right > root->val) {
            right = isValidBST(root->right);
        }
    }
    else if (!root->right) {
        right = true;
    }

    if (left && right) {
        return true;
    }
    return false;
}

int main() {
    return 0;
}
