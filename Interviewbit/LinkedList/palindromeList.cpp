/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    ListNode *slow=A,*fast=A;
    stack<int> s;
    while(slow!=NULL){
        s.push(slow->val);
        slow=slow->next;
        
    }
    while(A!=NULL){
        int data=s.top();
        s.pop();
        if(data!=A->val) return 0;
        A=A->next;
    }
    return 1;
    
}
