/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void path(vector<vector<int> >& ans, vector<int>& v, TreeNode* A, int B){
    if(!A) return;
    B -= A->val;
    v.push_back(A->val);
    if(!A->left && !A->right){
        if(B == 0) ans.push_back(v);
        v.pop_back();
        return ;
    }
    path(ans, v, A->left, B);
    path(ans, v, A->right, B);
    v.pop_back();
    return ;
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > ans;
    vector<int> v;
    if(A == NULL){
        return ans;
    }
    path(ans, v, A, B);
    return ans;
}
