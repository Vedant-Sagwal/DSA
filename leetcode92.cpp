#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << endl;
        head = head -> next;
    }
}

ListNode* reverseList(ListNode* start, ListNode* end) {
    if (start == NULL) {
        return NULL;
    }
    if (start == end) {
        return start;
    }
    ListNode* prev = NULL;
    ListNode* curr = start;
    ListNode* next1 = NULL;
    while (prev != end) {
        cout << "curr : " << curr->val << endl;
        next1 = curr -> next;
        curr ->next =  prev;
        prev = curr;
        cout << "prev : " << prev->val << endl;
        curr = next1;
    }
    return prev;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    //Base Case
    if (left > right) {
        return NULL;
    }
    if (left == right) {
        return head;
    }
    ListNode* ptr = head;
    int counter = 1;
    ListNode* start = NULL;
    ListNode* end = NULL;
    ListNode* prev1 = NULL;
    ListNode* prev2 = NULL;
    while (ptr != NULL) {
        if (counter == left - 1) {
            prev1 = ptr; 
        } 
        if (counter == right) {
            end = ptr; 
        }
        if (counter == left) {
            start = ptr;
        }
        counter++;
        ptr = ptr -> next;
    }
    prev2 = end->next;
    ListNode* ans = reverseList(start, end);
    if (prev1 != NULL) {
        prev1 -> next = ans;
        start->next = prev2;
        return head;
    }
    else {
        start -> next = prev2;
        return ans;
    } 
}   


int main() {
    return 0;
}
