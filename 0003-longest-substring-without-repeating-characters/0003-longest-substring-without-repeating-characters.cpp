class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        vector<int> hash(256, -1);

        int l = 0, r = 0;
        int maxLen = 0;

        while(r < n){

            // check in hash, [!= -1 (seen previously..)]
            if(hash[s[r]] != -1){

                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }

            }

            maxLen = max(maxLen, r - l + 1);
            hash[s[r]] = r;
            r++;
        }

        return maxLen;
    }
};