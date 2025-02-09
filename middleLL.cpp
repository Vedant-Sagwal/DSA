#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode* hare = head;
    ListNode* turtle = head;
    while (hare != NULL && hare -> next != NULL) {
        hare = hare -> next -> next;
        turtle = turtle -> next;
    }
    return turtle;
}

int main() {
    return 0;
}
