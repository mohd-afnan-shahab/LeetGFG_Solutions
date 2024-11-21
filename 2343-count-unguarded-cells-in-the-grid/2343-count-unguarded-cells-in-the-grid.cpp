class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for(auto& v : guards){
            int i = v[0];
            int j = v[1];

            grid[i][j] = 2; // marking 2. means guard is there
        }

        for(auto& v : walls){
            int i = v[0];
            int j = v[1]; 

            grid[i][j] = 3;     // marking 3. means wall is there
        }

        // helper func to mark guarded cells
        auto markDirection = [&](int i, int j, int deltaI, int deltaJ){
            i = i + deltaI;
            j = j + deltaJ;

            while(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != 2 && grid[i][j] != 3){
                if(grid[i][j] == 0) grid[i][j] = 1;
                
                i = i + deltaI;
                j = j + deltaJ;
            }
        };

        for(auto& guard : guards){
            int i = guard[0];
            int j = guard[1];

            markDirection(i, j, -1, 0);     // up
            markDirection(i, j, 1, 0);      // down
            markDirection(i, j, 0, -1);      // left
            markDirection(i, j, 0, 1);     // right
        }

        // count unguarded cells
        int unguarded = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) unguarded++;
            }
        }

        return unguarded;
    }
};