class Solution {
public:
    // TIME COMPLEXITY - O(N) and SPACE COMPLEXITY - O(1)
    int minLength(string s) {
        int n = s.length();

        int l = 0, r = 1;
        while(r < n){
            if(l < 0){
                l++;
                s[l] = s[r];
            }
            else if(s[l] == 'A' && s[r] == 'B' || s[l] == 'C' && s[r] == 'D'){
                l--;
            }
            else{
                l++;
                s[l] = s[r];
            }

            r++;
        }

        return l + 1;
    }
};
