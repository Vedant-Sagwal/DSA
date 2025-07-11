#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

int height_of_bt(TreeNode *root) {
  // base case
  if (root == NULL) {
    return 0;
  }
  int left = height_of_bt(root->left);
  int right = height_of_bt(root->right);
  return (1 + max(left, right));
}

int diameterOfBinaryTree1(TreeNode *root) {
  // base case
  if (root == NULL) {
    return 0;
  }
  // left
  int left_height = height_of_bt(root->left);
  int left = diameterOfBinaryTree1(root->left);
  // right
  int right_height = height_of_bt(root->right);
  int right = diameterOfBinaryTree1(root->right);
  return max((left_height + right_height), max(left, right));
}
// return diameter and height as a pair to reduce time complexity
pair<int, int> solve(TreeNode *root) {
  // base case
  if (root == NULL) {
    return make_pair(0, 0);
  }
  pair<int, int> left_side = solve(root->left);
  pair<int, int> right_side = solve(root->right);
  pair<int, int> final_ans;
  // diameter
  final_ans.first = max((left_side.second + right_side.second),
                        max(left_side.first, right_side.first));
  // height
  final_ans.second = 1 + max(left_side.second, right_side.second);
  return final_ans;
}

int diameterOfBinaryTree(TreeNode *root) {
  pair<int, int> p1 = solve(root);
  return p1.first;
}

TreeNode *takeInput() {
  TreeNode *root = NULL;
  int num;
  cout << "Enter root data : " << endl;
  cin >> num;
  if (num != -1) {
    root = new TreeNode();
    root->val = num;
    root->left = NULL;
    root->right = NULL;
    cout << "For left of " << root->val << " : " << endl;
    root->left = takeInput();
    cout << "For right of " << root->val << " : " << endl;
    root->right = takeInput();
  }
  return root;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    TreeNode *root = takeInput();
    diameterOfBinaryTree(root);
  }
  return 0;
}
