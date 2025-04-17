#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* takeInput() {
    TreeNode* root = NULL;
    int num;
    cout << "Enter root data : " << endl;
    cin >> num;
    if (num != -1) {
        root = new TreeNode();
        root->data = num;
        root->left = NULL;
        root->right = NULL;
        cout << "For left of " << root->data << " : " << endl;
        root->left = takeInput();
        cout << "For right of " << root->data << " : " << endl;
        root->right = takeInput();
    }
    return root;
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
        TreeNode* root = takeInput();
        cout << "Tree is : " << endl;
        printTree(root);
    }
    return 0;
}
