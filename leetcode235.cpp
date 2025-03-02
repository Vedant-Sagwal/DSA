#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestorRec(TreeNode* root, TreeNode* p, TreeNode* q) {
    if ((root->val >= p->val && root->val <= q->val) || (root->val <= p->val && root->val >= q->val)) {
        return root;
    }
    else if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    else {
        return lowestCommonAncestor(root->right, p, q);
    }
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root != NULL) {  
        if ( (root->val >= p->val && root->val <= q->val) || (root->val <= p->val && root->val >= q->val) ) {
            return root;
        }
        else if (root->val > p->val && root->val > q->val) {
            root = root -> left;
        }
        else {
            root = root->right;
        }
    }
    return root;
}

int main() {
    return 0;
}
