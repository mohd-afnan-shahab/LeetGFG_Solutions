class Solution {
public:

    int helper(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){

        if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;

        // base case
        if(i == 0 && j == 0) return 1;

        if(i < 0 || j < 0) return 0;

        // step 1 - check before calling helper func
        if(dp[i][j] != -1) return dp[i][j];

        int up = helper(i-1, j, obstacleGrid, dp);
        int left = helper(i, j-1, obstacleGrid, dp);

        // step 2 - store before returning
        dp[i][j] = (up + left);
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();    // row size
        int n = obstacleGrid[0].size();     // col size

        // initialize a dp array
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(m-1, n-1, obstacleGrid, dp);

    }
};