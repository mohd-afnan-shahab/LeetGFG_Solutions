class Solution {
public:

    void subsequence(vector<int>& nums, int ind, int n, 
                    vector<vector<int>> &ans,
                    vector<int> temp)
    {

        if(ind == n){
            ans.push_back(temp);
            return;
        }

        // if im not taking..
        subsequence(nums, ind + 1, n, ans, temp);

        // if im taking.. (yes)
        temp.push_back(nums[ind]); 
        subsequence(nums, ind + 1, n, ans, temp);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        subsequence(nums, 0, n, ans, temp);

        return ans;
    }
};