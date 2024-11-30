class Solution {
public:

    int helper(int n, vector<int>& dp){
        if(n == 0) return 1;    // cnt all ways by returning 1.
        if(n == 1) return 1;    

        // step.2
        if(dp[n] != -1) return dp[n];

        int left = helper(n-1, dp);
        int right = helper(n-2, dp);
        
        // step.2
        dp[n] = left + right;
        return dp[n];
    }

    int climbStairs(int n) {
        
        vector<int> dp(n+1, -1);

        return helper(n, dp);
    }
};