int sumEvenGrandparent(TreeNode* root) {
        int sumski = 0;
        dfs(root,sumski);
        return sumski;
    }
    void dfs(TreeNode * root,int & sumski){
        if(!root) return;
        if(root->val % 2 ==0){
            if(root->left != NULL) {
            if(root->left->left != NULL) sumski += root->left->left->val;
            if(root->left->right != NULL) sumski += root->left->right->val;
           }
            if(root->right != NULL) {
            if(root->right->left != NULL) sumski += root->right->left->val;
            if(root->right->right != NULL) sumski += root->right->right->val;
           }
        }
        dfs(root->left,sumski);
        dfs(root->right,sumski);
    }
