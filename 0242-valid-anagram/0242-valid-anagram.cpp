class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        vector<int> freq(26, 0);

        int l = 0, r = 0;
        while(l < s.length() && t.length()){
            freq[s[l] - 'a']++;

            freq[t[r] - 'a']--;

            l++;
            r++;
        }

        for(int i = 0; i < freq.size(); i++){
            if(freq[i] != 0) return false;
        }

        return true;
    }
};