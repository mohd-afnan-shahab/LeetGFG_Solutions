class Solution {
public:
    
    // Tabulation method
    int uniquePaths(int m, int n) {
        
        // initialize dp with 0
        vector<vector<int>> dp(m, vector<int>(n, 0)); 

        // filling the base case
        dp[0][0] = 1;

        // expressing all stated (i, j) in for loops
        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){

                if(i == 0 && j == 0) continue;

                else {
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