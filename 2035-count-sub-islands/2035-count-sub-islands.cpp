class Solution {
public:
    bool DFS(vector<vector<int>>& grid1, int row, int col,vector<vector<int>>& visited, vector<vector<int>>& grid2){
        visited[row][col] = 1;

        bool isSubIsland = true;

        // corresponding cell of grid2 in grid1 is 0
        if(grid1[row][col] == 0){
            isSubIsland = false;
        }
        
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];

            if(newRow >= 0 && newRow < grid2.size() && newCol >= 0 &&
                newCol < grid2[0].size() && visited[newRow][newCol] == 0
                && grid2[newRow][newCol] == 1) 
            {
                // if any of the island is not a sub island
                if(!DFS(grid1, newRow, newCol, visited, grid2)){
                    isSubIsland = false;
                }
            }
        }
        return isSubIsland;     
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int SubIslandCount = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid2[i][j] == 1 && !visited[i][j]){
                    if(DFS(grid1, i, j, visited, grid2)){
                        SubIslandCount++;
                    } 
                }
            }
        }
        return SubIslandCount;
    }
};