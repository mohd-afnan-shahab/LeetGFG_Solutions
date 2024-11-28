class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;
        
        while(!q.empty()){
            int levelsize = q.size();
            vector<int> row(levelsize);

            for(int i = 0; i < levelsize; i++){
                TreeNode* node = q.front();
                q.pop();

                int idx;
                if(leftToRight){
                    idx = i;
                }
                else{
                    idx = levelsize - 1 - i;
                }

                row[idx] = node -> val;

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }

            leftToRight = !leftToRight;
            ans.push_back(row);
        }

        return ans;
    }
};