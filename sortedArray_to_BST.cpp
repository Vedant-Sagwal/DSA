#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* array_to_BST(vector <int> &arr, int p, int r) {
    if (p > r) {
        return NULL;
    }
    int mid = (p + r) / 2;
    int to_be_root = arr[mid]; 
    TreeNode* root = new TreeNode();
    root->val = to_be_root;
    //go for left
    root->left = array_to_BST(arr, p, mid - 1);
    //go for right
    root->right = array_to_BST(arr, mid + 1, r);
    return root;
}

void displayTree(TreeNode* root) {
    //base case
    if (root == NULL) {
        return ;
    }
    queue<TreeNode*> q1;
    q1.push(root);
    q1.push(NULL);
    while (!q1.empty()) {
        TreeNode* temp = q1.front();
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
        int n;
        cin >> n;
        vector <int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        TreeNode* root = array_to_BST(arr, 0, n - 1);
        displayTree(root);
    }
    return 0;
}
