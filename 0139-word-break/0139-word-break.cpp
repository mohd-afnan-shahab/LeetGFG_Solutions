class Solution {
public:

    unordered_set<string> st;

    bool solve(int n, int idx, string& s, vector<int>& dp){

        // base case
        if(idx == n) return true;

        if(st.find(s) != st.end()) return true;

        // memoization check
        if(dp[idx] != -1) return dp[idx];

        for(int len = 1; len <= n; len++){
            string temp = s.substr(idx, len);

            if(st.find(temp) != st.end() && solve(n, idx + len, s, dp)){
                dp[idx] = 1;
                return true; 
            }
        }

        dp[idx] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        for(string& word : wordDict){
            st.insert(word);
        }

        vector<int> dp(n + 1, -1);

        return solve(n, 0, s, dp);
    }
};