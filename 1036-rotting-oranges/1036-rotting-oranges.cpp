class Solution {
public:

    int BFS(vector<vector<int>>& grid, vector<vector<int>>& visited, int n, int m){
        // {{row, col}, minute}
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    visited[i][j] = 2;
                    q.push({{i, j}, 0});
                } 
                else{
                    visited[i][j] = 0;
                }
            }
        }

        int time = 0;

        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int minute = q.front().second;
            q.pop();

            time = max(time, minute); 

            for(int i = 0; i < 4; i++){
                int nRow = row + deltaRow[i];
                int nCol = col + deltaCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && 
                    visited[nRow][nCol] != 2 && grid[nRow][nCol] == 1)
                { 
                    q.push({ {nRow, nCol}, minute + 1 });
                    visited[nRow][nCol] = 2;
                }
            }
        }
        return time;

    } 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0)); 

        int mintime = BFS(grid, visited, n, m);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return mintime;
    }
};

