class Solution {
public:

    void DFS(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& board){
        visited[row][col] = 1;

        int n = board.size();
        int m = board[0].size();

        // Check for all 4 directions
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];

            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !visited[newRow][newCol] && board[newRow][newCol] == 'O')
            {
                DFS(newRow, newCol, visited, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Traverse in all 4 boundaries

        // Traverse the first and last row
        for(int j = 0; j < m; j++){

            if(!visited[0][j] && board[0][j] == 'O'){
                DFS(0, j, visited, board);
            }

            if(!visited[n-1][j] && board[n-1][j] == 'O'){
                DFS(n-1, j, visited, board);
            }
        }

        // Traverse the first and last col
        for(int i = 0; i < n; i++){

            if(!visited[i][0] && board[i][0] == 'O'){
                DFS(i, 0, visited, board);
            }

            if(!visited[i][m - 1] && board[i][m - 1] == 'O'){
                DFS(i, m - 1, visited, board);
            }
        }

        // Replace all remaining 'O's with 'X's
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};