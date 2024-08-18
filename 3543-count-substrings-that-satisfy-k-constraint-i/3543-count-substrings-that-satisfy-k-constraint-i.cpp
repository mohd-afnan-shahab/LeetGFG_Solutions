class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int l = 0, r = 0;
        int zeroCount = 0, oneCount = 0;
        int totalSubstrings = 0;

        while (r < n) {
            if (s[r] == '1') {
                oneCount++;
            } else {
                zeroCount++;
            }

            while (zeroCount > k && oneCount > k) {
                if (s[l] == '1') {
                    oneCount--;
                } else {
                    zeroCount--;
                }
                l++;
            }

            totalSubstrings += (r - l + 1);
            r++;
        }

        return totalSubstrings;
    }
};
