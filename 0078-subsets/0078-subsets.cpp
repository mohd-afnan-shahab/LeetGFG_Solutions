class Solution {
public:

    void generateSubsets(vector<int>& nums, int ind, 
                         vector<vector<int>>& ans,
                         vector<int>& temp)
    {
        if (ind == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // If not taking the current element
        generateSubsets(nums, ind + 1, ans, temp);


        // If taking the current element
        temp.push_back(nums[ind]); 
        generateSubsets(nums, ind + 1, ans, temp);

        temp.pop_back(); // Backtrack to remove the last added element
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        generateSubsets(nums, 0, ans, temp);

        return ans;
    }
};
