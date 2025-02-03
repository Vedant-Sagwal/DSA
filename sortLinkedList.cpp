#include <iostream>
#include <vector>
using namespace std;

typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

void swap(ListNode**head, ListNode* a, ListNode* b) {
    ListNode* ptr1 = a;
    ListNode* ptr2  = b;
    while (ptr1 != NULL && ptr1 -> next != a) {
        ptr1 = ptr1 -> next;
    }
    while (ptr2 != NULL && ptr2 -> next != a) {
        ptr2 = ptr2 -> next;
    }
    ListNode* temp1 = a->next;
    a->next = b->next;
    ptr1->next = b; 
    b->next = temp1;
    ptr2->next = a;
}

ListNode* endLL(ListNode* head) {
    while (head != NULL && head-> next != NULL) {
        head = head -> next;
    }
    return head;
}

ListNode* partition(ListNode** list, ListNode* start, ListNode* end) {
    ListNode* first = start;
    ListNode* head = start;
    ListNode* pivot = end; 
    ListNode* prev = NULL;
    while (head != pivot) {
        if ((pivot != NULL && head != NULL) && (pivot->data < head -> data)) {
            if (prev == NULL) {
                prev = first; 
            } 
            else {
                prev = prev -> next;
            }
            swap(list, prev, head);
        }
        head = head -> next;
    }
    if (prev == NULL) {
        prev = first;
    }
    else {
        prev = prev -> next;
    }
    swap(list, prev, pivot);
    return prev;
}

ListNode* getPrev(ListNode** list, ListNode* ptr) {
    ListNode* head = *list;
    while (head != NULL && head -> next != ptr) {
        head = head -> next;
    }
    return head;
}

void quickSortList(ListNode** head, ListNode* start, ListNode* end) {
    if (start != end) {
        ListNode* pivot = partition(head, start, end);
        ListNode* prev = getPrev(head, pivot);
        quickSortList(head, start, prev);
        quickSortList(head, pivot -> next, end);
    }
}

int main() {

    return 0;
}
