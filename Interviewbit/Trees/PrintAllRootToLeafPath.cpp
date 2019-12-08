void allpaths(vector<vector<int>>& res, vector<int>& temp, TreeNode* A){
    if (!A)
        return;
    temp.emplace_back(A->val);
    if (!A->left && !A->right)
        res.emplace_back(temp);
    allpaths(res, temp, A->left);
    allpaths(res, temp, A->right);
    temp.pop_back();
}
vector<vector<int> > Solution::solve(TreeNode* root) {
    vector<vector<int>> res;
    vector<int> temp;
    allpaths(res, temp, root);
    return res;
}
