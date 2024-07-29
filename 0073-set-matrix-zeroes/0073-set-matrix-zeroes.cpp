class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> dummyCols(cols, 0);
        vector<int> dummyRows(rows, 0);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    dummyCols[j] = 1;
                    dummyRows[i] = 1;
                }
            }
        }

        // again iterate and change every element to 0 if dummy is 1

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(dummyCols[j] == 1 || dummyRows[i] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
     
    }
};