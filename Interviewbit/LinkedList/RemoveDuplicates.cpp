/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* temp=A;
    while(A!=NULL){
        while(A->next!=NULL && A->val==A->next->val){
            A->next=A->next->next;
    }
        A=A->next;
    }
    
    return temp;
    
}
