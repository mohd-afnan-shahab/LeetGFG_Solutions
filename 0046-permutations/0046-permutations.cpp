class Solution {
public:
    void solve(int index, vector<int>& nums, vector<vector<int>>& ans){

        // base case
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){

            swap(nums[i], nums[index]);

            // recursive call
            solve(index + 1, nums, ans);

            // backtrack
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);

        return ans;
    }
};