#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* parent = NULL;
    vector <TreeNode*> child;
};

struct bTreeNode {
    int val;
    bTreeNode* left;
    bTreeNode* right;
};

bTreeNode* convert_tree_to_btree(TreeNode* root) {
    if (root == NULL) return NULL;

    bTreeNode* bRoot = new bTreeNode();
    bRoot->val = root->val;

    if (root->child.size() != 0) {
        bRoot->left = convert_tree_to_btree(root->child[0]);

        bTreeNode* to_be_right = bRoot->left;
        for (int i = 1; i < root->child.size(); i++) {
            to_be_right->right = convert_tree_to_btree(root->child[i]);
            to_be_right = to_be_right->right;
        }
    }
    return bRoot;
}

TreeNode* input_treeNode () {
    int num;
    cout << "Enter data " << endl;
    cin >> num;
    TreeNode* tree = NULL;
    if (num != -1) {
        tree = new TreeNode(); 
        tree->val = num;
        int n;
        cout << "Enter no. of children of " << num << endl;
        cin >> n;
        if (n == 0) {
            return tree;
        }
        vector <TreeNode*> v1(n);
        for (int i = 0; i < n; i++ ) {
            cout << "For child"<< i + 1 << " of " << num << endl;
            tree->child.push_back(input_treeNode());
        }
    }
    return tree;
}

void display_bTree(bTreeNode* root) {
    //base case
    if (root == NULL) {
        return ;
    }
    queue<bTreeNode*> q1;
    q1.push(root);
    q1.push(NULL);
    while (!q1.empty()) {
        bTreeNode* temp = q1.front();
        q1.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q1.empty()) {
                q1.push(NULL);
            }
        }
        else {
            cout << temp->val << "\t";
            if (temp->left) {
                q1.push(temp->left);
            }
            if (temp->right) {
                q1.push(temp->right);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        TreeNode* root = input_treeNode();
        bTreeNode* broot = convert_tree_to_btree(root);
        display_bTree(broot);
    }
    return 0;
}
