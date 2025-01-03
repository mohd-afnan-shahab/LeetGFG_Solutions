class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();        // row size
        int n = grid[0].size();     // col size

        vector<vector<int>> dp(m, vector<int>(n));

        // base case starting cell
        if(grid[0][0] == 1) return 0;
        dp[0][0] = 1;

        // iterate in grid grom m-1, n-1
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == 1) dp[i][j] = 0;   // dead end

                else if(i == 0 && j == 0) dp[i][j] = 1;

                else{
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];

                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m-1][n-1];
    }
};