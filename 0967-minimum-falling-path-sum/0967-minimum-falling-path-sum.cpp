class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m));

        // base case
        for(int j = 0; j < m; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){

                int up = matrix[i][j] + dp[i-1][j];

                int leftDiagonal = 1e9;
                if(j > 0){
                    leftDiagonal = matrix[i][j] + dp[i-1][j-1];
                }

                int rightDiagonal = 1e9;
                if(j < m-1){
                    rightDiagonal = matrix[i][j] + dp[i-1][j+1];
                }

                dp[i][j] = min({up, leftDiagonal, rightDiagonal});
            }
        }

        int mini = 1e9;
        for(int j = 0; j < m; j++){
            mini = min(mini, dp[n-1][j]);
        }

        return mini;
    }
};