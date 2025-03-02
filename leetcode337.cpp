#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solve(TreeNode* root, bool visited, map<pair<TreeNode*, bool>, int> &m1) {
    if (root == NULL) {
        return 0;
    }
    if (m1.find({root, visited}) != m1.end()) {
        return m1[{root, visited}];
    }
    if (visited == false && root->left == NULL && root->right == NULL) {
        return root->val;
    }
    if (visited == true && root->left == NULL && root->right == NULL) {
        return 0;
    }   //include root
    int include = 0;
    if (visited == true) {
        include = solve(root->left, false, m1) + solve(root->right, false, m1);
    }
    else {
        include =  solve(root->left, true, m1) + solve(root->right, true, m1) + root->val;
    }
    //exclude 
    int exclude = solve(root->left, false, m1) + solve(root->right, false, m1);
    m1[make_pair(root, visited)] = max(include, exclude);
    return max(include, exclude);
}

int rob(TreeNode* root) {
    map<pair<TreeNode*, bool>, int> m1;
    return solve(root, false, m1);
}


int main() {
    return 0;
}
