class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        int l = 0, r = n - 1;

        auto isVowel = [](char c) {
            return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || 
                   c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        while (l < r) {
            if (isVowel(s[l]) && isVowel(s[r])) {
                swap(s[l], s[r]);
                l++;
                r--;
            } else {
                if (!isVowel(s[l])) l++;
                if (!isVowel(s[r])) r--;
            }
        }

        return s;
    }
};
