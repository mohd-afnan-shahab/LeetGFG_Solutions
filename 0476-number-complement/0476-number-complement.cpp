class Solution {
public:
    int findComplement(int num) {
        
        // Find the bit length of a num
        int bitlength = (int)(log2(num)) + 1; 

        unsigned int mask = (1U << bitlength) - 1;

        return num ^ mask;
    } 
};