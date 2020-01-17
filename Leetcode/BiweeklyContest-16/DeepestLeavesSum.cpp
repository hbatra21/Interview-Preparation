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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        int ans = 0;
        q.push(root);
        while(!q.empty()) {
            int node = q.size();
            ans = 0;
            while(node > 0) {
                TreeNode* top = q.front();
                q.pop();
                ans += top->val;
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
                node--;
            }
        }
        return ans;
    }
};
