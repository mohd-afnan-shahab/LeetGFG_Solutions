class Solution {
public:

    int helper(int i, int j, vector<vector<int>>& dp){
        
        if(i == 0 && j == 0){
            return 1;
        }

        if(i < 0 || j < 0){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int up = helper(i - 1, j,dp);
        int left = helper(i, j - 1, dp); 

        dp[i][j] = (up + left);
        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        int i = m - 1;
        int j = n - 1;
        
        // initialzation
        vector<vector<int>> dp(m, vector<int>(n, -1));
 
        return helper(i, j, dp);
    }
};