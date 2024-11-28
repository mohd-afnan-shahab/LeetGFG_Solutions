class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {

        if(root == NULL) return{};

        vector<double> result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int levelSize = q.size();
            long long sum = 0;
            
            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front();
                q.pop();

                sum += node -> val;

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }

            double avg = static_cast<double>(sum) / levelSize;
            result.push_back(avg);
        }

        return result;
    }
};