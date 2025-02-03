#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addAtLast(ListNode* head, int c) {
    ListNode* nn = new ListNode(c);
    if (head == NULL) {
        head = nn;
        return head;
    }
    head -> next = nn;
    head = nn;
    return head;
}
ListNode* merge(ListNode* a, ListNode* b) {
    ListNode* ans = new ListNode(-1);
    ListNode* temp = ans;
    while (a && b) {
        if (a->val <= b->val) {
            ans = addAtLast(ans, a -> val);
            a = a -> next;
        }
        else {
            ans = addAtLast(ans, b -> val);
            b = b -> next;
        }
    }
    while (a) {
        ans = addAtLast(ans, a -> val);
        a = a->next;
    }
    while (b) {
        ans = addAtLast(ans, b -> val);
        b = b -> next;
    }
    return temp->next;
}

ListNode* sortList(ListNode* head) {
        //Base Case
        if (head == NULL || head -> next == NULL) {
            return head;
        }

        //Splitting linked list in 2 parts
        ListNode* hare = head->next;
        ListNode* turtle = head;
        while (hare != NULL && hare -> next != NULL) {
            turtle = turtle -> next;
            hare = hare -> next -> next;
        }
        ListNode* left = head;
        ListNode* right = turtle -> next;
        turtle -> next = NULL;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }

int main() {
    return 0;
}
