/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {    
        vector<int> input;
        stack<int> s;
        while ( head != NULL ){
            input.push_back( head->val );
            head = head->next;
        }
        int size = input.size();
        vector<int> result(size);
        for ( int i = size - 1; i >= 0; i-- ){
            while ( !s.empty() && input[i] >= s.top() )
                s.pop();            
            if (s.empty())
                result[i] = 0;
            else 
                result[i] = s.top();
            s.push(input[i]);
        }              
        return result;       
    }
};
