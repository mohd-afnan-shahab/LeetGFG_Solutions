class Solution {
public:
    int findComplement(int num) {
        
        // Find the bit length of the num
        int bitLength = floor(log2(num)) + 1;

        for(int i = 0; i < bitLength; i++){
            num = num ^ (1 << i);
        }
        return num;
    }
};