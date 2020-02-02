static int MOD=1e9+7;
class Solution {
public:
long long totalTreeSum=0,result=0;
    void getTotalTreeSum(TreeNode* root)   {
        if(!root)
            return;
        totalTreeSum+=root->val;
        getTotalTreeSum(root->left);
        getTotalTreeSum(root->right);
    }
    int SumUnder(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left&&!root->right)
            return root->val;
        int sumUnderLeft=SumUnder(root->left),sumUnderRight=SumUnder(root->right);			
        result=max({result,(totalTreeSum-sumUnderLeft)*sumUnderLeft,(totalTreeSum-sumUnderRight)*sumUnderRight});      
        return sumUnderLeft+sumUnderRight+root->val;
    }
    int maxProduct(TreeNode* root) {
        getTotalTreeSum(root);
        SumUnder(root);
        return result%MOD;
    }
};
