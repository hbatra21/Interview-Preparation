/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode* curr=A;
    ListNode* head=A;
    ListNode* last=NULL;
    int n=0;
    if(A==NULL || B==0) return A;
    while(curr!=NULL){
        last=curr;
        curr=curr->next;
        n++;
    }
    last->next=head;
    curr=A;
    while(B>=n){
        B=B-n;
    }
    B=n-B;
    while(B--){
        last=curr;
        curr=curr->next;
    }
    head=curr; 
    last->next=NULL;
    return head ;
}
