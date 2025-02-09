#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }        
    if (head -> next == NULL && n == 1) {
        return NULL;
    }
    ListNode* end = head -> next;
    ListNode* start = head;
    ListNode* prev = NULL;
    int diff = 1;
    while (end != NULL && diff != n) {
        cout << "end : " << end << endl;
        cout << "Diff : " << diff << endl;
        diff++;
        end = end -> next;
    }
    while (end != NULL) {
        end = end -> next;
        prev = start;
        start = start -> next;
    }
    if (prev == NULL) {
        return head -> next;
    }
    prev -> next = start -> next;
    return head;
}


}

int main() {
    return 0;
}
