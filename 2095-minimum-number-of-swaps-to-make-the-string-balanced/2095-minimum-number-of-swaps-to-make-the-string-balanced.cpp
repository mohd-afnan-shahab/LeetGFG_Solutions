class Solution {
public:
    // TIME COMPLEXITY - O(N) and SPACE COMPLEXITY - O(1)
    int minSwaps(string s) {
        int unbalanced = 0;
        
        for(auto& ch : s){

            if(ch == '[') unbalanced++;

            else if(ch == ']' && unbalanced > 0) unbalanced--;

        }

        return (unbalanced + 1) / 2;
    }
};