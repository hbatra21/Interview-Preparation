void flatten(TreeNode *root) {
        if (!root) return;
        TreeNode* node = root;
        while (node) {

            // Attatches the right sub-tree to the rightmost leaf of the left sub-tree:
            if (node->left) {

                TreeNode *rightMost = node->left;
                while (rightMost->right) {

                    rightMost = rightMost->right;
                }
                rightMost->right = node->right;

                // Makes the left sub-tree to the right sub-tree:
                node->right = node->left;
                node->left = NULL;
            }

            // Flatten the rest of the tree:
            node = node->right;
        }     
    }
    // Recursive Approach
    /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void flat(TreeNode *root){
     if (!root) return;
        flat(root->left);
        flat(root->right);
        
        if (root->left){
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = nullptr;
            while (root->right != nullptr){
                root = root->right;
            }
            root->right = temp;
        }        
    }
TreeNode* Solution::flatten(TreeNode* A) {
    flat(A);
    return A;
    
}
