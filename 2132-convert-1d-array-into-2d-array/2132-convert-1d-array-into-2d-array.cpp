class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        if(m * n != original.size()){
            return {};          // return an empty 2D array
        }


        vector<vector<int>> array2D(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                array2D[i][j] = original[i * n + j];
            }
        }
        return array2D;
    }
};