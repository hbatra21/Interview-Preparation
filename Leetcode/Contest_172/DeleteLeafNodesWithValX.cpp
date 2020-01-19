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
    TreeNode* del(TreeNode* root, int target) {     
        if (root == NULL) 
            return NULL; 
        root->left = del(root->left, target); 
        root->right = del(root->right, target); 
        if (root->val == target && root->left == NULL && root->right == NULL) { 
            return NULL; 
        } 
        return root; 
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        root = del(root, target);
        return root;
    }
};
