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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1, res = 0, currSum = INT_MIN;
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            while(size){
                TreeNode* top = q.front();
                q.pop();
                sum += top->val;
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
                size--;
            }
            if(sum > currSum) {
			res = level;
			currSum = sum;
		}
		level++;
        }
        return res;
    }
};
