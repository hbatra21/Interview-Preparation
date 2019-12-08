/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    int levelSize = 1, nextLevel = 0;
    vector<vector<int> > result;
    vector<int> curLevel;
    if(A==NULL)
        return result;
    queue<TreeNode*> q;
    q.push(A);
    while(q.empty()!=true)
    {
        TreeNode* node=q.front();
        q.pop();
        if(node->left!=NULL)
        {
            q.push(node->left);
            nextLevel++;
        }    
        if(node->right!=NULL)
        {   
            q.push(node->right);
            nextLevel++;
        }
        levelSize--;
        curLevel.push_back(node->val);
        if (levelSize == 0) {
            result.push_back(curLevel);
            levelSize = nextLevel;
            nextLevel = 0;
            curLevel.clear();
        }
        delete(node);
    }
    return result;
}
