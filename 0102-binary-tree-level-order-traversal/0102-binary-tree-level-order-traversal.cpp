
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL) return {};

        vector<vector<int>> result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int levelsize = q.size();
            
            vector<int> inter;
            for(int i = 0; i < levelsize; i++){
                TreeNode* node = q.front();
                q.pop();

                inter.push_back(node -> val);

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }

            result.push_back(inter);
        }

        return result;
    }
};