class Solution {
public:
    
    void DFS(int row, int col, vector<vector<int>>& image, vector<vector<int>>& filledImage,
             int deltaRow[], int deltaCol[], int initialColor, int color){
        
        // Update the current cell with the new color
        filledImage[row][col] = color;

        int m = filledImage.size();
        int n = filledImage[0].size();

        for(int i = 0; i < 4; i++){
            int nRow = row + deltaRow[i];
            int nCol = col + deltaCol[i];

            if(nRow >= 0 && nRow < m && nCol < n && nCol >= 0 &&
               image[nRow][nCol] == initialColor && filledImage[nRow][nCol] != color
            ){
                DFS(nRow, nCol, image, filledImage, deltaRow, deltaCol, initialColor, color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];   

        vector<vector<int>> filledImage = image;    // Copy of the original image to modify

        // Possible moves: up, right, down, left
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        // Start the flood fill process from the starting pixel
        DFS(sr, sc, image, filledImage, deltaRow, deltaCol, initialColor, color);

        return filledImage;
    }
};