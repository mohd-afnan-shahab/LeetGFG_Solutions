class Solution {
public:
    void solve(string s, unordered_set<string>& st, int i, int currCount, int& maxCount){
        
        // pruning
        if(currCount + (s.length() - 1) <= maxCount) return;

        if(i >= s.length()){
            maxCount = max(maxCount, currCount);
        }

        for(int j = i; j < s.length(); j++){
            // create substring
            string substring = s.substr(i, j - i + 1); // O(n)

            // if substr not present in set
            if(st.find(substring) == st.end()){
                st.insert(substring);   // DO

                solve(s, st, j + 1, currCount + 1, maxCount);   // EXPLORE

                st.erase(substring);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int currCount = 0;
        int maxCount = 0;
        int i = 0;

        solve(s, st, i, currCount, maxCount);

        return maxCount;
    }
};