    class Solution {
    public:
        void BFS(vector<vector<int>> grid, int row, int col, vector<vector<int>>& visited){
            
            queue<pair<int, int>> q;
            q.push({row, col}); 
            visited[row][col] = 1;      // Mark the starting cell as visited

            int deltaRow[] = {-1, 0, 1, 0};
            int deltaCol[] = {0, 1, 0, -1};

            while(!q.empty()){

                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++){
                int newRow = row + deltaRow[i];
                int newCol = col + deltaCol[i];

                    if(newRow >= 0 && newRow < grid.size() && 
                        newCol >= 0 && newCol < grid[0].size() &&
                        visited[newRow][newCol] == 0 &&
                        grid[newRow][newCol] == 1)
                    {
                        visited[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                } 
            }

        }
        int numEnclaves(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();

            vector<vector<int>> visited(n, vector<int>(m, 0));

            // Traverse at first and last row
            for(int j = 0; j < m; j++){
                if(grid[0][j] == 1 && visited[0][j] == 0){
                    BFS(grid, 0, j, visited);
                }

                if(grid[n - 1][j] == 1 && visited[n - 1][j] == 0){
                    BFS(grid, n - 1, j, visited);
                }
            }

            // Traverse at first and last col
            for(int i = 0; i < n; i++){

                if(grid[i][0] == 1 && visited[i][0] == 0){
                    BFS(grid, i, 0, visited);
                }

                if(grid[i][m - 1] == 1 && visited[i][m - 1] == 0){
                    BFS(grid, i, m - 1, visited);
                }
            }

            int remainingOnes = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j] == 1 && visited[i][j] == 0){
                        remainingOnes++;
                    }
                }
            }

            return remainingOnes;
        }
    };