#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    string data;
    string final_code;
    int freq;
    Node* left;
    Node* right;
};

class comparator {
    public:
        bool operator() (Node* a, Node* b) {
            return ((a->freq) > (b->freq));
        }
};

void codePrint(Node* head, string code) {
    //base case
    if (head == NULL) {
        return ;
    }
    if (head -> left == NULL && head->right == NULL) {
        head->final_code = code;
        cout << head->data << " ::::: " << head->final_code << endl;
    }
    if (head->left) {
        codePrint(head -> left, code + "0");
    }
    if (head -> right) {
        codePrint(head -> right, code + "1");
    }
}

void level_order_traversal(Node* head) {
    queue<Node*> pq1;
    pq1.push(head);
    pq1.push(NULL);
    while (!pq1.empty()) {
        Node* temp = pq1.front(); 
        pq1.pop();
        if (temp != NULL) {
            cout << temp->data << " : ";
            cout << temp->freq << "    ";
            if (temp->left) {
                pq1.push(temp->left);
            }
            if (temp->right) {
                pq1.push(temp->right);
            }
        }
        else {
            cout << endl; 
            if (!pq1.empty()) {
                pq1.push(NULL);
            }
        }
    }
}

void huffmanAlgo(Node* lst[], int n) {
    priority_queue<Node*, vector <Node*> , comparator> pq1;
    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        pq1.push(lst[i]);
    }
    while (!pq1.empty()) {
        Node* first = pq1.top();
        pq1.pop();
        if (!pq1.empty()) {
            Node* second = pq1.top(); 
            pq1.pop();
            Node* nn = new Node();
            nn->data = (first->data + second->data);
            nn->left = first;
            nn->right = second;
            nn->freq = first->freq + second->freq;
            pq1.push(nn);
        }
        else {
            head = first;
        }
    }
    level_order_traversal(head);
    cout << endl << endl;
    odePrint(head, "");
}



int main() {
    int n;
    cin >> n;
    Node* lst[n];
    for (int i = 0; i < n; i++) {
        Node* nn = new Node();
        lst[i] = nn;
        cin >> lst[i]->data;
        cin >> lst[i]->freq;
        lst[i]->left = NULL;
        lst[i]->right = NULL;
    }
    huffmanAlgo(lst, n);
    return 0;
}
