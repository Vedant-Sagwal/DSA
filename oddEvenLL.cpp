#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* evenOdd(ListNode* head) {
    ListNode* evenHead = NULL; 
    ListNode* oddHead = NULL;
    ListNode* evenTail = NULL;
    ListNode* oddTail = NULL;
    ListNode* ptr = head;
    while (ptr != NULL) {
        if (ptr -> val % 2 == 0) {
            ListNode* temp = ptr -> next;
            if (evenHead == NULL) {
                evenHead = ptr;
                evenTail = ptr; 
                evenTail -> next = NULL;
                ptr = temp;
            }
            else {
                evenTail -> next = ptr;
                evenTail = ptr;
                ptr = temp;
            }
        }
        else {
            ListNode* temp = ptr -> next;
            if (oddHead == NULL) {
                oddHead = ptr;
                oddTail = ptr; 
                oddTail -> next = NULL;
                ptr = temp;
            }
           
            else {
                evenTail -> next = ptr;
                evenTail = ptr;
                ptr = temp;
            } 
        }
    }
    evenTail -> next = oddHead;
    oddTail -> next = NULL;
    return evenHead;
}

int main() {
    return 0;
}
