#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode* random;
    ListNode() : data(0), next(nullptr),random(nullptr) {}
    ListNode(int x) : data(x), next(nullptr), random(nullptr) {}
    ListNode(int x, ListNode* next) : data(x), next(next), random(nullptr) {}
};


ListNode* cloneLL(ListNode* lst) {
    //base case
    if (lst == NULL) {
        return NULL;
    }
    unordered_map<ListNode*, ListNode*> m1;
    //can handle multiple random to same pointer if we use vector<ListNode*>
    unordered_map<ListNode*, ListNode*> m2;
    ListNode* clonedLL = NULL;
    ListNode *nn = new ListNode();
    nn->data = lst->data;
    nn->next = NULL;
    nn->random = NULL;
    clonedLL = nn;
    ListNode* ptr = clonedLL;
    m1[lst] = clonedLL;
    if (lst->random != NULL) {
        m2[lst->random] = lst;
    }
    if (m2.find(lst) != m2.end()) {
        ListNode* randomptr = m1[m2[lst]];
        randomptr->random = ptr;
    }
    if (m2.find(lst->random) != m2.end()) {
        ListNode* randomptr = m1[lst->random];
        ptr -> random = randomptr;
    }
    lst = lst -> next;
    while (lst != NULL) {
        ListNode* nn = new ListNode();
        nn->data = lst->data;
        nn->next = NULL;
        nn->random = NULL;
        ptr -> next = nn;
        ptr = ptr -> next;
        m1[lst] = ptr;
        m2[lst->random] = lst;
        if (m2.find(lst) != m2.end()) {
            ListNode* randomptr = m1[m2[lst]];
            randomptr->random = ptr;
        }
        if (m2.find(lst->random) != m2.end()) {
            ListNode* randomptr = m1[lst->random];
            ptr -> random = randomptr;
        }
        lst = lst -> next;
    }
    return clonedLL;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ListNode* lst = NULL;
        ListNode* tail = NULL;
        unordered_map<int, ListNode*> m3;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if (tail == NULL) {
                lst = new ListNode(num);
                tail = lst;
            }
            else {
                tail->next = new ListNode(num);
                tail = tail->next;
            }
            m3[tail->data] = tail;
        }
        ListNode* tail2 = lst;
        while (tail2 != NULL) {
            int n1;
            cin >> n1;
            tail2->random = m3[n1];
            tail2 = tail2->next;
        }
        ListNode* ans = cloneLL(lst);
        while (lst != NULL) {
            cout << lst->data << " . " << lst->random->data << "\t";
            lst = lst -> next;
        }
        cout << endl;
        while (ans != NULL) {
            cout << "Ans : " <<  ans->data << "\t";
            if (ans->random) {
                cout <<  " random : " << ans->random->data << endl;
            }
            ans = ans -> next;
        }
        cout << endl;
    }
    return 0;
}
