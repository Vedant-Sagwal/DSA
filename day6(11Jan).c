#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int * ans = (int *) malloc(numsSize * sizeof(int));
    int pred = 1;
    int succ = 1;
    for (int i = 0; i < numsSize; i++ ) {
       ans[i] = pred; 
       pred = pred * nums[i];
    }
    for (int i = numsSize - 1; i >= 0; i-- ) {
        ans[i] *= succ;
        succ = nums[i] * succ;
    }
    *returnSize = numsSize;
    return ans;
}
struct ListNode* reverseList(struct ListNode* head ) {
    struct ListNode* prev = NULL;    
    struct ListNode* next = NULL;
    struct ListNode* ptr = head;
    while (ptr != NULL) {
        printf("%d", ptr -> val);
        next = ptr -> next;
        ptr -> next = prev; 
        prev = ptr;
        ptr = next;
    }
    return prev;
}
struct ListNode* addToLast(struct ListNode* tail, int value) {
    struct ListNode* nn = (struct ListNode*) malloc(sizeof(struct ListNode));
    nn->val = value;
    nn->next = NULL;
    
    if (tail != NULL) {
        tail->next = nn;  // Append the new node to the end
    }
    
    return nn;  // Return the new tail
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct ListNode* head = NULL;  // Head of the merged list
    struct ListNode* tail = NULL;  // Tail of the merged list

    // Initialize the head and tail with the smaller of the two first nodes
    if (list1->val < list2->val) {
        head = (struct ListNode*) malloc(sizeof(struct ListNode));
        head->val = list1->val;
        head->next = NULL;
        tail = head;
        list1 = list1->next;
    } else {
        head = (struct ListNode*) malloc(sizeof(struct ListNode));
        head->val = list2->val;
        head->next = NULL;
        tail = head;
        list2 = list2->next;
    }

    // Merge the lists using the tail pointer
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            tail = addToLast(tail, list1->val);
            list1 = list1->next;
        } else {
            tail = addToLast(tail, list2->val);
            list2 = list2->next;
        }
    }

    // Append any remaining elements from list1 or list2
    while (list1 != NULL) {
        tail = addToLast(tail, list1->val);
        list1 = list1->next;
    }

    while (list2 != NULL) {
        tail = addToLast(tail, list2->val);
        list2 = list2->next;
    }

    return head;
}

int main() {
    return 0;
}
