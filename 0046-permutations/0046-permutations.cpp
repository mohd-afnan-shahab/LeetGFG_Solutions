class Solution {
public:
    // TIME COMPLEXITY - O(n * n!) ans SPACE COMPLEXITY - O(N + N) {recursive call + visited array}
    void solve(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, vector<bool>& visited){

        // base case : if temp.size() becomes equal to arr.size()
        if(nums.size() == temp.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < visited.size(); i++){
            if(!visited[i]){
                visited[i] = 1;
                temp.push_back(nums[i]);

                // recursive call
                solve(nums, temp, ans, visited);

                // backtrack
                visited[i] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), 0);

        solve(nums, temp, ans, visited);

        return ans;
    }
};