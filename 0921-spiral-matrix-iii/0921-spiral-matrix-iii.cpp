class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        // EAST, SOUTH, WEST, NORTH
        vector<vector<int>> directions = { {0,1}, {1,0}, {0,-1}, {-1,0} }; 

        // and step++ when move towards east and west
        int step = 0;
        int dir = 0;  // 0th index direction (initially at east) 

        vector<vector<int>> result; 
        result.push_back({rStart, cStart}); 

        while(result.size() < rows * cols){

            // direction is east or west
            if( dir == 0 || dir == 2){
                step++;
            }
            for(int count = 0; count < step; count++){
                rStart += directions[dir][0];   // x coordinate
                cStart += directions[dir][1];   // y coordinate
                
                // if out of bound..
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols){
                    result.push_back({rStart, cStart});
                }
            }

            dir = (dir + 1) % directions.size(); 
        }
        return result;
    }
};