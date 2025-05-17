#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node() {
    data = 0;
    left = right = NULL;
  }
  Node(int val) {
    data = val;
    left = right = NULL;
  }
};
vector<int> zigZagTraversal(Node *root) {
  vector<int> ans;
  // Base Case
  if (root == NULL) {
    return ans;
  }

  queue<Node *> q1;
  q1.push(root);
  bool leftToRight = true;

  // Traversal
  while (!q1.empty()) {
    int size = q1.size();
    vector<int> temp(size);
    // Each level traversal
    for (int i = 0; i < size; i++) {
      int index = leftToRight ? i : size - i - 1;
      temp[index] = q1.front()->data;
      Node *tempNode = q1.front();
      q1.pop();

      // Left subtree
      if (tempNode->left) {
        q1.push(tempNode->left);
      }
      // Right Subtree
      if (tempNode->right) {
        q1.push(tempNode->right);
      }
    }
    // Flag change!!
    leftToRight = !(leftToRight);
    for (auto i : temp) {
      ans.push_back(i);
    }
  }
  return ans;
}

vector<int> zigZagTraversalEfficient(Node *root) {
  vector<int> ans;
  // Base Case
  if (root == NULL) {
    return ans;
  }

  queue<Node *> q1;
  stack<Node *> s1;
  q1.push(root);
  q1.push(new Node(-101));
  bool leftToRight = true;

  // Traversal
  while (!q1.empty()) {
    Node *temp = q1.front();
    q1.pop();
    if (!leftToRight) {
      if (temp->data == -101) {
        while (!s1.empty()) {
          Node *top1 = s1.top();
          s1.pop();
          ans.push_back(top1->data);
        }
        if (!q1.empty()) {
          q1.push(new Node(-101));
          leftToRight = !leftToRight;
        }
      } else {
        s1.push(temp);
        if (temp->left) {
          q1.push(temp->left);
        }
        if (temp->right) {
          q1.push(temp->right);
        }
      }
    } else {
      if (temp->data == -101) {
        if (!q1.empty()) {
          q1.push(new Node(-101));
          leftToRight = !leftToRight;
        }
      } else {
        ans.push_back(temp->data);
        if (temp->left) {
          q1.push(temp->left);
        }
        if (temp->right) {
          q1.push(temp->right);
        }
      }
    }
  }
  return ans;
}

Node *takeInput() {
  Node *root = NULL;
  int num;
  cout << "Enter root data : " << endl;
  cin >> num;
  if (num != -1) {
    root = new Node(num);
    root->left = NULL;
    root->right = NULL;
    cout << "For left of " << root->data << " : " << endl;
    root->left = takeInput();
    cout << "For right of " << root->data << " : " << endl;
    root->right = takeInput();
  }
  return root;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    Node *root = takeInput();
    vector<int> ans1 = zigZagTraversal(root);
    vector<int> ans2 = zigZagTraversalEfficient(root);
    for (auto i : ans1) {
      cout << i << "\t";
    }
    cout << endl;
    for (auto i : ans2) {
      cout << i << "\t";
    }
    cout << endl;
  }
  return 0;
}
