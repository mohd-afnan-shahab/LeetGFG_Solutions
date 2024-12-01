class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // base case
        if (root == NULL) return NULL;

        // Swap the left and right children
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;

        // Recur for left and right subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
