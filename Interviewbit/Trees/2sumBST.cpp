void helper(TreeNode* A, vector<int> &B){
    if(A->left) 
        helper(A->left, B);
    B.push_back(A->val);
    if(A->right) 
        helper(A->right, B);
    return;
}
int Solution::t2Sum(TreeNode* A, int B){
    vector<int> Inorder;
    helper(A, Inorder);
    int n = Inorder.size();
    for(int i = 0, j = n-1; i<j;){
        if(Inorder[i]+Inorder[j] == B) 
            return 1;
        if(Inorder[i]+Inorder[j]<B) 
            i++;
        else if(Inorder[i]+Inorder[j]>B)
            j--;
    }
return 0;
}
