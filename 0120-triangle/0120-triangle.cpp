class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();        // row size

        // initialize 2D dp of size m*m
        vector<vector<int>> dp(m, vector<int>(m));

        // base case
        for(int j = 0; j < m; j++){
            dp[m-1][j] = triangle[m-1][j];
        }

        // iterate from m-2 to 0
        for(int i = m-2; i >= 0; i--){
            for(int k = i; k >= 0; k--){

                int down = triangle[i][k] + dp[i+1][k];
                int diagonal = triangle[i][k] + dp[i+1][k+1];

                dp[i][k] = min(down, diagonal);
            }
        }

        return dp[0][0];
    }
};