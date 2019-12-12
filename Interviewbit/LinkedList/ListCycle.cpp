/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    if(!A || !A->next) return NULL;
    ListNode* slow = A;
    ListNode* fast = A;
    while(slow != NULL && fast != NULL) {
        slow = slow->next;
        if(fast->next == NULL) 
            return NULL;
        else 
            fast = (fast->next)->next;
        if(slow == fast) break;
    }
    // This is Important to prevent segmentation fault
    if(slow == NULL || fast == NULL) 
        return NULL;
    
    ListNode* temp = A;
    while(temp != slow) {
        temp = temp->next;
        slow = slow->next;
    }
    return temp;
    
}
