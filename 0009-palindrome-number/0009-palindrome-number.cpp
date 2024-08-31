class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) return false;

        int reversed = 0;
        int dup = x;    // store original x in dup

        while(x != 0){ 
            int lastDigit = x % 10;

            if(reversed < INT_MIN/10 || reversed > INT_MAX/10) return 0;

            reversed = (reversed * 10) + lastDigit;
            x = x / 10;
        } 

        return (dup == reversed);
    }
};