class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();      // row size
        int n = matrix[0].size();   // col size

        // Initialize the result matrix with transposed dimensions (n x m)
        vector<vector<int>> result(n, vector<int>(m)); 

        // Transpose the matrix
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                result[j][i] = matrix[i][j];
            }
        }

        // Return the transposed matrix
        return result;
    }
};
