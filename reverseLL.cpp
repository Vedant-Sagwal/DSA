#include <iostream>
#include <vector>
using namepspace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x,ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList1(ListNode* head) {
    //iterative
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode*  next = NULL;
    while (curr != NULL) {
        next = curr->next; 
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* endLL(ListNode* head) {
    while (head != NULL && head -> next != NULL) {
        head = head -> next;
    }
    return head;
}

ListNode* reverseList(ListNode* head) {
    //recursive
    //Base Case
    if (head == NULL) {
        return NULL;
    } 
    if (head -> next == NULL) {
        return head;
    }
    ListNode* temp = head->next;
    ListNode* nextHead = reverseList(head->next);
    temp->next = head;
    head->next = NULL;
    return nextHead;
}



int main () {
    return 0;
}
