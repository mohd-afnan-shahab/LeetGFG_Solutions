class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        // XOR operation to find differing bits b/w start and goal
        int ans = start ^ goal;
        int minFlips = 0;

        // count the no of set bits (1's)
        while(ans > 0){
            ans = ans & (ans - 1);  // removes the lowest set bit in ans
            minFlips++;
        }

        return minFlips;
    }
};