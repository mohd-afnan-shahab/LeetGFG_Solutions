class Solution {
public:

    int helper(int i, int j, vector<vector<int>>& triangle, int m, vector<vector<int>>& dp){

        // base case
        if(i == m-1){
            return triangle[i][j];
        }

        // step 2. Memoization check
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + helper(i+1, j, triangle, m, dp);
        int diagonal = triangle[i][j] + helper(i+1, j+1, triangle, m, dp);

        // step 1. store
        dp[i][j] = min(down, diagonal);
        return dp[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();    // row size

        vector<vector<int>> dp(m, vector<int>(m, -1));

        return helper(0, 0, triangle, m, dp);
    }
};