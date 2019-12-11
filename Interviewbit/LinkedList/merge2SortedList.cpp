/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(!A) return B;
    if(!B) return A;
    ListNode* temp = new ListNode(0);
    ListNode* res = temp;
    while(A && B) {
        if(A->val > B->val) {
            temp->next = B;
            B = B->next;
        }
        else if(A->val <= B->val) {
            temp->next = A;
            A = A->next;
        }
        temp = temp->next;
    }
    while(A) {
        temp->next = A;
        temp = temp->next;
        A = A->next;
    }
    while(B) {
        temp->next = B;
        temp = temp->next;
        B = B->next;
    }
    return res->next;
}
