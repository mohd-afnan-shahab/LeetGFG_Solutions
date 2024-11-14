class Solution {
public:
    
    // // *********** memoization ***********

    // int helper(int idx, vector<int>& nums, vector<int>& dp){

    //     // base case
    //     if(idx == 0) return nums[0];

    //     // step.2
    //     if(dp[idx] != -1) return dp[idx];

    //     int pick = nums[idx];
    //     if(idx > 1) pick += helper(idx - 2, nums, dp);

    //     int notPick = 0 + helper(idx - 1, nums, dp);

    //     // step.1
    //     dp[idx] = max(pick, notPick);

    //     return dp[idx];
    // }

    // int rob(vector<int>& nums) {
    //     int n = nums.size();

    //     int idx = n - 1;

    //     // Initialize 
    //     vector<int> dp(idx + 1, -1);

    //     return helper(idx, nums, dp);
    // }







        // *********** Tabulation ***********


    int rob(vector<int>& nums) {
        int n = nums.size();

        // Initialize 
        vector<int> dp(n); 

        // base case
        dp[0] = nums[0];

        for(int i = 1; i < n; i++){
            
            int pick = nums[i];

            if(i > 1) pick += dp[i-2];

            int notPick = 0 + dp[i-1];

            dp[i] = max(pick, notPick); 
        }

        return dp[n - 1];
    }
};