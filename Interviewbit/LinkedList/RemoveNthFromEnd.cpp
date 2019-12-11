/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int n=0;
    ListNode* temp1=A;
    while(temp1!=NULL){
        n++;
        temp1=temp1->next;
    }
     if(!A) return NULL;
    if(B>=n) return A->next;
    int count=0;
    ListNode* temp=A;
    while(count<n-B-1){
        count++;
        temp=temp->next;
    }
    temp->next=(temp->next)->next;
    return A;
}
