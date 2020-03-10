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
     int zz(TreeNode* root, bool dir) {
        if (!root) return -1;
        return 1 + (dir ? zz(root->left, !dir) : zz(root->right, !dir));
    } 
    int longestZigZag(TreeNode* root, int mark=0) {
        if (!root) return 0;
		return  max(max(mark >= 0 ? zz(root, true) : 0, mark <= 0 ? zz(root, false) : 0),
                    max(longestZigZag(root->left, 1), longestZigZag(root->right, -1)));
    }
};
