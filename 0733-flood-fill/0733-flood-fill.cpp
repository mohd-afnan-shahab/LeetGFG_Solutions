class Solution {
public:
    
    void DFS(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans,
             int deltaRow[], int deltaCol[], int initialColor, int color){

        ans[row][col] = color;

        int m = ans.size();
        int n = ans[0].size();

        for(int i = 0; i < 4; i++){
            int nRow = row + deltaRow[i];
            int nCol = col + deltaCol[i];

            if(nRow >= 0 && nRow < m && nCol < n && nCol >= 0 &&
               image[nRow][nCol] == initialColor && ans[nRow][nCol] != color
            ){
                DFS(nRow, nCol, image, ans, deltaRow, deltaCol, initialColor, color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];   
        vector<vector<int>> ans = image;

        // all 4 directions
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        DFS(sr, sc, image, ans, deltaRow, deltaCol, initialColor, color);

        return ans;
    }
};