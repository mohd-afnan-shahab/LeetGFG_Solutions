class Solution {
public:

    bool subsetSumtoK(int n, int target, vector<int>& nums){

        vector<vector<bool>> dp(n, vector<bool>(target+1, false));

        // base case
        for(int i = 0; i < n; i++){
            dp[i][0] = true; 
        }
        if(nums[0] <= target){
            dp[0][nums[0]] = true;
        }

        for(int idx = 1; idx < n; idx++){
            for(int j = 1; j <= target; j++){
                
                bool notTake = dp[idx - 1][j];

                bool take = false;
                if(j >= nums[idx]){
                    take = dp[idx - 1][j - nums[idx]];
                }

                dp[idx][j] = take || notTake;
            }
        }

        return dp[n-1][target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for(int i = 0; i < n; i++) totalSum += nums[i];

        if(totalSum % 2 != 0) return false;

        int target = totalSum / 2;

        return subsetSumtoK(n, target, nums);
    }
};