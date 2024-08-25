class Solution {
public:
    
    void BFS(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& grid){ // Pass grid by reference

        visited[row][col] = true;
        queue<pair<int,int>> q;
        q.push({row, col});

        int m = grid.size();
        int n = grid[0].size();

        // define the 4 possible directions(up, down, right, left)
        vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0,1}, {0,-1}};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Traverse in the 4 neighbors 
            for(auto direction : directions){
                int nRow = row + direction.first;
                int nCol = col + direction.second;

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n
                   && grid[nRow][nCol] == '1' && !visited[nRow][nCol]){

                    visited[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int count = 0;
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(!visited[row][col] && grid[row][col] == '1'){
                    count++;
                    BFS(row, col, visited, grid); 
                }
            } 
        }
        return count;
    }  
};
