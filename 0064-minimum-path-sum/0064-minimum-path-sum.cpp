class Solution {
public:

    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){

        // base case
        if(i == 0 && j == 0) return grid[0][0];

        if(i < 0 || j < 0) return 1e9;      // cuz we have to find min cost

        // step 1 check before recursive call
        if(dp[i][j] != -1) return dp[i][j];

        int up = grid[i][j] + helper(i-1, j, grid, dp);
        int left = grid[i][j] + helper(i, j-1, grid, dp);

        // step 2 store it.
        dp[i][j] = min(up, left);
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();    // row size
        int n = grid[0].size();     // col size

        // initialization
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(m-1, n-1, grid, dp);
    }
};