class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // helper func
        auto minFlipsForPalindrome = [](const vector<int>& line){
            int flips = 0;
            int n = line.size();

            for(int i = 0; i < n/2; i++){
                if(line[i] != line[n - i - 1]){
                    flips++;
                }
            }
            return flips;
        };

        // min flips to make all rows palindrome
        int totalRowFlips = 0;
        for(const auto& row : grid){
            totalRowFlips += minFlipsForPalindrome(row);
        }

        // similarly for cols 
        int totalColFlips = 0;
        for (int col = 0; col < cols; ++col) {
            vector<int> column_values(rows);
            for (int row = 0; row < rows; ++row) {
                column_values[row] = grid[row][col];
            }
            totalColFlips += minFlipsForPalindrome(column_values);
        }

        // Return the minimum number of flips needed
        return min(totalRowFlips, totalColFlips);
    }
};