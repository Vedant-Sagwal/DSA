#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* solve(vector <int> &preorder, vector<int> &inorder, int pre_start, int pre_end, int in_start, int in_end) {
    //Base Case
    if (pre_start > pre_end|| in_start > in_end) {
        return NULL;
    }
    TreeNode* root = NULL;
    root = new TreeNode();
    root->val = preorder[pre_start];
    int i = in_start;
    while (i <= in_end && inorder[i] != root->val) {
        i++;
    }

    root->left = solve(preorder, inorder, pre_start + 1, pre_start + (i - in_start), in_start, i - 1);
    root->right = solve(preorder, inorder, pre_start + (i - in_start + 1), pre_end, i +1 , in_end);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return solve(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

void printTree(TreeNode* root) {
    if (root == NULL) {
        return ;
    }
    queue<TreeNode*> q1;
    q1.push(root);
    q1.push(NULL);
    while (!q1.empty()) {
        TreeNode* front1 = q1.front();
        q1.pop();
        if (front1 == NULL) {
            cout << endl;
            if (!q1.empty()) {
                q1.push(NULL);
            }
        }
        else {
            cout << front1->data << "  ";
            if (front1->left != NULL) {
                q1.push(front1->left);
            }
            if (front1 -> right != NULL) {
                q1.push(front1->right);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        vector <int> inorder(num);
        vector <int> preorder(num);
        for (int i = 0; i < num; i++) {
            cin >> inorder[i] >> preorder[i];
        }
        TreeNode* root = buildTree(preorder, inorder);
        printTree(root);
    }
    return 0;
}
