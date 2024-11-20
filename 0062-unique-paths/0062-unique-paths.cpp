class Solution {
public:

    // TC - O(2^(m*n)) and SC - O( (m-1) + (n-1))

    int helperFunc(int i, int j, vector<vector<int>>& dp){

        if(i == 0 && j == 0) return 1;
        
        if(i < 0 || j < 0) return 0;
        
        // step.2
        if(dp[i][j] != -1) return dp[i][j];

        int up = helperFunc(i-1, j, dp);
        int left = helperFunc(i, j-1, dp);

        // step.1
        dp[i][j] = up + left;
        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        int i = m - 1;
        int j = n - 1;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helperFunc(i, j, dp);
    }
};