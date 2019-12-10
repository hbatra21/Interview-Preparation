/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* Tree(ListNode* &head,int start,int end){
    if(start>end)return NULL;
    int mid=(end+start)/2;
    TreeNode* l=Tree(head,start,mid-1);
    TreeNode* root=new TreeNode(head->val);
    head=head->next;
    TreeNode* r=Tree(head,mid+1,end);
    root->left=l;
    root->right=r;
    return root;
} 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    if(A==NULL) return NULL;
    int len=0;
    ListNode* curr=A;
    while(curr!=NULL){
        len++;
        curr=curr->next;
    }
    return Tree(A,0,len-1);
    
}
