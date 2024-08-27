class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();     // number of rows in matrix
        int m = mat[0].size();  // number of cols in matrix

        queue<pair<int, int>> q;
        vector<vector<int>> result(n, vector<int>(m, -1));      // matrix to store distances

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    q.push({i, j}); 
                }
            }
        }   

        // Arrays to move in the four possible directions
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // move to 4 directions
            for(int i = 0; i < 4; i++){
                int nRow = row + deltaRow[i];
                int nCol = col + deltaCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    result[nRow][nCol] == -1)
                {
                    result[nRow][nCol] = result[row][col] + 1;
                    q.push({nRow, nCol});
                }
            }
        }
        return result;
    }
};