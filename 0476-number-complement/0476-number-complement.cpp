class Solution {
public:
    int findComplement(int num) {
        
        // Find the bit length of num
        int bitlength = (int)(log2(num)) + 1; 

        // Create a mask with all bits set to 1 for the length of num
        unsigned int mask = (1U << bitlength) - 1;

        // XOR num with mask to flip all bits
        return num ^ mask;
    } 
};
