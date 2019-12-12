/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* head,int B){
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* post;
    int count=0;
    while(curr && count<B ){
        post=curr->next;
        curr->next=prev;
        prev=curr;
        curr=post;
        count++;
    }
    if(post!=NULL) head->next=reverse(post,B);
    return prev;
}

ListNode* Solution::swapPairs(ListNode* A) {
    A=reverse(A,2);
    return A;
}
