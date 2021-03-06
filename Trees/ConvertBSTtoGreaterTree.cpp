/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum;
     void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->right);
        sum += root->val;
        root->val = sum;
        inorder(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        inorder(root);
        return root;
    }
};
/*class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return root;
        int tot = 0;
        dfs(root, tot);
        return root;
    }
private:
    void dfs(TreeNode *root, int &tot){
        if(root->right){
            dfs(root->right, tot);
        }
        tot += root->val;
        root->val += (tot - root->val);
        if(root->left){
            dfs(root->left, tot);
        }
    }
};*/
