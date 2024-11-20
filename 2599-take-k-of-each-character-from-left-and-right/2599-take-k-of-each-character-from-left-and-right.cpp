class Solution {
public:

    // sliding window
    int takeCharacters(string s, int k) {
        int n = s.length();

        int countA=0, countB=0, countC=0;

        for(auto& ch : s){
            if(ch == 'a') countA++;
            else if(ch == 'b') countB++;
            else countC++;
        }

        if(countA < k || countB < k || countC < k) return -1;

        // sliding window template
        int l = 0, r = 0;

        int windowLength = 0;
        while(r < n){
            if(s[r] == 'a') countA--;
            else if(s[r] == 'b') countB--;
            else countC--;

            // shrink the window
            while(l <= r && (countA < k || countB < k || countC < k)){
                
                if(s[l] == 'a') countA++;
                else if(s[l] == 'b') countB++;
                else countC++;

                l++;
            }

            windowLength = max(windowLength, r-l+1);
            r++;
        }

        return n - windowLength;

    }
};