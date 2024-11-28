
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }

        int leftHeight = maxDepth(root -> left);
        int rightHeight = maxDepth(root -> right);

        return 1 + max(leftHeight, rightHeight);
    }
};