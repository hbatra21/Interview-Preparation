/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void printleaves(TreeNode *A,vector<int> &v)
{
    if(A)
    {
        printleaves(A->left,v);
        if(!A->left && !A->right)
            v.push_back(A->val);
        printleaves(A->right,v);
    }
}

void printleft(TreeNode* A,vector<int> &v)
{
    if(A)
    {
        if(A->left)
        {
            v.push_back(A->val);
            printleft(A->left,v);
        }
        else if(A->right)
        {
            v.push_back(A->val);
            printleft(A->right,v);
        }
    }
}

void printright(TreeNode *A,vector <int> &v)
{
    if(A)
    {
        if(A->right)
        {
            printright(A->right,v);
            v.push_back(A->val);
        }
        else if(A->left)
        {
            printright(A->left,v);
            v.push_back(A->val);
        }
    }
    
}
vector<int> Solution::solve(TreeNode* A) 
{
    vector<int> v;
    if(A)
        v.push_back(A->val);
    printleft(A->left,v);
    printleaves(A->left,v);
    printleaves(A->right,v);
    printright(A->right,v);
    return v;
}
