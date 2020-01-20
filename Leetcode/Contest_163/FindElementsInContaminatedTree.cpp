/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    unordered_set<int> values;
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        return values.find(target) != values.end();
    }
    void recover(TreeNode* root, int value) {
        if (root) {
            values.insert(value);
            root->val = value;
            recover(root->left, value * 2 + 1);
            recover(root->right, value * 2 + 2);
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
