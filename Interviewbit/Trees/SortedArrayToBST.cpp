/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* create(const vector<int> &A, int st, int en){
    if (st > en) return NULL;
    int mid = (st + en)/2;
    TreeNode *root = new TreeNode(A[mid]);
    root->left = create(A, st, mid-1);
    root->right = create(A, mid+1, en);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return create(A, 0, A.size()-1);
}
