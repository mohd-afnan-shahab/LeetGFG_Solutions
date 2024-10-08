class Solution {
public:
    // TIME COMPLEXITY - O(N) and SPACE COMPLEXITY - O(1)
    int minSwaps(string s) {
        int unbalanced = 0;
        
        for(char ch : s){

            if(ch == '[') unbalanced += 1;

            else if(ch == ']' && unbalanced > 0) unbalanced -= 1;

        }

        return (unbalanced + 1) / 2;
    }
};